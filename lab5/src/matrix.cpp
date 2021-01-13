#include "matrix.hpp"

Matrix::Matrix(int n, int m)
{
    if(n <= 0 || m <= 0)
    {
        throw MyException("Wrong size of an array");
    }
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
    if(n <= 0)
        throw MyException("Wrong size of a square array");

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
    if (!in.is_open())
    {
        throw MyException("Cannot open the file");
    }
    in >> n_class;
    in >> m_class;
 
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

double Matrix::get(int n, int m) const
{
    if (n > rows() || n < 0 || m > cols() || m < 0)
        throw MyException("Index error");

    return arr[n][m];
}

int Matrix::rows() const
{
    return n_class;
}

int Matrix::cols() const
{
    return m_class;
}

Matrix Matrix::operator +(const Matrix& m2)
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
    }else{
        throw MyException("Addition is impossible");
    }

    return madd;
}

Matrix Matrix::operator -(const Matrix& m2)
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
        }else{
            throw MyException("Subtraction is impossible");
        }
        return msub;
}

Matrix Matrix::operator *(const Matrix& m2)
{
    Matrix mmul(rows(),cols());
    
    if (cols() != m2.rows())
    {
        throw MyException("Multiplication is impossible");
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

void Matrix::operator +=(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                arr[i][j] += m2.arr[i][j];
            }
        }

    }else{
        throw MyException("Addition and assigning is impossible");

    }
}

void Matrix::operator ++(int inc)
{
    if(inc!=0)
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                arr[i][j]+=inc;
            }
        }
    }
    else{
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                arr[i][j]++;
            }
        }
    }
}


void Matrix::operator -=(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                arr[i][j] -= m2.arr[i][j];
            }
        }

    }else{
        throw MyException("Subtraction and assigning is impossible");
    }
}

bool Matrix::operator ==(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < n_class; i++)
        {
            for (int j = 0; j < m_class; j++)
            {
                if(arr[i][j] != m2.arr[i][j])
                   return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m2)
{
    
    os << m2.rows() << " " << m2.cols() << std::endl;
    for (int i = 0; i < m2.rows(); i++)
    {
        for (int j = 0; j < m2.cols(); j++)
        {
            os << std::setw(4) << m2.get(i,j) << "  ";
        }
        os << std::endl;
    }

    return os;
}


void Matrix::operator [](int n)
{
    if(n > rows() || n < 0)
    {
        throw MyException("The given number is not in the availability range");
    }
    for(int j = 0; j < m_class; j++)
        std::cout << arr[n][j] << std::setw(4);
    std::cout << std::endl;
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
