#include <iostream>
#include "GestorDB/GestorDB.h"

int main() {
    GestorDB gestor;
    gestor.loadDB("mytestdb");
    std::vector<std::string> vec1 = {"id","name","age"};
    gestor.insertToTable("apulo",vec1);
    return 0;
}