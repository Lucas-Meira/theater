#ifndef SESSION_H
#define SESSION_H

#include "../../domains/domains.h"

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;

public:
    void setId(IdCode id)
    {
        _id = id;
    }

    IdCode getId()
    {
        return _id;
    }

    void setDate(Date date)
    {
        _date = date;
    }

    Date getDate()
    {
        return _date;
    }

    void setTime(Time time)
    {
        _time = time;
    }

    Time getTime()
    {
        return _time;
    }
};

#endif