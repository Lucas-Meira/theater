#ifndef PAGE_HANDLER_H
#define PAGE_HANDLER_H

#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iomanip>
#include <curses.h>

#include "../services/services.h"

class PageHandler
{
private:
    const static int READ_BUFFER_SIZE = 128;
    char readBuffer[READ_BUFFER_SIZE];
    unsigned int _currentLine = 0;
    unsigned int _currentX = 0;
    unsigned int _currentY = 0;
    unsigned int _lines;
    unsigned int _columns;
    ServicesInterface *_services;

    void _loadScreenDimensions();

public:
    PageHandler(ServicesInterface *services) : _services(services)
    {
    }

    void handle();
    void clearScreen();
    void clearLines(int nbOfLines);
    void print(const std::string &message);
    unsigned int renderMenu(const std::vector<std::string> &options);
    std::string readInput();

    ServicesInterface *getServices() { return _services; }
};

#endif