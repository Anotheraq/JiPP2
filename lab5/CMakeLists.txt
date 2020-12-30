# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( lab5 )

include_directories( ./include ./include/lab5 ./src )

add_executable( main ./src/main.cpp ./src/matrix.cpp )