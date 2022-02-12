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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

typedef struct bar_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfVector2f rect_size;
    sfVector2f rect_pos;
}bar_t;

typedef struct cursor_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rectangle;
    sfVector2f position;
    sfVector2f size;
} cursor_t;

typedef struct quote_s{
    char *str;
    sfText *text;
    sfVector2f position;

} quote_t;

typedef struct gorilla_s {
    sfRenderWindow *window;
    sfClock *clock;
    int score;
    sfBool over;
    sfBool win;
    sfBool pause;
    sfMusic *fond;
    sfMusic *hurt;
    gorille_sprite_t gorille;
    bg_sprite_t bg;
    quote_t quote;
    cursor_t cursor;
    char **quote_bdd;
} gorilla_t;


int call_API(void);
void init_bdd(gorilla_t *gorilla);
