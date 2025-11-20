/*
** EPITECH PROJECT, 2025
** handle_events.
** File description:
** A function that handle events.
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

void draw(sfRenderWindow *w, bird_t *b, sfSprite *bg)
{
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, bg, NULL);
    sfRenderWindow_drawSprite(w, b->sprite, NULL);
    sfRenderWindow_display(w);
}

void game_loop(sfRenderWindow *window)
{
    sfMusic *music = load_music("./sounds/sound.mp3");
    bird_t *bird = create_bird("./images/bird.png");
    sfClock *clock = sfClock_create();

    sfTexture *bg_texture = sfTexture_createFromFile("./images/bg.png", NULL);
    sfSprite *bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 300);

    while(sfRenderWindow_isOpen(window)) {
        handle_events(window);
        move_bird(bird);
        animate_bird(bird, clock);
        draw(window, bird, bg_sprite);
    }
    sfMusic_destroy(music);
}
