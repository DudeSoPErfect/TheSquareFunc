#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "square.h"
#include "testing.h"

int main()
{
    float a = 0, b = 0, c = 0, x_1 = 0, x_2 = 0;
    testing();

    if (3 == scanf("%f %f %f", &a, &b, &c))
    {
        int nroots = solving_the_square(a, b, c, &x_1, &x_2);
        printing(nroots, x_1, x_2);

        return 0;
    }
    else
    {
        printf("Wrong input data\n");
        return -1;
    }
}

