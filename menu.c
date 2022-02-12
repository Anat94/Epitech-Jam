/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu.c
*/

#include "gorilla.h"
#include <string.h>
#include <time.h>

void init_bg(gorilla_t *gorilla)
{
    gorilla->menu.sprite = sfSprite_create();
    gorilla->menu.texture = sfTexture_createFromFile("media/Background.png", NULL);
    sfSprite_setTexture(gorilla->bg.sprite, gorilla->bg.texture, sfTrue);
}

int main(int argc, char **argv)
{
    gorilla_t gorilla;
    sfVideoMode mode = {1920, 1080, 64};
    gorilla.window = sfRenderWindow_create(mode, "MY_GORLILA", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(gorilla.window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(gorilla.window, 12);
    sfEvent event;
    init_bg(&gorilla);
    while (sfRenderWindow_isOpen(gorilla.window)) {
        sfRenderWindow_clear(gorilla.window, sfBlack);
        while (sfRenderWindow_pollEvent(gorilla.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfMusic_destroy(gorilla.fond);
                sfMusic_destroy(gorilla.hurt);
                sfRenderWindow_close(gorilla.window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyP)) {
                gorilla.pause = true;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN)) {
                gorilla.pause = false;
            }
        }
        sfRenderWindow_drawSprite(gorilla.window, gorilla.menu.sprite, NULL);
    }
    return 0;
}