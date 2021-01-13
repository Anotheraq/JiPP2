#ifndef MAT_HPP
#define MAT_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exceptions.hpp"

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
        double get(int x, int y) const;
        Matrix operator +(const Matrix& m2);
        Matrix operator -(const Matrix& m2);
        Matrix operator *(const Matrix& m2);
        Matrix operator >>(int n);
        void operator +=(const Matrix& m2);
        void operator -=(const Matrix& m2);
        bool operator ==(const Matrix& m2);
        void operator ++(int inc);
        void operator [](int n);
        int rows() const;
        int cols() const;
        void store(std::string filename,std::string path);
        void print();
};

std::ostream& operator<<(std::ostream& os, const Matrix& m2);
#endif