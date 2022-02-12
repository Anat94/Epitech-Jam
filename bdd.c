/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** bdd.c
*/

#include "gorilla.h"

int init_bdd(gorilla_t *gorilla) {
    char **quote_bdd = malloc(sizeof(char *) * 25);
    quote_bdd[0] = my_strdup("One fails forward toward success.");
    quote_bdd[1] = my_strdup("When performance exceeds ambition, the overlap is called success.");
    quote_bdd[2] = my_strdup("The path to success is to take massive, determined action.");
    quote_bdd[3] = my_strdup("The secret of success is constancy to purpose.");
    quote_bdd[4] = my_strdup("Successful people ask better questions, and as a result, they get better answers.");
    quote_bdd[5] = my_strdup("Through perseverance many people win success out of what seemed destined to be certain failure.");
    quote_bdd[6] = my_strdup("Most great people have attained their greatest success just one step beyond their greatest failure.");
    quote_bdd[7] = my_strdup("It is on our failures that we base a new and different and better success.");
    quote_bdd[8] = my_strdup("Life is a succession of lessons, which must be lived to be understood.");
    quote_bdd[9] = my_strdup("A little more persistence, a little more effort, and what seemed hopeless failure may turn to glorious success.");
    quote_bdd[10] = my_strdup("Success means having the courage, the determination, and the will to become the person you believe you were meant to be.");
    quote_bdd[11] = my_strdup("Good people are good because they've come to wisdom through failure. We get very little wisdom from success, you know.";
    quote_bdd[12] = my_strdup("There is only one success to be able to spend your life in your own way.");
    quote_bdd[13] = my_strdup("Everyone can taste success when the going is easy, but few know how to taste victory when times get tough.");
    quote_bdd[14] = my_strdup("Of course there is no formula for success except perhaps an unconditional acceptance of life and what it brings.");
    quote_bdd[15] = my_strdup("Always be yourself, express yourself, have faith in yourself, do not go out and look for a successful personality and duplicate it.");
    quote_bdd[16] = my_strdup("One secret of success in life is for a man to be ready for his opportunity when it comes.");
    quote_bdd[17] = my_strdup("Many of life's failures are people who did not realize how close they were to success when they gave up.");
    quote_bdd[18] = my_strdup("I can't imagine a person becoming a success who doesn't give this game of life everything hes got.");
    quote_bdd[19] = my_strdup("The first requisite for success is the ability to apply your physical and mental energies to one problem incessantly without growing weary.");
    quote_bdd[20] = my_strdup("Try not to become a man of success, but rather try to become a man of value.");
    quote_bdd[21] = my_strdup("People of mediocre ability sometimes achieve outstanding success because they don't know when to quit. Most men succeed because they are determined to.");
    quote_bdd[22] = my_strdup("The person who lives life fully, glowing with life's energy, is the person who lives a successful life.");
    quote_bdd[23] = my_strdup("A successful person is one who can lay a firm foundation with the bricks that others throw at him or her.");
    quote_bdd[24] = NULL;
}