/*
** EPITECH PROJECT, 2025
** game_loop.c
** File description:
** A function that handle  the game.
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include "my.h"

void draw(sfRenderWindow *w, bird_t *b, sfSprite *bg)
{
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, bg, NULL);
    sfRenderWindow_drawSprite(w, b->sprite, NULL);
}

static void init_background(sfSprite **bg_sprite, sfTexture **bg_texture)
{
    sfVector2f scale = {2, 2};

    *bg_texture = sfTexture_createFromFile("./images/bg.png", NULL);
    *bg_sprite = sfSprite_create();
    sfSprite_setTexture(*bg_sprite, *bg_texture, sfTrue);
    sfSprite_setScale(*bg_sprite, scale);
}

static void init_game_objects(bird_t **bird, sfClock **clock,
    sfText **score_text, sfSound **hit_sound)
{
    sfFont *font = sfFont_createFromFile("./fonts/letter.ttf");

    *bird = create_bird("./images/bird.png");
    *clock = sfClock_create();
    *score_text = init_score(font);
    *hit_sound = load_sound("./sounds/sound.mp3");
}

static void handle_events2(sfRenderWindow *window, bird_t *bird,
    sfSound *hit_sound, int *score)
{
    sfEvent e;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        if (e.type == sfEvtMouseButtonPressed
            && e.mouseButton.button == sfMouseLeft) {
                check_bird_click(mouse, bird, hit_sound, score);
        }
    }
}

void cleanup_audio(sfSound *hit_sound, sfMusic *music)
{
    sfSound_destroy(hit_sound);
    sfMusic_destroy(music);
}

void game_loop(sfRenderWindow *window)
{
    bird_t *bird;
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
    sfText *score_text;
    sfSound *hit_sound;
    sfClock *clock;
    int score = 0;
    sfMusic *music = load_music("./sounds/music.mp3");

    init_background(&bg_sprite, &bg_texture);
    init_game_objects(&bird, &clock, &score_text, &hit_sound);
    while (sfRenderWindow_isOpen(window)) {
        handle_events2(window, bird, hit_sound, &score);
        move_bird(bird);
        animate_bird(bird, clock);
        draw(window, bird, bg_sprite);
        display_score(window, score_text, score);
        sfRenderWindow_display(window);
    }
        cleanup_audio(hit_sound, music);
}
