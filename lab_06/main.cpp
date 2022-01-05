#include "matrix.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "ant_alg.h"
#include "brute.h"

#define CUSTOM_PATH "route.txt"
#define TIME_COMPARE_PATH "time_compare.csv"

#define EPS 1e-6

using namespace std;

int read_matrix(Matrix<double> &res, const std::string &file_name) {
  ifstream file(file_name);

  size_t nodes;

  if (!(file >> nodes))
    return 1;

  res = Matrix<double>(nodes, nodes);
  for (size_t i = 0; i < nodes * nodes; i++) {
    double node;
    if (!(file >> node))
      return 1;
    res[i / nodes][i % nodes] = node;
  }

  file.close();

  return 0;
}

void generate_matrix(Matrix<double> &mtr, size_t n, int max_value) {
  mtr = Matrix<double>(n, n);
  for (size_t i = 0; i < n; i++)
    for (size_t j = i; j < n; j++) {
      double val = 0;
      if (i != j)
        val = 1 + rand() % max_value;
      mtr[i][j] = val;
      mtr[j][i] = val;
    }
}

void time_compare() {
  ofstream file(TIME_COMPARE_PATH);

  file << "Matrix Size,Ant,Brute" << std::endl;
  for (size_t i = 2; i < 11; i += 1) {
    Matrix<double> mtr;
    generate_matrix(mtr, i, 20);
    brute b(mtr);
    ant_alg a(mtr, 0.5, 0.5, 0.1, 10);
    file << i << "," << a.algorithm_time() << "," << b.algorithm_time()
         << std::endl;
  }

  file.close();
}

void ant_stat(int max_value) {
  Matrix<double> mtr;
  generate_matrix(mtr, 10, max_value);

  brute b(mtr);
  double etalon = b.find_shortest_way();

  mtr.print_csv(std::string("matrix_") + std::to_string(max_value) +
                std::string(".csv"));

  ofstream file(std::string("matrix_ant_time_") + std::to_string(max_value) +
                std::string(".csv"));
  file << "a,b,ro,res,diff" << std::endl;
  for (double a = 0; 1 - a > EPS; a += 0.4) {
    for (double b = 0; 1 - b > EPS; b += 0.4) {

      for (double r = 0; 1 - r > EPS; r += 0.4) {
        ant_alg a_alg(mtr, a, b, r, 20);
        double len = a_alg.find_shortest_way();
        file << a << "&" << b << "&" << r << "&" << len << "&" << len - etalon
             << "\\\\" << std::endl;
      }
    }
    file << "\\hline" << std::endl;
  }

  file.close();
}

int main() {
  Matrix<double> routes;
  int rc = read_matrix(routes, std::string(CUSTOM_PATH));
  if (rc)
    return rc;

  routes.print();
  brute b(routes);

  std::cout << "Brute shortest way: " << b.find_shortest_way() << std::endl;

  double alpha, beta, ro;
  size_t iter;
  std::cout << "Input alpha, beta, ro, days: ";
  std::cin >> alpha >> beta >> ro >> iter;
  ant_alg a(routes, alpha, beta, ro, iter);
  std::cout << "Ant shortest way: " << a.find_shortest_way() << std::endl;

  int inp;
  std::cout << "Do you want get statistic (1, 0): ";
  std::cin >> inp;
  if (inp == 1) {
    time_compare();
    ant_stat(20);
  }

  return 0;
}
