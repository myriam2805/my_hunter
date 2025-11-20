/*
** EPITECH PROJECT, 2025
** handle_bird.c
** File description:
** A function that handle the bird.
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

bird_t *create_bird(char *filepath)
{
    bird_t *b = malloc(sizeof(bird_t));

    b->texture = sfTexture_createFromFile("./images/bird.png", NULL);
    b->sprite = sfSprite_create();
    b->rect = (sfIntRect){0, 0, 110, 110};
    b->pos = (sfVector2f){0, 200};
    b->speed = 1;

    sfSprite_setTexture(b->sprite, b->texture, sfTrue);
    sfSprite_setTextureRect(b->sprite, b->rect);
    return b;
}

void move_bird(bird_t *b)
{
    b->pos.x += b->speed;
    if (b->pos.x > 800)
        b->pos.x = -110;
    sfSprite_setPosition(b->sprite, b->pos);
}

void animate_bird(bird_t *b, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_restart(clock)) > 0.1)
        b->rect.left += 110;
    if (b->rect.left >= 330)
        b->rect.left = 0;
    sfSprite_setTextureRect(b->sprite, b->rect);
}


