/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** A function that test our code.
*/
#include "my.h"

int help_option(void)
{
    my_putstr("my_hunter - Game inspired by Dunk Hunt!\n");
    my_putstr("Objective: shoot the duck that appear to earn points.\n");
    my_putstr("\nUsage: ./my_hunter [options]\n");
    my_putstr("Available options:\n");
    my_putstr("  -h       Display this help message and exit the program\n");
    my_putstr("\nGame controls:\n");
    my_putstr("  Left click   Shoot the duck\n");
    my_putstr("\nCatch the duck and beat your high score!\n");
    return 0;
}

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window();

    if (ac > 1 && my_strcmp(av[1], "-h") == 0)
        return help_option();
    if (window == NULL)
        return 84;
    menu_loop(window);
    game_loop(window);
    sfRenderWindow_destroy(window);
    return 0;
}
