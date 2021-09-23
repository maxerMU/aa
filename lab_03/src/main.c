#include <stdlib.h>
#include <stdio.h>

#include "statistic.h"
#include "sorts.h"
#include "gen.h"

int main(void)
{
    // get_statistic("bubble_worst_results.txt", 0, gen_worst);
    // get_statistic("bubble_random_results.txt", 0, gen_random);
    // get_statistic("bubble_best_results.txt", 0, gen_best);

    // get_statistic("insertion_worst_results.txt", 1, gen_worst);
    // get_statistic("insertion_random_results.txt", 1, gen_random);
    // get_statistic("insertion_best_results.txt", 1, gen_best);

    get_statistic("quick_worst_results.txt", 2, gen_worst);
    get_statistic("quick_random_results.txt", 2, gen_random);
    get_statistic("quick_best_results.txt", 2, gen_best);

    return EXIT_SUCCESS;
}