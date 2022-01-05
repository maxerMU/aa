#include "ant.h"
#include <stdlib.h>

ant::ant(const std::vector<std::vector<double>> &interests, size_t nodes_count,
         size_t start)
    : interests(interests), nodes_count(nodes_count) {
  route.push_back(start);
}

std::vector<size_t> ant::get_route() {
  find_route();
  return route;
}

void ant::find_route() {
  for (size_t i = 0; i < nodes_count - 1; i++) {
    std::vector<std::pair<size_t, double>> probabilities;
    double interests_sum = 0;
    for (size_t j = 0; j < nodes_count; j++) {
      bool is_visited = false;
      for (size_t k = 0; k < route.size(); k++)
        if (j == route[k])
          is_visited = true;

      if (!is_visited) {
        double interest;
        if (route[i] < j)
          interest = interests[route[i]][j - route[i]];
        else
          interest = interests[j][route[i] - j];

        interests_sum += interest;
        probabilities.push_back(
            std::pair<size_t, double>(j, interest)); // division after loop
      }
    }

    for (size_t j = 0; j < probabilities.size(); j++) {
      probabilities[j].second /= interests_sum;
    }

    double seed = (double)(rand() % 100) / 100.0;
    size_t j = 0;
    double cur_prob = probabilities[0].second;

    while (cur_prob < seed && j + 1 < probabilities.size()) {
      cur_prob += probabilities[++j].second;
    }

    route.push_back(probabilities[j].first);
  }
}
