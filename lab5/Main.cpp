#include "matrix.cpp"
#include <iostream>
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
    Matrix A = m1+m2;
    A.print();
    std::cout << "\nm1 - m2:" << std::endl;
    Matrix B = m1-m2;
    B.print();
    
    std::cout << "\nm1 * m3:" << std::endl;
    Matrix C = m1*m3;
    C.print();

    std::cout << "m1 == m2: ";
    bool rownosc = m1 == m2;
    std::cout << rownosc << std::endl;
    std::cout << "m1[0]: ";
    m1[0];
    
    std::string filename, path;
    std::cout << "\nPodaj nazwe pliku do zapisu: ";
    std::cin >> filename;
    std::cout << "Podaj sciezke do zapisu(np. C:\\\\folder_name\\\\): ";
    std::cin >> path;
    
    std::cout << m1;
    
    std::ofstream file;
    file.open(path + filename);
    file << m1;

    system("pause");
    return 0;
} 