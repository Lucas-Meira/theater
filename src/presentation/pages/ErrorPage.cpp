#include "../Pages.h"

Page *ErrorPage::show(PageHandler *handler)
{
    handler->print("An error occurred!");
    handler->print("");
    handler->print("Press any key to continue...");

    getch();

    return new InitPage;
}
