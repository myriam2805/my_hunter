/*
** EPITECH PROJECT, 2025
** sound.c
** File description:
** A function that handle the sound.
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"

sfSound *load_sound(char *filepath)
{
    sfSoundBuffer *buf = sfSoundBuffer_createFromFile(filepath);

    if (!buf)
        return NULL;

    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buf);
    return sound;
}
