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
    Session(IdCode id, Date date, Time time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    Session(std::string id, std::string date, std::string time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    Session() {}

    void setId(IdCode id)
    {
        _id = id;
    }

    void setId(std::string id)
    {
        _id = IdCode(id);
    }

    IdCode getId()
    {
        return _id;
    }

    void setDate(Date date)
    {
        _date = date;
    }

    void setDate(std::string date)
    {
        _date = Date(date);
    }

    Date getDate()
    {
        return _date;
    }

    void setTime(Time time)
    {
        _time = time;
    }

    void setTime(std::string time)
    {
        _time = Time(time);
    }

    Time getTime()
    {
        return _time;
    }
};

#endif