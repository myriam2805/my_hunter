/*
** EPITECH PROJECT, 2025
** my header file
** File description:
** A header to connect all functions together.
*/
#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

typedef struct bird_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    float speed;
} bird_t;

sfRenderWindow *create_window(void);
int menu_loop(sfRenderWindow *window);
void game_loop(sfRenderWindow *window);
void handle_events(sfRenderWindow *window);
bird_t *create_bird(char *filepath);
void move_bird(bird_t *b);
void animate_bird(bird_t *bird, sfClock *clock);
sfSound *load_sound(char *filepath);
sfMusic *load_music(char *filepath);
int my_putstr(char const *str);
int click_on_start(sfVector2i m);
void draw(sfRenderWindow *w, bird_t *b, sfSprite *bg);
sfText *init_score(sfFont *font);
void display_score(sfRenderWindow *win, sfText *text, int score);
void check_bird_click(sfVector2i mouse, bird_t *b, sfSound *sound, int *score);
void maj_score(sfRenderWindow* win, sfText *text, char *str, int len);
int my_strcmp(char *a, char *b);
void cleanup_audio(sfSound *hit_sound, sfMusic *music);

#endif
