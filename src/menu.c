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
    if (m.x >= 518 && m.x <= 582 && m.y >= 268 && m.y <= 332)
        return 1;
    return 0;
}

static int handle_menu_event(sfEvent *e, sfRenderWindow *win)
{
    if (e->type == sfEvtClosed) {
        sfRenderWindow_close(win);
        return 0;
    }
    if (e->type == sfEvtMouseButtonPressed
        && e->mouseButton.button == sfMouseLeft) {
        if (click_on_start(sfMouse_getPositionRenderWindow(win)))
            return 1;
    }
    return 0;
}

int menu_loop(sfRenderWindow *win)
{
    sfTexture *t = sfTexture_createFromFile("./images/menu.png", NULL);
    sfSprite *bg = sfSprite_create();
    sfEvent e;
    sfVector2f scale = (sfVector2f){2, 2};
    int result = 0;

    sfSprite_setTexture(bg, t, sfTrue);
    sfSprite_setScale(bg, scale);
    while (sfRenderWindow_isOpen(win) && result == 0) {
        while (sfRenderWindow_pollEvent(win, &e)) {
            result = handle_menu_event(&e, win);
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, bg, NULL);
        sfRenderWindow_display(win);
    }
    return 0;
}
