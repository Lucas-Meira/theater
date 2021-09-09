#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#include "sqlite3.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

struct SQLResult
{
public:
    static const int SUCCESS = SQLITE_OK;
    static const int FAILURE = SQLITE_ERROR;

    int status;
    char *errorMessage;

    std::vector<std::map<std::string, std::string>> rows;
};

class DBHandler
{
private:
    static constexpr char _filename[] = "theater.db";
    static constexpr char _logFilename[] = "theater.log";
    std::ofstream _log;

    sqlite3 *_db;
    static DBHandler *_instance;

    bool _open();
    bool _close();
    static int _formatResult(void *_result, int nbEntries, char **columnEntries, char **columnNames);

    DBHandler()
    {
        const std::vector<std::string> pathsToSqlFiles{"src/services/db/sql/Type.sql", "src/services/db/sql/Play.sql", "src/services/db/sql/Participant.sql", "src/services/db/sql/Room.sql", "src/services/db/sql/Session.sql"};

        for (unsigned int i = 0; i < pathsToSqlFiles.size(); i++)
        {

            std::ifstream file(pathsToSqlFiles[i]);
            std::stringstream query;
            query << file.rdbuf();
            file.close();
            execute(query);
        }
    };

public:
    DBHandler(DBHandler &other) = delete;
    void operator=(const DBHandler &other) = delete;

    static DBHandler *getInstance();

    SQLResult execute(const std::string &query);
    SQLResult execute(const std::stringstream &query);
};

#endif