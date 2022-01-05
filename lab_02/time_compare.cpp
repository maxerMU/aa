#include "time_compare.hpp"
#include "arr_gen.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

double func_time(mtr_func_t func, size_t n, size_t iterations) {
  Matrix<int> mtr1(n, n);
  matr_gen(mtr1, n, n, LIMIT);

  Matrix<int> mtr2(n, n);
  matr_gen(mtr2, n, n, LIMIT);

  Matrix<int> res(n, n);

  clock_t start = clock();
  for (size_t i = 0; i < iterations; i++) {
    func(res, mtr1, n, n, mtr2, n, n);
  }
  return ((double)(clock() - start)) / iterations;
}

void write_header() {
  cout << setw(37) << "Time in ms" << endl;
  cout << setw(4) << "Len" << setw(20) << "std" << setw(20) << "Vinograd"
       << setw(20) << "Vinograd improved" << setw(20) << endl;
}

void time_compare(size_t min_size, size_t max_size, size_t step,
                  const char *file_name) {
  ofstream file;

  if (!file_name) {
    write_header();
  } else {
    file.open(file_name);
    file << "len,Standart,Vinograd,Optimized" << endl;
  }

  for (size_t n = min_size; n <= max_size; n += step) {
    if (!file_name) {
      cout << setw(4) << n;
      cout << setw(20) << func_time(standart, n, ITERATIONS);
      cout << setw(20) << func_time(vinograd, n, ITERATIONS);
      cout << setw(20) << func_time(optimized_vinograd, n, ITERATIONS);
      cout << endl;
    } else {
      file << n;
      file << func_time(standart, n, ITERATIONS) << ",";
      file << func_time(vinograd, n, ITERATIONS) << ",";
      file << func_time(optimized_vinograd, n, ITERATIONS);
      file << endl;
    }
  }

  if (!file_name) {
    file.close();
  }
}
