/*
** EPITECH PROJECT, 2021
** Epitech-Jam
** File description:
** PROJETDEMERDE.h
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct gorille_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
}gorille_sprite_t;

typedef struct bg_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} bg_sprite_t;

typedef struct gorilla_s {
    char **quote;
    sfRenderWindow *window;
    sfClock *clock;
    int score;
    sfBool over;
    sfBool win;
    sfBool pause;
    sfText *level;
    sfMusic *fond;
    gorille_sprite_t gorille;
    bg_sprite_t bg;
} gorilla_t;
