#include "../Pages.h"
#include "../../domains/domains.h"
#include "../../entities/entities.h"

Page *ListItemsPage::show(PageHandler *handler)
{
    handler->print("OK");

    getch();
};
