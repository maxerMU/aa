#include <stdio.h>
#include <string.h>
#include <time.h>

#include "statistic.h"
#include "sorts.h"
#include "gen.h"

void get_statistic(const char *filename, int sort_type, gen_func_t gen_func)
{
    FILE *f= fopen(filename, "w");

    for (size_t size = START_SIZE; size < START_SIZE + SIZE_STEP * SIZE_COUNT; size += SIZE_STEP)
    {
        int *a = gen_func(size);
        int *a_copy = malloc(size * sizeof(int));
        memcpy(a_copy, a, size * sizeof(int));

        clock_t copy = clock();
        for (size_t i = 0; i < TIME_ITERATIONS; i++)
        {
            memcpy(a, a_copy, size * sizeof(int));
        }
        copy = clock() - copy;
        // double copy_time = ((double)copy / CLOCKS_PER_SEC) / TIME_ITERATIONS;

        clock_t sort = clock();
        for (size_t i = 0; i < TIME_ITERATIONS; i++)
        {
            switch (sort_type)
            {
            case 0:
                bubble_sort(a, size);
                break;
            case 1:
                insertion_sort(a, size);
                break;
            case 2:
                quick_sort(a, 0, size - 1);
                break;
            }
            memcpy(a, a_copy, size * sizeof(int));
        }
        sort = clock() - sort;
        // double sort_time = ((double)sort / CLOCKS_PER_SEC) / TIME_ITERATIONS - copy_time;

        fprintf(f, "%zu %ld\n", size, sort - copy);

        free(a);
        free(a_copy);
    }

    fclose(f);
}