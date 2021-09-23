#pragma once
#include <stdlib.h>

typedef int *(*gen_func_t)(size_t);

int *gen_worst(size_t length);
int *gen_random(size_t length);
int *gen_best(size_t length);