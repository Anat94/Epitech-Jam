/*
** EPITECH PROJECT, 2021
** install_repo
** File description:    1350
** main.c
*/

#include "gorilla.h"
#include <string.h>
#include <time.h>

void create_sprite2(gorilla_t *gorilla) {
    gorilla->gorille.sprite = sfSprite_create();
    gorilla->gorille.texture = sfTexture_createFromFile("media/fitness.png", NULL);
    gorilla->gorille.position = (sfVector2f){1920.0/2.0 - 250.0, 500};
    gorilla->gorille.rect = (sfIntRect){0, 0, 360, 360};
    sfSprite_setTexture(gorilla->gorille.sprite, gorilla->gorille.texture, sfTrue);
    sfSprite_setPosition(gorilla->gorille.sprite, gorilla->gorille.position);
    sfSprite_setTextureRect(gorilla->gorille.sprite, gorilla->gorille.rect);
}

void create_bg2(gorilla_t *gorilla) {
    gorilla->bg.sprite = sfSprite_create();
    gorilla->bg.texture = sfTexture_createFromFile("media/antarctique.jpg", NULL);
    gorilla->bg.scale = (sfVector2f){1.875, 1.40625};
    sfSprite_setTexture(gorilla->bg.sprite, gorilla->bg.texture, sfTrue);
    sfSprite_setScale(gorilla->bg.sprite, gorilla->bg.scale);
}

void move_rect2(gorilla_t *gorilla)
{
    if (gorilla->is_jumping == true) {
        if (gorilla->gorille.rect.left >= 5750)
            gorilla->gorille.rect.left = 0;
        else
            gorilla->gorille.rect.left += 360;
        sfSprite_setTextureRect(gorilla->gorille.sprite, gorilla->gorille.rect);
    } else
        gorilla->gorille.rect.left = 0;
}

void create_text2(gorilla_t *gorilla)
{
    gorilla->quote.text = sfText_create();
    gorilla->quote.position = (sfVector2f){150, 50};
    sfText_setPosition(gorilla->quote.text, gorilla->quote.position);
    sfFont *F_score = sfFont_createFromFile("media/Fonts/Candy_Beans.otf");
    sfText_setFont(gorilla->quote.text, F_score);
    sfText_setCharacterSize(gorilla->quote.text, 25);
}

float random_pos_bar2(bar_t *bar)
{
    return (rand() % (397 - (int)bar->rect_size.x)) + (1920/2-193);
}

void new_round2(bar_t *bar, int round) {
    bar->rect_size.x = 100 - (round * 15);
    bar->rect_pos.x = random_pos_bar2(bar);
    sfRectangleShape_setSize(bar->rectangle, bar->rect_size);
    sfRectangleShape_setPosition(bar->rectangle, bar->rect_pos);
}


