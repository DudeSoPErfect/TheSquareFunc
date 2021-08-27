
#ifndef UNTITLED_SQUARE_H
#define UNTITLED_SQUARE_H

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

int solving_the_line(float a, float b, float *x_1);

int solving_the_square(float a, float b, float c, float *x_1, float *x_2);

int printing(int num_of_roots, float x_1, float x_2);

#endif //UNTITLED_SQUARE_H
