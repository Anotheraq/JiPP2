# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( lab3exceptions )

include_directories( ./include ./src ./include/lab3exceptions )

add_executable( main ./src/Main.cpp ./src/matrix.cpp )