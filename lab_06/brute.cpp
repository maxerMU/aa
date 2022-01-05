#include "brute.h"

double brute::find_shortest_way() {
  std::vector<size_t> route;
  for (size_t i = 0; i < routes.n(); i++)
    route.push_back(i);

  double res = find_route_distance(route);
  while (route_next_step(route)) {
    double cur_res = find_route_distance(route);
    if (cur_res < res)
      res = cur_res;
  }

  return res;
}

double brute::find_route_distance(const std::vector<size_t> &route) {
  double res = 0;
  for (size_t i = 0; i < route.size() - 1; i++) {
    res += routes[route[i]][route[i + 1]];
  }

  res += routes[route[route.size() - 1]][route[0]];

  return res;
}

bool brute::route_next_step(std::vector<size_t> &route) {
  int n = route.size();

  int j = n - 2;
  while (j != -1 && route[j] > route[j + 1])
    j--;

  if (j == -1)
    return false; // больше перестановок нет

  int k = n - 1;
  while (route[j] > route[k])
    k--;

  std::swap(route[j], route[k]);

  int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
  while (l < r)
    std::swap(route[l++], route[r--]);
  return true;
}
