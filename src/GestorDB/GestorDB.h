//
// Created by alfred on 9/18/17.
//

#ifndef GESTORBD_GESTORDB_H
#define GESTORBD_GESTORDB_H


#include "../DataBase/DataBase.h"
#include <memory>

class GestorDB {
public:
    GestorDB();
    void loadDB(std::string dbName);
    void createDB(std::string dbName);
    void deleteDB(std::string dbName);
    void createTable(std::string tableName, const std::vector<std::string> &vector1);
    void deleteTable(std::string tableName);
    void insertToTable(std::string tableName, const std::vector<std::string> &vector1);
private:
    std::shared_ptr<DataBase> db;
    std::string path;
    std::string dbName;
};


#endif //GESTORBD_GESTORDB_H
