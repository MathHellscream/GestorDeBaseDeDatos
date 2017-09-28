//
// Created by alfred on 9/18/17.
//

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Table.h"


Table::Table(const std::string &nameOfTable, std::string &dbPath, const std::vector<std::string> &dataTypes) {
    struct stat st{0};
    std::string completePath = dbPath + '/' + nameOfTable;
    std::cout << "tabla en: " << completePath << std::endl;
    if (stat(completePath.c_str(), &st) == -1) {
        mkdir(completePath.c_str(), 0700);
        std::ofstream tableData(completePath + "/" + nameOfTable + ".trd");
        tableData.close();
        std::ofstream metaData(completePath + "/" + nameOfTable + ".trm",
                               std::ios_base::out | std::ios_base::binary);
        char buffer[40 * (dataTypes.size() + 2)];
        char value[40];
        strncpy(value, nameOfTable.c_str(), 39);
        value[39] = '\0';
        for (int i = 0; i < 40; ++i) {
            buffer[i] = value[i];
        }
        std::stringstream ss;
        ss << dataTypes.size();
        std::string rows = ss.str();
        strncpy(value, rows.c_str(), 39);
        value[39] = '\0';
        for (int i = 0; i < 40; ++i) {
            buffer[40 + i] = value[i];
        }

        for (int i = 0; i < dataTypes.size(); ++i) {
            strncpy(value, dataTypes[i].c_str(), 39);
            value[39] = '\0';
            for (int j = 0; j < 40; ++j) {
                buffer[40 * (i + 2) + j] = value[j];
            }
        }
        metaData.write(buffer, sizeof(buffer));
        metaData.close();

    }
    pathOfTable = dbPath + "/" + nameOfTable;
    this->nameOfTable = nameOfTable;
    DataType = dataTypes;
    if (DataType.empty()) {
    }
}

void Table::addRow(const std::vector<std::string> &values) {
    std::ofstream table(pathOfTable + "/" + nameOfTable + ".trd",
                        std::ios_base::app | std::ios_base::out | std::ios_base::binary);
    char buffer[40 * values.size()];
    char value[40];
    for (int i = 0; i < values.size(); ++i) {
        strncpy(value, values[i].c_str(), 39);
        value[39] = '\0';
        for (int j = 0; j < 40; ++j) {
            buffer[40 * i + j] = value[j];
        }
    }
    table.write(buffer, sizeof(buffer));
    table.close();
}

void Table::deleteRow(const std::vector<std::string> &cols, std::vector<std::string> &values) {

}

std::string Table::lookForRow(const std::vector<std::string> &cols, const std::vector<std::string> &values) {
    return std::__cxx11::string();
}

void Table::updateData(const std::vector<std::string> &ColsToUpdate, const std::vector<std::string> &newValue,
                       const std::vector<std::string> &conditions) {

}

void Table::loadPage(int &Linefrom, int &LineTo) {

}


