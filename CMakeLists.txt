# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( lab4 )

include_directories( ./include ./src )

add_executable( main ./src/Main.cpp ./src/matrix.cpp )