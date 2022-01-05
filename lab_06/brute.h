#ifndef BRUTE_H
#define BRUTE_H

#include "base_comivoyadger_alg.h"
#include "matrix.h"
#include <vector>

class brute : public base_comivoyadger_alg {
public:
  brute(const Matrix<double> &routes) : routes(routes) {}
  virtual double find_shortest_way() override;

private:
  Matrix<double> routes;
  double find_route_distance(const std::vector<size_t> &route);
  bool route_next_step(std::vector<size_t> &route);
};

#endif // BRUTE_H
