/*
** EPITECH PROJECT, 2023
** 106bombyx
** File description:
** 106bombyx
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <stdarg.h>
    #include <string.h>
    #include <math.h>
    #include <signal.h>
    #include <ctype.h>


int validate_coefficient(char **av, int ac);
double evaluate_polynomial(char *polynomial, double x);
void process_coefficients(char **coefficients, int num_coefficients);
int valid_n_arg(int ac);



int s_main(int argc, char *argv[]);

#endif
