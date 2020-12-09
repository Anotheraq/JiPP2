#include "lab3exceptions/matrix.hpp"

Matrix::Matrix(int n, int m)
{
    n_class = n;
    m_class = m;

    if(n < 0 || m < 0)
    {
        throw MyException("Wrong size of an array");
    }
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

    if(n <= 0)
        throw MyException("Wrong size of a square array");

    arr = new double *[n_class];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[n_class];
    }

    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            arr[i][j] = 0;
        }
    }

    
}
Matrix::Matrix(std::string filename, std::string path)
{
    std::ifstream in;
    in.open(path + filename, std::ios::in);
    in >> n_class;
    in >> m_class;

    if (!in.is_open())
    {
        throw MyException("Cannot open the file");
    }

    arr = new double* [n_class];
    for (int i = 0; i < n_class; i++)
        arr[i] = new double[m_class];

    for (int i = 0; i < n_class; i++)
        for (int j = 0; j < m_class; j++)
            in >> arr[i][j];
    in.close();


}



void Matrix::set(int n, int m, double val)
{
    if (n > rows() || n < 0 || m > cols() || m < 0)
        throw MyException("Index error");

    arr[n][m] = val;
}

double Matrix::get(int n, int m)
{
    if (n > rows() || n < 0 || m > cols() || m < 0)
        throw MyException("Index error");
    
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
    if (rows() != m2.rows() && cols() != m2.cols())
        throw MyException("Addition is impossible");

    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            madd.arr[i][j] = arr[i][j] + m2.arr[i][j];
        }
    }

    return madd;

}

Matrix Matrix::subtract(Matrix m2)
{
    Matrix msub(rows(),cols());

    if (rows() != m2.rows() && cols() != m2.cols())
        throw MyException("Subtraction is impossible");
    
    for (int i = 0; i < n_class; i++)
    {
        for (int j = 0; j < m_class; j++)
        {
            msub.arr[i][j] = arr[i][j] - m2.arr[i][j];
        }
    }
    return msub;

}

Matrix Matrix::multiply(Matrix m2)
{
    Matrix mmul(rows(),cols());

    if (cols() != m2.rows())
        throw MyException("Multiplication is impossible");
        
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
    
    file.open(path + filename, std::ios::out);
    
    if(!file.is_open())
        throw MyException("Cannot open the file");
    
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

