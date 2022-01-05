#ifndef INC_01_TIME_COMPARE_HPP
#define INC_01_TIME_COMPARE_HPP

#include <iostream>
#include <ostream>

#include "algorithms.hpp"

#define LIMIT 10000
#define ITERATIONS 100

void time_compare(size_t min_size, size_t max_size, size_t step,
                  const char *file_name = nullptr);

#endif
