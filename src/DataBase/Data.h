//
// Created by alfred on 9/18/17.
//

#ifndef GESTORBD_DATA_H
#define GESTORBD_DATA_H

#include <vector>
#include <string>

class Data {
public:
    explicit Data(const std::vector<std::string> &DataTypes, const std::vector<std::string> &Data1, const int &Dim);

    std::vector<std::string> getDataType();

    std::vector<std::string> getData();

    int getDimensions();

private:
    std::vector<std::string> DataType;
    std::vector<std::string> CData;
    int Dimensions;
};


#endif //GESTORBD_DATA_H
