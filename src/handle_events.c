/*
** EPITECH PROJECT, 2025
** handle_events.c
** File description:
** A function that handle_events.c
*/
#include <SFML/Graphics.h>
#include "my.h"

void handle_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
