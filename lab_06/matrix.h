#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>
#include <ostream>
#include <string.h>

using namespace std;

template <typename Type> class Matrix {
public:
  Matrix();
  Matrix(int n, int m);
  ~Matrix();

  Matrix(const Matrix<Type> &mtr);

  int n() const { return _n; }
  int m() const { return _m; }

  Type *operator[](int i) { return matrix[i]; }
  Matrix<Type> &operator=(const Matrix<Type> &mtr);

  void print() const;
  void print_csv(const std::string &file_name) const;
  void fill(const Type &value);

private:
  int _n, _m;
  int allocated_rows, allocated_columns;
  Type **matrix;
};

template <typename Type> ostream &operator<<(ostream &stream, Matrix<Type> &m) {
  for (int i = 0; i < m.n(); i++) {
    for (int j = 0; j < m.m(); j++)
      stream << m[i][j] << " ";
    stream << "\n";
  }
  return stream;
}

template <typename Type> void Matrix<Type>::print() const {
  for (size_t i = 0; i < _n; i++) {
    for (size_t j = 0; j < _m; j++)
      std::cout << matrix[i][j] << " ";

    std::cout << std::endl;
  }
}

template <typename Type>
void Matrix<Type>::print_csv(const std::string &file_name) const {
  ofstream file(file_name);
  for (size_t i = 0; i < _n; i++) {
    for (size_t j = 0; j < _m - 1; j++)
      file << matrix[i][j] << ",";

    file << matrix[i][_m - 1] << std::endl;
  }

  file.close();
}

template <typename Type> void Matrix<Type>::fill(const Type &value) {
  for (size_t i = 0; i < _n; i++) {
    for (size_t j = 0; j < _m; j++)
      matrix[i][j] = value;
  }
}

template <typename Type>
Matrix<Type>::Matrix()
    : _n(0), _m(0), allocated_rows(0), allocated_columns(0), matrix(nullptr) {}

template <typename Type> Matrix<Type>::Matrix(int n, int m) : _n(n), _m(m) {
  matrix = new Type *[n];

  for (allocated_rows = 0; allocated_rows < n; allocated_rows++) {
    matrix[allocated_rows] = new Type[m];
  }

  allocated_columns = m;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix<Type> &mtr) {
  if (allocated_rows < mtr._n || allocated_columns < mtr._m) {
    if (allocated_rows != 0) {
      for (int i = 0; i < allocated_rows; i++)
        delete[] matrix[i];

      delete[] matrix;
    }

    matrix = new Type *[mtr._n];

    for (allocated_rows = 0; allocated_rows < mtr._n; allocated_rows++) {
      matrix[allocated_rows] = new Type[mtr._m];
    }
    allocated_columns = mtr._m;
  }

  _n = mtr._n;
  _m = mtr._m;

  for (size_t i = 0; i < _n; i++) {
    memcpy(matrix[i], mtr.matrix[i], sizeof(Type) * _m);
  }

  return *this;
}

template <typename Type> Matrix<Type>::Matrix(const Matrix<Type> &mtr) {

  matrix = new Type *[mtr._n];

  _n = mtr._n;
  _m = mtr._m;

  for (allocated_rows = 0; allocated_rows < mtr._n; allocated_rows++) {
    matrix[allocated_rows] = new Type[mtr._m];
  }
  allocated_columns = mtr._m;

  for (size_t i = 0; i < _n; i++) {
    memcpy(matrix[i], mtr.matrix[i], sizeof(Type) * _m);
  }
}

template <typename Type> Matrix<Type>::~Matrix() {
  for (int i = 0; i < allocated_rows; i++)
    delete[] matrix[i];

  delete[] matrix;
}

#endif // MATRIX_H
