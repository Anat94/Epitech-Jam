/*
** EPITECH PROJECT, 2021
** install_repo
** File description:
** main.c
*/

#include "gorilla.h"
#include <string.h>
#include <time.h>


void create_sprite(gorilla_t *gorilla) {
    gorilla->gorille.sprite = sfSprite_create();
    gorilla->gorille.texture = sfTexture_createFromFile("media/singe.png", NULL);
    gorilla->gorille.position = (sfVector2f){1920.0/2.0 - 65.0, 500};
    gorilla->gorille.scale = (sfVector2f){2,2};
    gorilla->gorille.rect = (sfIntRect){0, 0, 130, 180};
    sfSprite_setTexture(gorilla->gorille.sprite, gorilla->gorille.texture, sfTrue);
    sfSprite_setPosition(gorilla->gorille.sprite, gorilla->gorille.position);
    sfSprite_setScale(gorilla->gorille.sprite, gorilla->gorille.scale);
    sfSprite_setTextureRect(gorilla->gorille.sprite, gorilla->gorille.rect);
}

void create_bg(gorilla_t *gorilla) {
    gorilla->bg.sprite = sfSprite_create();
    gorilla->bg.texture = sfTexture_createFromFile("media/Background.png", NULL);
    gorilla->bg.scale = (sfVector2f){0.64, 0.54};
    sfSprite_setTexture(gorilla->bg.sprite, gorilla->bg.texture, sfTrue);
    sfSprite_setScale(gorilla->bg.sprite, gorilla->bg.scale);
}

void move_rect(gorilla_t *gorilla)
{
    if (gorilla->gorille.rect.left >= 1430)
        gorilla->gorille.rect.left = 0;
    else
        gorilla->gorille.rect.left = gorilla->gorille.rect.left + 130;
    sfSprite_setTextureRect(gorilla->gorille.sprite, gorilla->gorille.rect);
}

void create_text(gorilla_t *gorilla)
{
    gorilla->quote.text = sfText_create();
    gorilla->quote.position = (sfVector2f){150, 50};
    sfText_setPosition(gorilla->quote.text, gorilla->quote.position);
    sfFont *F_score = sfFont_createFromFile("media/Fonts/Candy_Beans.otf");
    sfText_setFont(gorilla->quote.text, F_score);
    sfText_setCharacterSize(gorilla->quote.text, 25);
}

int main(int argc, char **argv)
{
    gorilla_t gorilla;
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 64};
    gorilla.window = sfRenderWindow_create(mode, "MY_GORLILA", sfResize | sfClose, NULL);
    sfRenderWindow_setPosition(gorilla.window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(gorilla.window, 12);
    gorilla.over = false;
    gorilla.win = false;
    gorilla.pause = false;
    gorilla.score = 0;
    gorilla.clock = sfClock_create();


    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f rectangle_size = {200, 300};
    sfRectangleShape_setSize(rectangle, rectangle_size);
    create_sprite(&gorilla);
    create_bg(&gorilla);
    create_text(&gorilla);
    srand(time(NULL));
    int i = rand() % 15;
    init_bdd(&gorilla);
    char *str = " ";
    while (sfRenderWindow_isOpen(gorilla.window)) {
        sfRenderWindow_drawRectangleShape(gorilla.window, rectangle, NULL);
        sfRenderWindow_clear(gorilla.window, sfBlack);
        while (sfRenderWindow_pollEvent(gorilla.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(gorilla.window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyP)) {
                gorilla.pause = true;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN)) {
                gorilla.pause = false;
            }
        }
        if (gorilla.pause == false && gorilla.win == false && gorilla.over == false) {
            sfRenderWindow_drawSprite(gorilla.window, gorilla.bg.sprite, NULL);
            sfRenderWindow_drawSprite(gorilla.window, gorilla.gorille.sprite, NULL);
            sfRenderWindow_drawText(gorilla.window, gorilla.quote.text, NULL);
            move_rect(&gorilla);
            if (sfTime_asSeconds(sfClock_getElapsedTime(gorilla.clock)) > 1) {
                str = gorilla.quote_bdd[i];
                if (strlen(str) > 75)
                    sfText_setCharacterSize(gorilla.quote.text, 25);
                else
                    sfText_setCharacterSize(gorilla.quote.text, 50);

                if (i == 23)
                    i = 0;
                else
                    i++;
                sfText_setString(gorilla.quote.text, str);
                sfClock_restart(gorilla.clock);
            }
            sfRenderWindow_display(gorilla.window);
        }
    }
    return 0;
}
