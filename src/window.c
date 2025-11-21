/*
** EPITECH PROJECT, 2025
** window.c
** File description:
** A function that open a window and displays an image.
*/
#include "my.h"
#include <math.h>

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1100, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(
    mode, "My Hunter", sfResize | sfClose, NULL);

    return window;
}
