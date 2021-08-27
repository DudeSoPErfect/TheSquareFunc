/*
    \file файл со структурой для тестов и самим тестированием.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "testing.h"
/*
    \brief Переменные для подстановки
 */

const int ZERO = 0;

/*
    \brief Структура данных для тестировки корректности программы на вычисление
    количества корней и самих корней квадратного уравнения.
    Состоит из трех Коэффициентов "а", "b" и "с", количества корней и их значений.
 */

struct DataForTesting_t {
    float a;
    float b;
    float c;
    int nroots;
    float x_1;  // два поля указатели на флот, проверятся на значения 0. Сделать такие тесты. вызывать ассерт при 0.
    float x_2;
    float *s1;
    float *s2;
};

/*
    \brief Функция подставяет неизменные значения на места переменных коэффициентов
    квадратного уравнения и проверяет корректность его решения.
    \details Принимает на вход количество корней, и два корня в виде констант.
    Выводит на экран значение "ОК", за каждый пройденный, заранее составленный тест.
    При выявлении ошибки в подсчетах, выводит на экран информацию об ошибке,
    дополняя это значениями коэффициентов, тем что ожидалось получить и тем,
    что получилось в результате вычислений.
    \param[in] num_of_roots - количество корней
    \param[out]  x_1, x_2 - корни
 */

void placing_the_vars(int num_of_roots) {
    float x_1 = 0, x_2 = 0;
    DataForTesting_t arr[] = {

            {1, 2, 1, SQUARE_ONE_ROOT,   -1,   -1, &x_1, &x_2},  //один корень
            {1, 5, 6, SQUARE_TWO_ROOTS,   -3,   -2, &x_1, &x_2},  //два корня
            {2, 4, 8, SQUARE_ZERO_ROOTS,   ZERO, ZERO, &x_1, &x_2},  //нет корней
            {0, 4, 8, LINEAR_ONE_ROOT,   -2,   ZERO, &x_1, &x_2},  //один корень
            {0, 0, 8, LINEAR_ZERO_ROOTS,   ZERO, ZERO, &x_1, &x_2},   //нет корней
            {0, 0, 0, LINEAR_INF_ROOTS, ZERO, ZERO, &x_1, &x_2}     //бесконечное количество корней
    };


    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        x_1 = 0, x_2 = 0;
        num_of_roots = solving_the_square(arr[i].a, arr[i].b, arr[i].c, &x_1, &x_2);


        if (num_of_roots == arr[i].nroots) {           //проверка на соответствие количества
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
                        printf("OK\n");}

                    else {
                        printf("input: %f %f %f\n", arr[i].a, arr[i].b, arr[i].c);
                        printf("Correct number of roots. Roots expected : %f. Roots get : %f\n", x_1, arr[i].x_1);
                    }
                    break;
                case SQUARE_TWO_ROOTS:
                    if (is_zero(x_1 - arr[i].x_1) && is_zero(x_2 - arr[i].x_2))
                    {
                        printf("OK\n");}
                    else {
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

}
