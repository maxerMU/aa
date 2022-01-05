#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>
#include <ostream>
#include <string.h>

using namespace std;

template <typename Type> class Matrix {
private:
  size_t _n, _m;
  Type **matrix;

public:
  Matrix();
  Matrix(int n, int m);
  ~Matrix();

  Matrix(const Matrix<Type> &mtr);
  Matrix(const Matrix<Type> &&mtr);

  size_t n() { return _n; }
  size_t m() { return _m; }

  Type *operator[](int i) { return matrix[i]; }
  Matrix<Type> &operator=(const Matrix<Type> &mtr);

  void print();
};

template <typename Type> ostream &operator<<(ostream &stream, Matrix<Type> &m) {
  for (int i = 0; i < m.n(); i++) {
    for (int j = 0; j < m.m(); j++)
      stream << m[i][j] << " ";
    stream << "\n";
  }
  return stream;
}

template <typename Type> void Matrix<Type>::print() {
  for (size_t i = 0; i < _n; i++) {
    for (size_t j = 0; j < _m; j++)
      std::cout << matrix[i][j] << " ";

    std::cout << std::endl;
  }
}

template <typename Type>
Matrix<Type>::Matrix() : _n(0), _m(0), matrix(nullptr) {}

template <typename Type> Matrix<Type>::Matrix(int n, int m) : _n(n), _m(m) {
  matrix = new Type *[n];

  for (int i = 0; i < n; i++)
    matrix[i] = new Type[m];
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix<Type> &mtr) {
  _n = mtr._n;
  _m = mtr._m;
  matrix = new Type *[mtr._n];

  for (size_t i = 0; i < _n; i++) {
    matrix[i] = new Type[_m];
    memcpy(matrix[i], mtr.matrix[i], sizeof(Type) * _m);
  }

  return *this;
}

template <typename Type> Matrix<Type>::Matrix(const Matrix<Type> &mtr) {
  _n = mtr._n;
  _m = mtr._m;
  matrix = new Type *[mtr._n];

  for (size_t i = 0; i < _n; i++) {
    matrix[i] = new Type[_m];
    memcpy(matrix[i], mtr.matrix[i], sizeof(Type) * _m);
  }
}

template <typename Type> Matrix<Type>::Matrix(const Matrix<Type> &&mtr) {
  _n = mtr._n;
  _m = mtr._m;
  matrix = mtr.matrix;
}

template <typename Type> Matrix<Type>::~Matrix() {
  for (size_t i = 0; i < _n; i++)
    delete[] matrix[i];

  delete[] matrix;
}

#endif // MATRIX_H
