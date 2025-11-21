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
    char str[50] = "Score : ";
    int len = 8;
    int tmp = score;
    char num[12];
    int i = 0;

    if (tmp == 0)
        num[i++] = '0';
    while (tmp > 0) {
        num[i++] = (tmp % 10) + '0';
        tmp /= 10;
    }
    for (int j = i - 1; j >= 0; j--)
        str[len++] = num[j];
    str[len] = '\0';

    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
}

void check_bird_click(sfVector2i mouse, bird_t *b, sfSound *sound)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(b->sprite);

    if (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y)) {
        sfSound_play(sound);
        score++;
        b->pos.x = -110;
        sfSprite_setPosition(b->sprite, b->pos);
    }
}