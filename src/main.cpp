#include "presentation/PageHandler.h"
#include "services/services.h"
#include <iostream>

int main(void)
{
    ServicesInterface *services = new ServicesInterface(new ParticipantHandler, new PlayHandler, new RoomHandler, new SessionHandler);
    PageHandler pageHandler(services);

    pageHandler.handle();

    return 0;
}
