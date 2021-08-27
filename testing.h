/*
    \file Заголовочный файл для обьявления функций, которые используются в testing.cpp.
 */
struct DataForTesting_t;

enum {
    OK = 0,
    SQUARE_ZERO_ROOTS,
    SQUARE_ONE_ROOT,
    SQUARE_TWO_ROOTS,
    LINEAR_ZERO_ROOTS,
    LINEAR_ONE_ROOT,
    LINEAR_INF_ROOTS
} Errors;


bool is_zero(float u);

void placing_the_vars(int num_of_roots);

int solving_the_square(float a, float b, float c, float *x_1, float *x_2);

