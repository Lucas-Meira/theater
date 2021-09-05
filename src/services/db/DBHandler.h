#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#include "sqlite3.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

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
    bool _formatResult(void *_result, int nbEntries, char **columnEntries, char **columnNames);

    DBHandler()
    {
        std::ifstream file("src/services/db/sql/participant.sql");

        std::stringstream query;

        query << file.rdbuf();

        file.close();

        execute(query);
    };

public:
    DBHandler(DBHandler &other) = delete;
    void operator=(const DBHandler &other) = delete;

    static DBHandler *getInstance();

    bool execute(const std::string &query);
    bool execute(const std::stringstream &query);
};

#endif