/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** A function that compares two strings.
*/
#include "my.h"

int my_strcmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}
