/*
** EPITECH PROJECT, 2025
** handle_events.
** File description:
** A function that handle events.
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include "my.h"

sfText *score_text = NULL;

void draw(sfRenderWindow *w, bird_t *b, sfSprite *bg)
{
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, bg, NULL);
    sfRenderWindow_drawSprite(w, b->sprite, NULL);

    if (score_text)
        display_score(w, score_text);

    sfRenderWindow_display(w);
}

void game_loop(sfRenderWindow *window)
{
    sfMusic *music = load_music("./sounds/music.mp3");
    bird_t *bird = create_bird("./images/bird.png");
    sfClock *clock = sfClock_create();
    sfEvent e;

    sfVector2f scale = {2, 2};
    sfTexture *bg_texture = sfTexture_createFromFile("./images/bg.png", NULL);
    sfSprite *bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, sfTrue);
    sfSprite_setScale(bg_sprite, scale);

    sfFont *font = sfFont_createFromFile("./fonts/letter.ttf");
    score_text = init_score(font);

    sfSound *hit_sound = load_sound("./sounds/sound.mp3");

    sfRenderWindow_setFramerateLimit(window, 300);

    while (sfRenderWindow_isOpen(window)) {

        while (sfRenderWindow_pollEvent(window, &e)) {
            if (e.type == sfEvtClosed)
                sfRenderWindow_close(window);

            if (e.type == sfEvtMouseButtonPressed &&
                e.mouseButton.button == sfMouseLeft) {

                sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
                check_bird_click(mouse, bird, hit_sound);  
            }
        }
        move_bird(bird);
        animate_bird(bird, clock);
        draw(window, bird, bg_sprite);
    }

    sfSound_destroy(hit_sound);
    sfMusic_destroy(music);
}
