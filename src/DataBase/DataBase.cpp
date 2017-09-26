//
// Created by alfred on 9/18/17.
//

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include "DataBase.h"

DataBase::DataBase(const std::string &dbName, const std::string &path) {
    struct stat st{0};
    std::string completePath = path + '/'+dbName;
    if(stat(completePath.c_str(),&st)==-1){
        std::cout << "no existe " << completePath << std::endl;
        mkdir(completePath.c_str(),0700);
    }
    this->dbName = dbName;
    this->dbPath = path + '/' +dbName;
}

void DataBase::createTable(const std::string &tableName, const std::vector<std::string> &dataTypes) {
    auto completePath = dbPath + '/' + tableName;
    std::cout << "ez: " << completePath << std::endl;
    struct stat st{0};
    if(stat(completePath.c_str(),&st)==-1){
        Table table(tableName,dbPath,dataTypes);
    }
    else std::cerr << "Table exists" << std::endl;
}

void DataBase::deleteTable(const std::string &tableName) {
    auto completePath = dbPath + '/' + tableName;
    struct stat st{0};
    std::string delcompletepath = "rm -rf " + completePath;
    if(stat(completePath.c_str(),&st)==-1) std::cerr << "Tabla no existe" << std::endl;
    else system(delcompletepath.c_str());
}

void DataBase::insertDataToTable(const std::string &tableName, const std::vector<std::string> &data) {
    Table table(tableName,dbPath);
    table.addRow(data);
}

void DataBase::deleteDataToTable() {

}

