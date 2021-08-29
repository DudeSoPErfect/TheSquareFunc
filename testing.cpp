/*
    \file файл со структурой для тестов и самим тестированием.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "testing.h"
#include "square.h"

/*
    \brief Переменная для подстановки при отсутствии корней или их бесконечном количестве
 */
const int BAD_VALUE = 0xBEDA;

void validation(DataForTesting_t *arr, int num_of_roots, float x_1, float x_2, int i)
{
    if (num_of_roots == arr[i].nroots)
    {                                              //проверка на соответствие количеств
        switch (num_of_roots) {                    //проверки на соответствия значений
            case LINEAR_ZERO_ROOTS:
            case LINEAR_INF_ROOTS:
            case SQUARE_ZERO_ROOTS:
                printf("OK\n");
                break;
            case LINEAR_ONE_ROOT:
            case SQUARE_ONE_ROOT:
                if (is_zero(x_1 - arr[i].x_1))
                {
                    printf("OK\n");
                }
                else
                {
                    printf("input: %f %f %f\n", arr[i].a, arr[i].b, arr[i].c);
                    printf("Correct number of roots. Roots expected : %f. Roots get : %f\n", x_1, arr[i].x_1);
                }
                break;
            case SQUARE_TWO_ROOTS:
                if (is_zero(x_1 - arr[i].x_1) && is_zero(x_2 - arr[i].x_2))
                {
                    printf("OK\n");
                }
                else
                {
                    printf("input: %f %f %f\n", arr[i].a, arr[i].b, arr[i].c);
                    printf("Correct number of roots. Roots expected: %f, %f. Roots get: %f, %f\n", x_1, x_2,
                           arr[i].x_1, arr[i].x_2);
                }
                break;
            default:
                printf("\ninvalid number of roots\n");
                break;
        }
    } else {
        printf("input: %f %f %f\n", arr[i].a, arr[i].b, arr[i].c);
        printf("Incorrect number of roots. Number of roots expected: %d. Number of roots get: %d\n", arr[i].nroots,
               num_of_roots);
    }
}

void testing()
{
    int num_of_roots = 0;
    float x_1 = 0, x_2 = 0;
    DataForTesting_t arr[] = {

            {1, 2, 1, SQUARE_ONE_ROOT,   -1,   -1, &x_1, &x_2},  //один корень
            {1, 5, 6, SQUARE_TWO_ROOTS,   -3,   -2, &x_1, &x_2},  //два корня
            {2, 4, 8, SQUARE_ZERO_ROOTS,   BAD_VALUE, BAD_VALUE, &x_1, &x_2},  //нет корней
            {0, 4, 8, LINEAR_ONE_ROOT,   -2,   BAD_VALUE, &x_1, &x_2},  //один корень
            {0, 0, 8, LINEAR_ZERO_ROOTS,   BAD_VALUE, BAD_VALUE, &x_1, &x_2},   //нет корней
            {0, 0, 0, LINEAR_INF_ROOTS, BAD_VALUE, BAD_VALUE, &x_1, &x_2}     //бесконечное количество корней
    };


    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        x_1 = 0, x_2 = 0;
        num_of_roots = solving_the_square(arr[i].a, arr[i].b, arr[i].c, &x_1, &x_2);

        validation(arr, num_of_roots, x_1, x_2, i);

    }
}
