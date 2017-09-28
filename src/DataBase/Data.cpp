//
// Created by alfred on 9/18/17.
//

#include <iostream>
#include "Data.h"

Data::Data(const std::vector<std::string> &DataTypes, const std::vector<std::string> &Data1, const int &Dim) {
    if (DataTypes.size() != Dim) {
        std::cerr << "Wrong number of Dimensions of DataTypes" << std::endl;
        exit(100);
    } else if (Data1.size() != Dim) {
        std::cerr << "Wrong number of Dimensions of Data" << std::endl;
        exit(100);
    } else {
        DataType = DataTypes;
        CData = Data1;
        Dimensions = Dim;
    }
}

std::vector<std::string> Data::getDataType() {
    return DataType;
}

std::vector<std::string> Data::getData() {
    return CData;
}

int Data::getDimensions() {
    return Dimensions;
}


