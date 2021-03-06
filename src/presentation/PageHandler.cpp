#include "PageHandler.h"
#include "Pages.h"

void PageHandler::handle()
{
    initscr();
    keypad(stdscr, true);

    Page *page = new InitPage();

    do
    {
        _loadScreenDimensions();
        clearScreen();
        try
        {
            Page *newPage = page->show(this);
            delete page;

            page = newPage;
        }
        catch (const std::exception &)
        {
            delete page;

            page = new ErrorPage();

            Page *newPage = page->show(this);
            delete page;

            page = newPage;
        }
    } while (page);
}

void PageHandler::print(const std::string &msg)
{
    _currentX = (_columns - msg.length()) / 2;
    _currentY = (_lines / 2 + _currentLine - 10) < 0 ? _lines / 2 + _currentLine : _lines / 2 + _currentLine - 10;

    mvprintw(_currentY, _currentX, msg.c_str());
    _currentLine++;
}

void PageHandler::_loadScreenDimensions()
{
    getmaxyx(stdscr, _lines, _columns);
}

void PageHandler::clearScreen()
{
    clear();
    _currentLine = 0;
}

void PageHandler::clearLines(int nbOfLines)
{
    for (int i = 0; i < nbOfLines; i++)
    {
        move(_currentY, 0);
        clrtoeol();
        _currentLine--;
        _currentY = _lines / 2 + _currentLine - 5;
    }
}

std::string PageHandler::readInput()
{
    getnstr(readBuffer, READ_BUFFER_SIZE);

    return std::string(readBuffer);
}

unsigned int PageHandler::renderMenu(const std::vector<std::string> &options)
{
    unsigned int currentOption = 0;
    int currentLine = _currentLine;

    std::deque<std::string> _options{options.front(), options.back()};

    _options.push_back(_options[0]);
    _options.pop_front();

    noecho();
    curs_set(0);

    while (true)
    {
        _currentLine = currentLine;

        for (unsigned int i = 0; i < options.size(); i++)
        {
            if (i == currentOption)
            {
                wattron(stdscr, A_REVERSE);
            }

            std::stringstream ss;

            ss << "[" << (i + 1) % options.size() << "]" << std::setw(32) << options[i];

            print(ss.str());
            wattroff(stdscr, A_REVERSE);
        }

        int option = getch();

        switch (option)
        {
        case KEY_A2:
        case KEY_UP:
        {
            currentOption = currentOption == 0 ? options.size() - 1 : currentOption - 1;
            break;
        }
        case KEY_C2:
        case KEY_DOWN:
        {
            currentOption = currentOption == options.size() - 1 ? 0 : currentOption + 1;
            break;
        }
        case '\r':
        case '\n':
        case KEY_ENTER:
        {
            echo();
            curs_set(1);
            return currentOption == options.size() - 1 ? 0 : currentOption + 1;
        }
        default:
        {
            if (isdigit(option))
            {
                echo();
                curs_set(1);
                return option - '0';
            }
            break;
        }
        }
    }
}