#include <iostream>
#include "matrix.hpp"
#include <ctime>


int main()
{
    srand(time(NULL));
    Matrix m1(6,5);
    std::cout << "\nm1: " << std::endl;
    std::cout << "Rows: " << m1.rows() << std::endl;
    std::cout << "Cols: " << m1.cols() << std::endl;
    
    for (int i = 0; i < m1.rows(); i++)
    {
        for (int j = 0; j < m1.cols(); j++) 
        {
            m1.set(i, j, rand() % 10);
        }
    }
    m1.print();

    Matrix m2(6,5);
    std::cout << "\nm2: " << std::endl;
    std::cout << "Rows: " << m2.rows() << std::endl;
    std::cout << "Cols: " << m2.cols() << std::endl;
    
    for (int i = 0; i < m2.rows(); i++)
    {
        for (int j = 0; j < m2.cols(); j++) 
        {
            m2.set(i, j, rand() % 10);
        }
    }
    m2.print();

    Matrix m3(5);
    std::cout << "\nm3: " << std::endl;
    std::cout << "Rows: " << m3.rows() << std::endl;
    std::cout << "Cols: " << m3.cols() << std::endl;
    
    for (int i = 0; i < m3.rows(); i++)
    {
        for (int j = 0; j < m3.cols(); j++) 
        {
            m3.set(i, j, rand() % 10);
        }
    }
    m3.print();

    std::cout << "\nm1 + m2:" << std::endl;
    m1.add(m2).print();

    std::cout << "\nm1 - m2:" << std::endl;
    m1.subtract(m2).print();

    std::string filename, path;
    std::cout << "\nPodaj nazwe bazy dannych do zapisu bez typu(.db): ";
    std::cin >> filename;
    std::cout << "Podaj sciezke do zapisu(np. C:\\\\folder_name\\\\): ";
    std::cin >> path;
    std::cout << "\nm1 mnozymy przez m3 a zatem zapisujemy do bazy dannych " << std::endl;
    m1.multiply(m3).store(filename, path);
    std::cout << "\nOdczytujemy macierz m4 z bazy dannych: " << std::endl;

    Matrix m4(filename, path);
    
    std::cout << "Rows: " << m4.rows() << std::endl;
    std::cout << "Cols: " << m4.cols() << std::endl;
    m4.print();

    system("pause");
    return 0;
} 