#ifndef INC_01_SORTS_HPP
#define INC_01_SORTS_HPP

#include "matrix.hpp"

using namespace std;

typedef int (*mtr_func_t)(Matrix<int> &, Matrix<int>, int, int, Matrix<int>,
                          int, int);

int standart(Matrix<int> &result, Matrix<int> matr1, int n1, int m1,
             Matrix<int> matr2, int n2, int m2);

int vinograd(Matrix<int> &result, Matrix<int> matr1, int n1, int m1,
             Matrix<int> matr2, int n2, int m2);

int optimized_vinograd(Matrix<int> &result, Matrix<int> matr1, int n1, int m1,
                       Matrix<int> matr2, int n2, int m2);

#endif
