#ifndef ANT_H
#define ANT_H

#include <vector>

class ant {
public:
  ant(const std::vector<std::vector<double>> &interests, size_t nodes_count,
      size_t start);
  std::vector<size_t> get_route();

private:
  void find_route();

  std::vector<std::vector<double>> interests;
  size_t nodes_count;

  std::vector<size_t> route;
};

#endif // ANT_H
