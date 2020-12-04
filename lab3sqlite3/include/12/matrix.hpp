#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "sqlite3/sqlite3.h"


class Matrix
{
    private:
        double ** arr;
        int n_class {}, m_class {};
    public:
        Matrix(int n, int m);
        Matrix(int n);
        Matrix(std::string filename, std::string path);
        void set(int n, int m, double val);
        double get(int x, int y);
        Matrix add(Matrix m2);
        Matrix subtract(Matrix m2);
        Matrix multiply(Matrix m2);
        int rows();
        int cols();
        void store(std::string filename,std::string path);
        void print();
};