int fitness(gorilla_t *gorilla)
{
    sfEvent event;
    gorilla->over = false;
    gorilla->win = false;
    gorilla->pause = false;
    gorilla->score = 0;
    gorilla->clock = sfClock_create();
    gorilla->is_jumping = false;
    sfClock *clock_wait = sfClock_create();


/*------------------------------BAR----------------------------------------------*/
    bar_t *bar = malloc(sizeof(bar_t));

    bar->sprite = sfSprite_create();
    bar->texture = sfTexture_createFromFile("media/BAR_vide.png", NULL);
    bar->rectangle = sfRectangleShape_create();
    bar->rect_size.x = 100;
    bar->rect_size.y = 63;
    bar->pos.x = (1920/2-(200));
    bar->pos.y = 900;
    sfVector2f scale = {0.5, 0.5};
    bar->rect_pos.x = random_pos_bar2(bar);
    bar->rect_pos.y = 907;

    sfRectangleShape_setSize(bar->rectangle, bar->rect_size);
    sfRectangleShape_setFillColor(bar->rectangle, sfGreen);
    sfRectangleShape_setPosition(bar->rectangle, bar->rect_pos);
    sfSprite_setPosition(bar->sprite, bar->pos);
    sfSprite_setScale(bar->sprite, scale);
    sfSprite_setTexture(bar->sprite, bar->texture, sfFalse);
/*-------------------------------------------------------------------------------*/

//---------------------------Create cursor---------------------------------------
    gorilla->cursor.sprite = sfSprite_create();
    gorilla->cursor.texture = sfTexture_createFromFile("media/BarreMillieu.png", NULL);
    gorilla->cursor.rectangle = sfRectangleShape_create();
    gorilla->cursor.position = (sfVector2f){774, bar->rect_pos.y};
    gorilla->cursor.size = (sfVector2f){5.0, 63.0};
    sfRectangleShape_setPosition(gorilla->cursor.rectangle, gorilla->cursor.position);
    sfRectangleShape_setFillColor(gorilla->cursor.rectangle, sfBlack);
    sfRectangleShape_setPosition(gorilla->cursor.rectangle, gorilla->cursor.position);
    sfRectangleShape_setSize(gorilla->cursor.rectangle, gorilla->cursor.size);
    sfSprite_setTexture(gorilla->cursor.sprite, gorilla->cursor.texture, sfFalse);

//-------------------------------------------------------------------------------
    create_sprite2(gorilla);
    create_bg2(gorilla);
    create_text2(gorilla);
    srand(time(NULL));
    int i = rand() % 15;
    init_bdd(gorilla);
    char *str = " ";
    gorilla->fond = sfMusic_createFromFile("media/Music/music_bg.ogg");
    sfMusic_play(gorilla->fond);
    sfMusic_setLoop(gorilla->fond, true);
    gorilla->hurt = sfMusic_createFromFile("media/Music/classic_hurt.ogg");
    sfMusic *win_sound = sfMusic_createFromFile("media/Music/jecodeaveclecul.ogg");

    bool aller = true;
    gorilla->clock = sfClock_create();

    while (sfRenderWindow_isOpen(gorilla->window)) {
        sfRenderWindow_clear(gorilla->window, sfBlack);
        while (sfRenderWindow_pollEvent(gorilla->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfMusic_destroy(gorilla->fond);
                sfMusic_destroy(gorilla->hurt);
                sfRenderWindow_close(gorilla->window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyP)) {
                gorilla->pause = true;
            }
            if (sfKeyboard_isKeyPressed(sfKeyN)) {
                gorilla->pause = false;
            }

            if (sfKeyboard_isKeyPressed(sfKeySpace) || (event.type == sfEvtJoystickButtonPressed)) {
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(gorilla->clock)) > 1) {
                    if ((((gorilla->cursor.position.x + gorilla->cursor.size.x) >= bar->rect_pos.x) && ((gorilla->cursor.position.x + gorilla->cursor.size.x) <= (bar->rect_pos.x + bar->rect_size.x))) && gorilla->is_jumping != true) {
                        new_round2(bar, gorilla->score);
                        gorilla->is_jumping = true;
                        gorilla->score++;
                        str = gorilla->quote_bdd[i];
                        if (strlen(str) > 75)
                            sfText_setCharacterSize(gorilla->quote.text, 25);
                        else
                            sfText_setCharacterSize(gorilla->quote.text, 50);

                        if (i == 23)
                            i = 0;
                        else
                            i++;
                        sfText_setString(gorilla->quote.text, str);
                        printf("JE RENTRE DANS LE IF\n");
                        sfClock_restart(clock_wait);
                    } else {
                        sfMusic_stop(gorilla->hurt);
                        sfMusic_play(gorilla->hurt);
                        printf("JE RENTRE DANS LE ELSE\n");
                    }
                    sfClock_restart(gorilla->clock);
                }
            }
        }
        if (gorilla->pause == false && gorilla->win == false && gorilla->over == false) {
            sfRenderWindow_drawSprite(gorilla->window, gorilla->bg.sprite, NULL);
            sfRenderWindow_drawSprite(gorilla->window, bar->sprite, NULL);
            sfRenderWindow_drawSprite(gorilla->window, gorilla->gorille.sprite, NULL);
            sfRenderWindow_drawRectangleShape(gorilla->window, bar->rectangle, NULL);
            sfRenderWindow_drawRectangleShape(gorilla->window, gorilla->cursor.rectangle, NULL);
            sfRenderWindow_drawText(gorilla->window, gorilla->quote.text, NULL);
            if (sfTime_asSeconds(sfClock_getElapsedTime(clock_wait)) > 2.7) {
                gorilla->is_jumping = false;
            }
            move_rect2(gorilla);
            if (bar->rect_size.x <= 5){
                gorilla->win = true;
            }
            if (gorilla->cursor.position.x > 1143)
                aller = false;
            if (gorilla->cursor.position.x <= 774)
                aller = true;
            if (aller == true)
                gorilla->cursor.position.x += 10;
            else
                gorilla->cursor.position.x -= 10;
            sfRectangleShape_setPosition(gorilla->cursor.rectangle, gorilla->cursor.position);
            sfRenderWindow_display(gorilla->window);
        }
    }
    return 0;
}
