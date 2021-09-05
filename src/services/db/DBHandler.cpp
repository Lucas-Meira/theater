#include "DBHandler.h"

DBHandler *DBHandler::_instance = nullptr;

DBHandler *DBHandler::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new DBHandler();
    }

    return _instance;
}

bool DBHandler::_open()
{
    return sqlite3_open_v2(_filename, &_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) == SQLITE_OK;
}

bool DBHandler::_close()
{
    return sqlite3_close(_db) == SQLITE_OK;
}

bool DBHandler::execute(const std::string &query)
{
    _open();
    char *buffer;
    sqlite3_exec(_db, query.c_str(), NULL, NULL, &buffer);

    _close();

    _log.open(_logFilename, std::fstream::out | std::fstream::app);

    _log << "[Q] " << query << std::endl;

    if (buffer)
    {
        _log << "[E] " << buffer << std::endl;
    }
    _log.close();
}

bool DBHandler::execute(const std::stringstream &query)
{
    return execute(query.str());
}