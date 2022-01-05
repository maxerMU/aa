#ifndef ANT_ALG_H
#define ANT_ALG_H

#define PHEROMON_START 0.2

#include "base_comivoyadger_alg.h"
#include "matrix.h"
#include <vector>

class ant_alg : public base_comivoyadger_alg {
public:
  ant_alg(const Matrix<double> &routes, double alpha, double beta, double ro,
          size_t iterations);
  virtual double find_shortest_way() override;

private:
  void find_interests(std::vector<std::vector<double>> &intersts);
  double route_length(const std::vector<size_t> &route);
  void evaporation();
  void update_pheromon(std::vector<size_t> route, double length);

  Matrix<double> routes;
  double alpha;
  double beta;
  double ro;
  size_t iterations;

  std::vector<std::vector<double>> pheromon;
};

#endif // ANT_ALG_H
