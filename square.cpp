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

/*
    \brief Функция принимает значение и возвращает булевое значение,
    является ли правдой, что значение равно 0.
    \param[in] u - исходное значение.
 */

bool is_zero(float u) {
    assert(!isnan(u));
    return fabs(u) < EPS;

}

/*
    \brief Функция для решения частного случая квадратных уравнений, а именно: линейных.
    \details Принимает на вход два коэффициента исходного уравнения и указатель на его корень.
    Возвращает единственное из значений "-1", "0" и "1", что соответственно означает количество
    корней исходного уравнения - "бесконечность", "ноль" или "один".
    При наличии корня, изменяет соответствующую переменную по указателю на значение вышеупомянутого корня.
    \param[out] x_1 - указатель на корень.
    \param[in] a, b - коэффициенты.
 */

int solving_the_line(float a, float b, float *x_1) {

    assert(!isnan(a));
    assert(!isnan(b));
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

/*
    \brief Функция для решения квадратного уравнения.
    \details Принимает на вход три коэффициента исходного уравнения и два указателя на его корни.
    Возвращает единственное из значений "0", "1" и "2", что соответственно означает количество
    корней исходнодного уравнения - "один", "два" или "три".
    При наличия корня/корней, изменяет соответствующую/соответствующие переменную/переменные
    по указателю на значение/значения вышеупомянутого корня/корней.
    \param[out] x_1, x_2 - указатели на корни.
    \param[in] a, b, c - коэффициенты.
 */

int solving_the_square(float a, float b, float c, float *x_1, float *x_2) {

    assert(!(isnan(a) || isnan(b) || isnan(c)));
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(!(isinf(a) || isinf(b) || isinf(c)));
    assert(x_1 != x_2);

    float D = b * b - 4 * a * c;

    if (is_zero(a)) {
        return solving_the_line(b, c, x_1);
    } else {
        if (is_zero(D)) {
            *x_1 = (b * (-1) + sqrt(D)) / (2 * a);
            return SQUARE_ONE_ROOT;
        } else if (D > 0) {
            *x_1 = (b * (-1) - sqrt(D)) / (2 * a);
            *x_2 = (b * (-1) + sqrt(D)) / (2 * a);
            return SQUARE_TWO_ROOTS;
        } else {
            //printf("No roots\n");
            *x_1 = 0;
            return SQUARE_ZERO_ROOTS;
        }
    }


}

/*
    \brief Функция для вывода количества корней и их значений.
    \details Принимает на вход количество корней и их значения.
    Выводит на экран количество корня/корней и его/их значение, в зависимости от их количества.
    \param[in] num_of_roots - количество корней. x_1, x_2 - значения корней

 */

int printing(int num_of_roots, float x_1, float x_2) {


    switch (num_of_roots) {
        case SQUARE_ZERO_ROOTS:
            printf("Square, no roots\n");
            break;
        case SQUARE_ONE_ROOT:
            printf("Square, one roots %f\n", x_1);
            break;
        case SQUARE_TWO_ROOTS:
            printf("Square, two roots %f and %f\n", x_1, x_2);
            break;
        case LINEAR_ZERO_ROOTS:
            printf("Linear, no roots\n");
            break;
        case LINEAR_ONE_ROOT:
            printf("Linear, one root %f\n", x_1);
            break;
        case LINEAR_INF_ROOTS:
            printf("Linear, infinite number of roots\n");
            break;
    }
    if (num_of_roots == 1) {
        printf("%d %f\n", num_of_roots, x_1);
    } else if (num_of_roots == 2) {
        printf("%d %f %f\n", num_of_roots, x_1, x_2);

    }
    return OK;
}
