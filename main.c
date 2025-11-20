/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** A function that test our code.
*/
#include "my.h"

int main(void)
{
    sfRenderWindow *window = create_window();

    if (window == NULL)
        return 84;

    menu_loop(window);
    game_loop(window);
    
    sfRenderWindow_destroy(window);
    return 0;
}