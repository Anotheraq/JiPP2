# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( lab3sqlite3 )

include_directories( ./include ./include/lab3sqlite3 ./src ./libs/sqlite3/include ./libs)

add_executable( main ./src/main.cpp ./src/matrix.cpp)

add_subdirectory( ./libs/sqlite3 )
target_link_libraries( main sqlite3 )
