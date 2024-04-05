/*
** EPITECH PROJECT, 2024
** Mathématics
** File description:
** 107transfer
*/

#include "../include/my.h"

int man_help(void)
{
    printf("USAGE\n");
    printf("\t\t./107transfer [num den]*\n");
    printf("DESCRIPTION\n");
    printf("\t\tnum\tpolynomial numerator defined by its coefficients\n");
    printf("\t\tden\tpolynomial denominator defined by its coefficients\n");
    return 0;
}

int validate_coefficient(char **av, int ac)
{
    int position_begin;
    int position_end;
    char *buffer;
    char *coefficient;

    for (int i = 1; i < ac; i++) {
        coefficient = av[i];
        position_begin = strlen(coefficient) - 1;
        position_end = position_begin;
        while (position_begin >= 0) {
            position_end = position_begin;
            for (; position_begin >= 0 && coefficient[position_begin] != '*'; position_begin--);
            position_begin++;
            buffer = strdup(coefficient + position_begin);
            buffer[position_end - position_begin + 1] = 0;
            if (!(isdigit(buffer[0]) || buffer[0] == '+' || buffer[0] == '-'))
                return 84;
            for (int i = 1; buffer[i]; i++)
                if (!isdigit(buffer[i]))
                    return 84;
            position_begin -= 2;
            if (position_begin == -1)
                return 84;
        }
    }
    return 0;
}

double evaluate_polynomial(char *polynomial, double x)
{
    int position_begin = strlen(polynomial) - 1;
    int position_end = position_begin;
    double value = 0;
    char *buffer;

    while (position_begin >= 0) {
        position_end = position_begin;
    for (; position_begin >= 0 &&
    polynomial[position_begin] != '*'; position_begin--);
        position_begin++;
        buffer = strdup(polynomial + position_begin);
        buffer[position_end - position_begin + 1] = 0;
        value *= x;
        value += atof(buffer);
        position_begin -= 2;
    }
    return value;
}

void process_coefficients(char **coefficients, int num_coefficients)
{
    double value = 0;
    double result = 1;
    double fir;
    double sec;

    for (value = 0; value < 1.001; value += 0.001) {
        for (int i = 0; i < num_coefficients; i += 2) {
            fir = evaluate_polynomial(coefficients[i], value);
            sec = evaluate_polynomial(coefficients[i + 1], value);
            result *= fir / sec;
        }
        printf("%.3f -> %.5f\n", value, result);
        result = 1;
    }
}

int valid_n_arg(int ac)
{
    if ((ac % 2) == 0 && ac != 0)
        return 0;
    else
        return 84;
}

int s_main(int ac, char **av)
{
    char **coefficients = malloc(sizeof(char *) * (ac - 1));

    if (ac == 1)
    return 84;
    if (ac == 2 && strcmp(av[1], "-h") != 0)
        return 84;
    if (ac == 2 && strcmp(av[1], "-h") != 0)
        return 84;
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return man_help();
    if (valid_n_arg(ac - 1) == 84)
        return 84;
    if (validate_coefficient(av, ac) == 84)
        return 84;
    for (int i = 0; i < (ac - 1); i++)
        coefficients[i] = strdup(av[i + 1]);
    if (coefficients == NULL)
        return 84;
    process_coefficients(coefficients, ac - 1);
    return 0;
}
