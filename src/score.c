/*
** EPITECH PROJECT, 2025
** score.c
** File description:
** A function that add the score.
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

sfText *init_score(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){10, 10});
    return text;
}

void maj_score(sfRenderWindow* win, sfText *text, char *str, int len)
{
    str[len] = '\0';
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
}

void display_score(sfRenderWindow *win, sfText *text, int score)
{
    char str[50] = "Score : ";
    int len = 8;
    int tmp = score;
    char num[12];
    int i = 0;

    if (tmp == 0) {
    num[i] = '0';
    i = i + 1;
    }
    while (tmp > 0) {
    num[i] = (tmp % 10) + '0';
    i = i + 1;
    tmp = tmp / 10;
    }
    for (int j = i - 1; j >= 0; j = j - 1) {
    str[len] = num[j];
    len = len + 1;
    }
    maj_score(win, text, str, len);
}

void check_bird_click(sfVector2i mouse, bird_t *b, sfSound *sound, int *score)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(b->sprite);

    if (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y)) {
        sfSound_play(sound);
        (*score)++;
        b->pos.x = -110;
        sfSprite_setPosition(b->sprite, b->pos);
    }
}
