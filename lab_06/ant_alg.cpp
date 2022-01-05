#include "ant_alg.h"
#include "ant.h"
#include <cmath>
#include <limits>

ant_alg::ant_alg(const Matrix<double> &routes, double alpha, double beta,
                 double ro, size_t iterations)
    : routes(routes), alpha(alpha), beta(beta), ro(ro), iterations(iterations) {
  for (size_t i = 0; i < routes.n(); i++) {
    std::vector<double> row_pheromon;
    for (size_t j = i; j < routes.m(); j++)
      row_pheromon.push_back(PHEROMON_START);

    pheromon.push_back(row_pheromon);
  }
}

double ant_alg::find_shortest_way() {
  double res = std::numeric_limits<double>::max();
  for (size_t k = 0; k < iterations; k++) {
    std::vector<std::vector<double>> interests;
    find_interests(interests);

    evaporation();
    for (size_t i = 0; i < routes.n(); i++) {
      ant a(interests, routes.n(), i);
      std::vector<size_t> route = a.get_route();
      double cur_length = route_length(route);
      if (cur_length < res)
        res = cur_length;
      update_pheromon(route, cur_length);
    }
  }

  return res;
}

void ant_alg::update_pheromon(std::vector<size_t> route, double length) {
  double pheromon_step = 1 / length;
  for (size_t i = 0; i < route.size() - 1; i++) {
    if (route[i] < route[i + 1])
      pheromon[route[i]][route[i + 1] - route[i]] += pheromon_step;
    else
      pheromon[route[i + 1]][route[i] - route[i + 1]] += pheromon_step;
  }
  if (route[0] < route[route.size() - 1])
    pheromon[route[0]][route[route.size() - 1] - route[0]] += pheromon_step;
  else
    pheromon[route[route.size() - 1]][route[0] - route[route.size() - 1]] +=
        pheromon_step;
}

double ant_alg::route_length(const std::vector<size_t> &route) {
  double res = 0;
  for (size_t i = 0; i < route.size() - 1; i++) {
    res += routes[route[i]][route[i + 1]];
  }

  res += routes[route[route.size() - 1]][route[0]];

  return res;
}

void ant_alg::evaporation() {
  for (size_t i = 0; i < pheromon.size(); i++)
    for (size_t j = 0; j < pheromon[i].size(); j++) {
        if (pheromon[i][j] < 1e-6)
            pheromon[i][j] = 0.2;
      pheromon[i][j] *= (1 - ro);
    }
}

void ant_alg::find_interests(std::vector<std::vector<double>> &intersts) {
  intersts.clear();
  for (size_t i = 0; i < routes.n(); i++) {
    std::vector<double> row_interest;
    for (size_t j = i; j < routes.m(); j++) {
      double interest;
      if (i != j) {
        double t = std::pow(pheromon[i][j - i], alpha);
        double n = std::pow(1 / routes[i][j], beta);
        interest = t * n;

      } else
        interest = 0;
      row_interest.push_back(interest);
    }

    intersts.push_back(row_interest);
  }
}
