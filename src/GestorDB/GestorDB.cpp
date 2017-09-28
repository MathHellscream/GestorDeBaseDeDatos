//
// Created by alfred on 9/18/17.
//

#include <climits>
#include <zconf.h>
#include <sys/stat.h>
#include <iostream>
#include "GestorDB.h"

GestorDB::GestorDB() {
    db = nullptr;
}

void GestorDB::loadDB(std::string dbName) {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    auto fullPath = std::string(result, static_cast<unsigned long>((count > 0) ? count : 0));
    struct stat st{0};
    while (fullPath[fullPath.size() - 1] != '/')fullPath.pop_back();
    fullPath.pop_back();
    auto completePath = fullPath + '/' + dbName;
    if (stat(completePath.c_str(), &st) == -1) std::cerr << "Base de Datos noe existe" << std::endl;
    else db = std::make_shared<DataBase>(dbName, fullPath);
}

void GestorDB::createDB(std::string dbName) {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    auto fullPath = std::string(result, static_cast<unsigned long>((count > 0) ? count : 0));
    struct stat st{0};
    while (fullPath[fullPath.size() - 1] != '/')fullPath.pop_back();
    fullPath.pop_back();
    auto completePath = fullPath + "/" + dbName;
    std::cout << "fullPath " << fullPath << std::endl;
    std::cout << completePath << std::endl;
    if (stat(completePath.c_str(), &st) != -1) std::cerr << "Base de Datos existe" << std::endl;
    else db = std::make_unique<DataBase>(dbName, fullPath);
}

void GestorDB::deleteDB(std::string dbName) {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    auto fullPath = std::string(result, static_cast<unsigned long>((count > 0) ? count : 0));
    struct stat st{0};
    while (fullPath[fullPath.size() - 1] != '/')fullPath.pop_back();
    fullPath.pop_back();
    auto completePath = fullPath + "/" + dbName;
    std::cout << "fullPath " << fullPath << std::endl;
    std::cout << completePath << std::endl;
    std::string rmpath = "rm -rf " + completePath;
    if (stat(completePath.c_str(), &st) == -1) std::cerr << "Base de Datos no existe" << std::endl;
    else system(rmpath.c_str());
}

void GestorDB::createTable(std::string tableName, const std::vector<std::string> &vector1) {
    std::cout << "Creando tabla" << std::endl;
    if (!db) {
        std::cerr << "No hay base de datos cargada" << std::endl;
        return;
    }
    db->createTable(tableName, vector1);
}

void GestorDB::deleteTable(std::string tableName) {
    std::cout << "Borrando tabla" << std::endl;
    if (!db) {
        std::cerr << "No hay base de datos cargada" << std::endl;
        return;
    }
    db->deleteTable(tableName);
}

void GestorDB::insertToTable(std::string tableName, const std::vector<std::string> &vector1) {
    std::cout << "insertando" << std::endl;
    if (!db) {
        std::cerr << "No hay base de datos cargada" << std::endl;
        return;
    }
    db->insertDataToTable(tableName, vector1);
}

