#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

template <typename Type>
class Matrix
{
private:
    int _n, _m;
    Type **matrix;
public:
    Matrix(int n, int m);
    ~Matrix();

    int n() {return _n; }
    int m() {return _m; }

    Type &operator ()(int i, int j) {return matrix[i][j]; }
    Type* operator [](int i){return matrix[i]; }

    Type *getArray() {return matrix[0]; }
    void print();
};

template<typename Type>
ostream & operator<< (ostream & stream, Matrix<Type> & m)
{
    for(int i = 0; i < m.n(); i++)
    {
        for(int j = 0; j < m.m(); j++)
            stream << m[i][j] <<" ";
        stream << "\n";
    }
    return stream;
}

template<typename Type>
void Matrix<Type>::print()
{
    for (size_t i = 0; i < _n; i++)
    {
        for (size_t j = 0; j < _m; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

template<typename Type>
Matrix<Type>::Matrix(int n, int m)
    :
      _n(n),
      _m(m)
{
    matrix = new Type*[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new Type[m];
}

template<typename Type>
Matrix<Type>::~Matrix()
{
    for (int i = 0; i < _n; i++)
        delete [] matrix[i];

    delete [] matrix;
}

#endif // MATRIX_HPP
