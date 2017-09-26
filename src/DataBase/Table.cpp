//
// Created by alfred on 9/18/17.
//

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include "Table.h"


Table::Table(const std::string &nameOfTable, std::string &dbPath, const std::vector<std::string> &dataTypes) {
    struct stat st{0};
    std::string completePath = dbPath + '/' + nameOfTable;
    std::cout << "tabla en: " << completePath << std::endl;
    if(stat(completePath.c_str(),&st)==-1){
        mkdir(completePath.c_str(),0700);
        std::ofstream tableData(completePath+"/"+nameOfTable+".trd");
        tableData.close();
        std::ofstream metaData(completePath+"/"+nameOfTable+".trm");
        metaData.close();
    }
    pathOfTable = dbPath + "/" + nameOfTable;
    this->nameOfTable = nameOfTable;
    DataType = dataTypes;
}

void Table::addRow(const std::vector<std::string> &values) {
    std::ofstream table(pathOfTable + "/" +nameOfTable + ".trd", std::ios_base::app | std::ios_base::out);
    std::cout << "rowtoTable " << pathOfTable + "/" + nameOfTable + ".trd";
    for (int i = 0; i < values.size(); ++i) {
        table << values[i];
        if(i!=values.size()-1)table << ",";
    }
    table << '\n';
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


