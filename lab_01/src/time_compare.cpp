#include "time_compare.hpp"
#include "levenstein.hpp"
#include "string_gen.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

double func_time(method_func_t func, size_t str_len, size_t iterations) {
  string str1 = string_gen(str_len), str2 = string_gen(str_len);
  clock_t start = clock();
  for (size_t i = 0; i < iterations; i++) {
    func(str1, str2);
  }
  return ((double)(clock() - start)) / iterations;
}

void write_header() {
  cout << setw(37) << "Time in ms" << endl;
  cout << setw(4) << "Len" << setw(15) << "Matrix" << setw(15) << "Recursion"
       << setw(15) << "With cache" << setw(15) << "Domerau" << endl;
}

void time_compare(bool write_to_std) {
  ofstream mtr_file;
  ofstream rec_file;
  ofstream dom_file;
  ofstream rec_cache_file;

  if (write_to_std) {
    write_header();
  } else {
    mtr_file.open("time_itmat.csv");
    mtr_file << "len,IterativeMatrix" << endl;

    rec_file.open("time_rec.csv");
    rec_file << "len,Recursive" << endl;

    dom_file.open("time_dl.csv");
    dom_file << "len,DamerauLevenshtein" << endl;

    rec_cache_file.open("time_recmat.csv");
    rec_cache_file << "len,RecursiveMatrix" << endl;
  }

  size_t n = 100000;
  for (size_t j = 5; j < 10; j += 1) {
    if (write_to_std) {
      cout << setw(4) << j;
      cout << setw(15) << func_time(matr_method, j, n);
      cout << setw(15) << func_time(recur_method, j, n / 100);
      cout << setw(15) << func_time(rec_cache_method, j, n);
      cout << setw(15) << func_time(Domerau_method, j, n);
      cout << endl;
    } else {
      mtr_file << j << "," << func_time(matr_method, j, n) << endl;
      rec_file << j << "," << func_time(recur_method, j, n / 100) << endl;
      rec_cache_file << j << "," << func_time(rec_cache_method, j, n) << endl;
      dom_file << j << "," << func_time(Domerau_method, j, n) << endl;
    }
  }

  n = 100;
  for (size_t j = 10; j < 60; j += 10) {
    if (write_to_std) {
      cout << setw(4) << j;
      cout << setw(15) << func_time(matr_method, j, n);
      cout << setw(15) << func_time(rec_cache_method, j, n);
      cout << setw(15) << func_time(Domerau_method, j, n);
      cout << endl;
    } else {
      mtr_file << j << "," << func_time(matr_method, j, n) << endl;
      rec_cache_file << j << "," << func_time(rec_cache_method, j, n) << endl;
      dom_file << j << "," << func_time(Domerau_method, j, n) << endl;
    }
  }

  if (!write_to_std) {
    mtr_file.close();
    rec_file.close();
    rec_cache_file.close();
    dom_file.close();
  }
}
