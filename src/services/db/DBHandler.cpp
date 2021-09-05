#include "DBHandler.h"

DBHandler *DBHandler::_instance = nullptr;

int DBHandler::_formatResult(void *_result, int nbEntries, char **columnEntries, char **columnNames)
{
    SQLResult *result = static_cast<SQLResult *>(_result);

    std::map<std::string, std::string> row;

    for (int i = 0; i < nbEntries; i++)
    {
        row[columnNames[i]] = columnEntries[i];
    }

    result->rows.push_back(row);

    return 0;
}

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

SQLResult DBHandler::execute(const std::string &query)
{
    SQLResult result;

    _open();

    result.status = sqlite3_exec(_db, query.c_str(), _formatResult, &result, &result.errorMessage);

    _close();

    _log.open(_logFilename, std::fstream::out | std::fstream::app);

    _log << "[Q] " << query << std::endl;

    if (result.status != SQLResult::SUCCESS)
    {
        _log << "[E] " << result.errorMessage << std::endl;
    }
    _log.close();

    return result;
}

SQLResult DBHandler::execute(const std::stringstream &query)
{
    return execute(query.str());
}