# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( lab6 )

include_directories( ./include ./src ./include/lab6)

add_executable( main ./src/main.cpp ./src/HRMS.cpp ./src/Employee.cpp )