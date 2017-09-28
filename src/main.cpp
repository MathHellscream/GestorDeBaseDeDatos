#include <iostream>
#include "GestorDB/GestorDB.h"

int main() {
    GestorDB gestor;
    gestor.loadDB("mytestdb");
    std::vector<std::string> dt{"int", "varchar", "int"};
    gestor.createTable("datos_backup", dt);
    return 0;
}