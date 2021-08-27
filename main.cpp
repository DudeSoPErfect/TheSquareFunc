#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "square.h"
void placing_the_vars(int num_of_roots);



int main() {
    float a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
    int num_of_roots = 0;
    placing_the_vars(num_of_roots);

    scanf("%f %f %f", &a, &b, &c);
    int nroots = solving_the_square(a, b, c, &x_1, &x_2);
    printing(nroots, x_1, x_2);

    return 0;
}

