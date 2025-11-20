/*
** EPITECH PROJECT, 2025
** window.c
** File description:
** A function that open a window and displays an image.
*/
#include "my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {550, 300, 32};

    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My Hunter", sfResize | sfClose, NULL);
    return window;
}
