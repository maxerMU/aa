#include "algorithms.hpp"
#include "arr_gen.hpp"
#include "time_compare.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 3;
  Matrix<int> matr1(n, n);
  Matrix<int> matr2(n, n);
  Matrix<int> result(n, n);
  matr_gen(matr1, n, n, 5);
  matr_gen(matr2, n, n, 5);

  cout << "Matrix 1:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matr1[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  cout << "Matrix 2:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matr2[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  cout << "Classic algorithm:" << endl;
  standart(result, matr1, n, n, matr2, n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  cout << "Vinograd algorithm:" << endl;
  vinograd(result, matr1, n, n, matr2, n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  cout << "Optimized vinograd algorithm:" << endl;
  optimized_vinograd(result, matr1, n, n, matr2, n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  cout << endl << "Results for even sizes:" << endl;
  time_compare(100, 200, 100);

  cout << endl << "Results for odd sizes:" << endl;
  time_compare(101, 201, 100);
  return 0;
}
