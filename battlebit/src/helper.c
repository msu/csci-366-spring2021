#include <stdio.h>

void helper_print_ull(unsigned long long i) {
    unsigned long long mask = 1u;
    printf("  0 1 2 3 4 5 6 7\n");
    for (int j = 0; j < 64; ++j) {
        if (j % 8 == 0) {
            printf("%i", j / 8);
        }
        if (mask & i) {
            printf(" 1");
        } else {
            printf(" 0");
        }
        if (j % 8 == 7) {
            printf("\n");
        }
        mask = mask << 1ull;
    }
}