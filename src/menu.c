/*
** EPITECH PROJECT, 2025
** menu.c
** File description:
** A function that create the menu.
*/
#include <SFML/Graphics.h>
#include "my.h"

int click_on_start(sfVector2i m)
{
    if (m.x > 300 && m.x < 500 && m.y > 350 && m.y < 420)
        return 1;
    return 0;
}

int menu_loop(sfRenderWindow *win)
{
    sfTexture *t = sfTexture_createFromFile("./images/menu.png", NULL);
    sfTexture *bt = sfTexture_createFromFile("./images/button.png", NULL);
    sfSprite *bg = sfSprite_create();
    sfSprite *btn = sfSprite_create();
    sfEvent e;

    sfSprite_setTexture(bg, t, sfTrue);
    sfSprite_setTexture(btn, bt, sfTrue);
    sfSprite_setPosition(btn, (sfVector2f){400, 300});

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &e)) {
            if (e.type == sfEvtClosed)
                sfRenderWindow_close(win);
            if (e.type == sfEvtMouseButtonPressed
                && click_on_start(sfMouse_getPositionRenderWindow(win)))
                return 1;
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, bg, NULL);
        sfRenderWindow_drawSprite(win, btn, NULL);
        sfRenderWindow_display(win);
    }
    return 0;
}
