#include "../Pages.h"
#include "../../domains/domains.h"
#include "../../entities/entities.h"

Page *ListItemsPage::show(PageHandler *handler)
{
    handler->print("Page not yet implemented. Press any key to continue...");

    getch();

    return new InitPage;
};
