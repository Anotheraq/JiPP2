#include "matrix.hpp"
#include <iostream>
#include <ctime>

int main()
{
    try{
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
        (m1+m2).print();
        std::cout << "\nm1 - m2:" << std::endl;
        (m1-m2).print();
        
        std::cout << "\nm1 * m3:" << std::endl;
        (m1*m3).print();
        std::cout << "m2+=m1: " << std::endl;
        m2+=m1;
        m2.print();
        std::cout << "m1++: " << std::endl;
        m1++;
        m1.print();
        std::cout << "m2-=m1: " << std::endl;
        m2-=m1;
        m2.print();
        
        if(m1==m2)
        {
            std::cout << "Macierze m1 oraz m2 sa identyczne" << std::endl;
        }else{
            std::cout << "Macierze m1 oraz m2 sa rozne" << std::endl;
        }
        std::cout << "m1[0]: ";
        m1[0];
        
        std::string filename, path;
        std::cout << "\nPodaj nazwe pliku do zapisu: ";
        std::cin >> filename;
        std::cout << "Podaj sciezke do zapisu(np. C:\\\\folder_name\\\\): ";
        std::cin >> path;
        
        
        std::ofstream file;
        file.open(path + filename, std::ios::out);
        
        if(file.is_open())
            file << m1;

        Matrix m4(filename, path);
        m4.print();
    }   
    catch(MyException &e)
    {
        std::cout << e.what() << std::endl;
    } 
    system("pause");
    return 0;
} 