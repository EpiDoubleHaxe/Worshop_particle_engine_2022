#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "linked_list.h"


#ifndef MY_GAME_
#define MY_GAME_

typedef struct BONJOUR_MON_CHER_AMI_LE_MOUTON_DE_TCHERNOBYL_COMMENT_VA_TU {
    sfRenderWindow *window;
    sfClock *clock;
    linked_list_t *particles;
} game_t;

#endif
