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
    gorilla->menu.texture = sfTexture_createFromFile("media/Olympic.jpg", NULL);
    sfSprite_setTexture(gorilla->menu.sprite, gorilla->menu.texture, sfTrue);
}

int main(int argc, char **argv)
{
    menuuu();
}

int menuuu(void)
{
    gorilla_t gorilla;
    sfVideoMode mode = {1920, 1080, 64};
    gorilla.window = sfRenderWindow_create(mode, "MY_GORLILA", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(gorilla.window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(gorilla.window, 12);
    sfEvent event;
    init_bg(&gorilla);
    gorilla.menu.corde = false;
    gorilla.menu.fitness = false;
    while (sfRenderWindow_isOpen(gorilla.window)) {
        sfRenderWindow_clear(gorilla.window, sfBlack);
        while (sfRenderWindow_pollEvent(gorilla.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(gorilla.window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                gorilla.menu.texture = sfTexture_createFromFile("media/UnderlineCorde.png", NULL);
                sfSprite_setTexture(gorilla.menu.sprite, gorilla.menu.texture, sfTrue);
                gorilla.menu.fitness = false;
                gorilla.menu.corde = true;
            }
            if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                gorilla.menu.texture = sfTexture_createFromFile("media/UnderlineFitness.png", NULL);
                sfSprite_setTexture(gorilla.menu.sprite, gorilla.menu.texture, sfTrue);
                gorilla.menu.corde = false;
                gorilla.menu.fitness = true;
            }
            if (gorilla.menu.corde == true) {
                if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                    corde(&gorilla);
                }
            }
            if (gorilla.menu.fitness == true){
                if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                    gorilla.menu.gamemode = strdup("fitness");
                    fitness(&gorilla);
                }
            }

        }
        sfRenderWindow_drawSprite(gorilla.window, gorilla.menu.sprite, NULL);
        sfRenderWindow_display(gorilla.window);
    }
    return 0;
}