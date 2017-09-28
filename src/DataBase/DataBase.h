//
// Created by alfred on 9/18/17.
//

#ifndef GESTORBD_DATABASE_H
#define GESTORBD_DATABASE_H

#include "Table.h"

class DataBase {
public:
    DataBase(const std::string &dbName, const std::string &path);

    void createTable(const std::string &tableName, const std::vector<std::string> &dataTypes);

    void deleteTable(const std::string &tableName);

    void insertDataToTable(const std::string &tableName, const std::vector<std::string> &data);

    void deleteDataToTable();

private:
    std::string dbName;
    std::string dbPath;
};


#endif //GESTORBD_DATABASE_H
