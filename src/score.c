/*
** EPITECH PROJECT, 2025
** score.c
** File description:
** A function that add the score.
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

int score = 0;

sfText *init_score(sfFont *font)
{
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){10, 10});
    return text;
}

void display_score(sfRenderWindow *win, sfText *text)
{
    char str[50];
    int tmp = score;
    int i = 0;

    str[0] = 'S'; str[1] = 'c'; str[2] = 'o'; str[3] = 'r'; str[4] = 'e'; str[5] = ' '; str[6] = ':'; str[7] = ' '; i = 8;
    if (tmp == 0)
        str[i++] = '0';
    while (tmp > 0) {
        str[i++] = '0' + tmp % 10;
        tmp /= 10;
    }
    str[i] = '\0';
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
}

void check_bird_click(sfVector2i mouse, bird_t *b)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(b->sprite);
    if (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y)) {
        score++;
        b->pos.x = -110;
        sfSprite_setPosition(b->sprite, b->pos);
    }
}
