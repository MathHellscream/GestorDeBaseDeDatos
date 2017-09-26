cmake_minimum_required(VERSION 3.8)
project(GestorBD)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/GestorDB/GestorDB.cpp src/GestorDB/GestorDB.h src/DataBase/DataBase.cpp src/DataBase/DataBase.h src/DataBase/Table.cpp src/DataBase/Table.h src/DataBase/Data.cpp src/DataBase/Data.h)
add_executable(GestorBD ${SOURCE_FILES})