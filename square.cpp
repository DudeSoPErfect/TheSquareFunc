/*
    \file файл с функциями решения квадратного уравнения
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "square.h"

const double EPS = 1e-8;

bool is_zero(float u)
{
    assert(!isnan(u));
    return fabs(u) < EPS;
}

int solving_the_line(float a, float b, float *x_1)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(x_1 != NULL);

    if (is_zero(a)) {
        if (is_zero(b)) {
            return LINEAR_INF_ROOTS;
        } else {
            return LINEAR_ZERO_ROOTS;
        }
    }

    *x_1 = -(b / a);

    return LINEAR_ONE_ROOT;
}

int solving_the_square(float a, float b, float c, float *x_1, float *x_2)
{

    assert((isfinite(a) || isfinite(b) || isfinite(c)));
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    if (is_zero(a))
    {
        return solving_the_line(b, c, x_1);
    }
    else
    {
        float D = b * b - 4 * a * c;
        if (is_zero(D)) {
            *x_1 = (b * (-1) + sqrt(D)) / (2 * a);
            return SQUARE_ONE_ROOT;
        } else if (D > 0) {
            *x_1 = (b * (-1) - sqrt(D)) / (2 * a);
            *x_2 = (b * (-1) + sqrt(D)) / (2 * a);
            return SQUARE_TWO_ROOTS;
        } else {
            return SQUARE_ZERO_ROOTS;
        }
    }
}

void printing(int num_of_roots, float x_1, float x_2)
{

    switch (num_of_roots) {
        case SQUARE_ZERO_ROOTS:
            printf("Square, no roots\n");
            break;
        case SQUARE_ONE_ROOT:
            printf("Square, one root: %f\n", x_1);
            break;
        case SQUARE_TWO_ROOTS:
            printf("Square, two roots: %f and %f\n", x_1, x_2);
            break;
        case LINEAR_ZERO_ROOTS:
            printf("Linear, no roots\n");
            break;
        case LINEAR_ONE_ROOT:
            printf("Linear, one root: %f\n", x_1);
            break;
        case LINEAR_INF_ROOTS:
            printf("Linear, infinite number of roots\n");
            break;
        default:
            printf("Can't define the root number\n");
            break;
    }
}
