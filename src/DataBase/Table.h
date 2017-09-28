//
// Created by alfred on 9/18/17.
//

#ifndef GESTORBD_TABLE_H
#define GESTORBD_TABLE_H

#include <vector>
#include <string>
#include "Data.h"

class Table {
public:
    explicit Table(const std::string &nameOfTable, std::string &dbPath, const std::vector<std::string> &dataTypes = {});

    void addRow(const std::vector<std::string> &values);

    void deleteRow(const std::vector<std::string> &cols, std::vector<std::string> &values);

    std::string lookForRow(const std::vector<std::string> &cols, const std::vector<std::string> &values);

    void updateData(const std::vector<std::string> &ColsToUpdate, const std::vector<std::string> &newValue,
                    const std::vector<std::string> &conditions);

private:
    std::vector<std::string> DataType;
    std::vector<Data> Page;
    int MaxSizeOfPage;
    std::string nameOfTable;
    std::string pathOfTable;

    void loadPage(int &Linefrom, int &LineTo);

};


#endif //GESTORBD_TABLE_H
