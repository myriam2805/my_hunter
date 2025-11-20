/*
** EPITECH PROJECT, 2025
** music.c
** File description:
** A function that handle the music.
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"

sfMusic *load_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}
