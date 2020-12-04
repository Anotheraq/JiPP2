cmake_minimum_required(VERSION 3.0)

project(sqlite3)

#include_directories( ./include ./include/12 ./src ./libs/sqlite3/include)

add_library(sqlite3 STATIC ./src/sqlite3.c ./src/shell.c )