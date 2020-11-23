#include "lab4\matrix.hpp"

Matrix::Matrix(int n, int m)
{
    n_class = n;
    m_class = m;
    arr = new double *[n_class];

    for (int i = 0; i < n_class; i++)
    {
        arr[i] = new double[m_class];
    }

    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            arr[i][j] = 0;
        }
    }
}
Matrix::Matrix(int n)
{
    m_class = n;
    n_class = n;
    
    arr = new double *[n_class];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[n_class];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
}
Matrix::Matrix(std::string filename, std::string path)
{
    std::ifstream in;
    in.open(path + filename);
    if (in.is_open())
    {
        in >> n_class;
        in >> m_class;
        if (n_class > 0 && m_class > 0)
        {
            arr = new double* [n_class];
            for (int i = 0; i < n_class; i++)
                arr[i] = new double[m_class];

            for (int i = 0; i < n_class; i++)
                for (int j = 0; j < m_class; j++)
                    in >> arr[i][j];
        }
        in.close();
    }
    else
        std::cout << "Nie udalo sie otworzyc plik" << std::endl;

}



void Matrix::set(int n, int m, double val)
{
    arr[n][m] = val;
}

double Matrix::get(int n, int m)
{
    return arr[n][m];
}

int Matrix::rows()
{
    return n_class;
}

int Matrix::cols()
{
    return m_class;
}

Matrix Matrix::add(Matrix m2)
{
    Matrix madd(rows(),cols());
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                madd.arr[i][j] = arr[i][j] + m2.arr[i][j];
            }
        }
        return madd;
    }else{
        std::cout << "Dodanie niemozliwe";
        exit(1);
    }
}

Matrix Matrix::subtract(Matrix m2)
{
    Matrix msub(rows(),cols());
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                msub.arr[i][j] = arr[i][j] - m2.arr[i][j];
            }
        }
        return msub;
    }else{
        std::cout << "Odejmowanie niemozliwe";
        exit(1);
    }
}

Matrix Matrix::multiply(Matrix m2)
{
    Matrix mmul(rows(),cols());
    if (cols() != m2.rows())
    {
        std::cout << "Mnozenie podanych macierzy nie jest mozliwe" << std::endl;
        exit(1);
    }
    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            for (int k = 0; k < m_class; k++)
                mmul.arr[i][j] += arr[i][k] * m2.arr[k][j];
        }
    }
    return mmul;
}

void Matrix::store(std::string filename,std::string path)
{
    std::ofstream file;
    file.open(path + filename);
    file << n_class << ' ' << m_class << std::endl;
    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            file << arr[i][j] << ' ';
        }
        file << std::endl;
    }
    file.close();
}

void Matrix::print()
{
    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            std::cout << std::setw(4) << get(i,j) << "  ";
        }
        std::cout << std::endl;
    }
}
