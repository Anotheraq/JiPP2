#include "matrix.hpp"

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

Matrix *mdbcb;

//callback func
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(argv[2][0] == 'n')
    {
        mdbcb = new Matrix(atoi(argv[0]), atoi(argv[1]));
    }else{
        mdbcb -> set(atoi(argv[0]), atoi(argv[1]), atoi(argv[2]));
    }
    return 0;
}

/*
Constructor macierzy z bazy dannych
*/
Matrix::Matrix(std::string filename, std::string path)
{
    
    std::string sql;
    sqlite3 *dbs;
    
    std::string pn = path+filename + ".db";
    sqlite3_open(pn.c_str(), &dbs);
    
    sql = "SELECT * FROM 'MATRIX'";
    sqlite3_exec(dbs, sql.c_str(), callback, 0, 0);
    
    n_class = mdbcb->n_class;
    m_class = mdbcb->m_class;

    arr = (double**)new double* [n_class];
    for (int i = 0; i < n_class; i++)
        arr[i] = (double*)new double[m_class];

    for (int i = 0; i < n_class; i++)
        for (int j = 0; j < m_class; j++)
            arr[i][j] = mdbcb->get(i,j);
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


/*
zapisywanie macierzy w bazu dannych
*/
void Matrix::store(std::string filename,std::string path)
{
    std::string sql;
    sqlite3 *dbs;
    std::string pn = path+filename + ".db";

    sqlite3_open(pn.c_str(), &dbs);
        
    sql = "CREATE TABLE MATRIX(n,m,v);";
    sqlite3_exec(dbs, sql.c_str(), 0, 0, 0);
    
    sql = "INSERT INTO MATRIX ('n', 'm', 'v') VALUES ('" + std::to_string(rows()) + "','" + std::to_string(cols()) + "','n');";
    sqlite3_exec(dbs, sql.c_str(), 0, 0, 0);
    
    for (int i = 0; i < rows(); i++)
    {
        for (int j = 0; j < cols(); j++)
        {
            sql = "INSERT INTO MATRIX ('n', 'm', 'v') VALUES ('" + std::to_string(i) + "','" + std::to_string(j) + "','" + std::to_string(arr[i][j]) + "');";
            sqlite3_exec(dbs, sql.c_str(), 0, 0, 0);
        }
    }
    sqlite3_close(dbs);
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
