#pragma once

#define TIME_ITERATIONS 1000000
#define START_SIZE 10
#define SIZE_STEP 10
#define SIZE_COUNT 10

#include "gen.h"

void get_statistic(const char *filename, int sort_type, gen_func_t gen_func);