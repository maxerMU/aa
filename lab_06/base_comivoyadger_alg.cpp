#include "base_comivoyadger_alg.h"
#include <time.h>

#define ITERATIONS 5

double base_comivoyadger_alg::algorithm_time() {
  clock_t start = clock();
  for (size_t i = 0; i < ITERATIONS; i++)
    find_shortest_way();

  return ((double)clock() - start) / ITERATIONS;
}
