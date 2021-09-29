#ifndef SESSION_H
#define SESSION_H

#include "../../domains/domains.h"

///
/// This class stores all the information of the session of the play.
/// Types of information:
/// - Identification code
/// - Date of the session
/// - Time of the session
///

class Session
{
private:
    IdCode _id;
    Date _date;
    Time _time;

public:
    ///
    /// Calls all the methods set for the objects of the attributes of class Session, if its objects is already created.
    /// @param id
    /// @param date
    /// @param time
    ///

    Session(const IdCode &id, const Date &date, const Time &time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    ///
    /// Calls all the methods set for the objects of the attributes of class Session.
    /// @param id
    /// @param date
    /// @param time
    ///

    Session(const std::string &id, const std::string &date, const std::string &time)
    {
        setId(id);
        setDate(date);
        setTime(time);
    }

    ///
    /// Creates an instance of the classSession.
    ///

    Session() {}

    ///
    /// Stores an already created object of class IdCode.
    /// @param id
    ///

    void setId(const IdCode &id)
    {
        _id = id;
    }

    ///
    /// Creates and stores the object of the class IdCode.
    /// @param id
    ///

    void setId(const std::string &id)
    {
        _id = IdCode(id);
    }

    ///
    /// Returns the stored object of the class IdCode.
    /// @return _id
    ///

    IdCode getId() const
    {
        return _id;
    }

    ///
    /// Stores an already created object of class Date.
    /// @param date
    ///

    void setDate(const Date &date)
    {
        _date = date;
    }

    ///
    /// Creates and stores the object of the class Date.
    /// @param date
    ///

    void setDate(const std::string &date)
    {
        _date = Date(date);
    }

    ///
    /// Returns the stored object of the class Date.
    /// @return _date
    ///

    Date getDate() const
    {
        return _date;
    }

    ///
    /// Stores an already created object of class Time.
    /// @param time
    ///

    void setTime(const Time &time)
    {
        _time = time;
    }

    ///
    /// Creates and stores the object of the class Time.
    /// @param time
    ///

    void setTime(const std::string &time)
    {
        _time = Time(time);
    }

    ///
    /// Returns the stored object of the class Time.
    /// @return _time
    ///

    Time getTime() const
    {
        return _time;
    }
};

#endif