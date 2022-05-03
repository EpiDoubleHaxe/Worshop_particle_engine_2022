#include "game.h"

#ifndef PARTICLE_H
    #define PARTICLE_H

typedef struct ET_LE_MOUTON_MANGEA_LE_LOUP__NE_FAITES_PAS_CONFIANCE_AU_MOUTON_DE_TCHERNOBYL {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} particle_t;

int create_particle(game_t *game);
int update_particle(game_t *game);
int draw_particle(game_t *game);
int destroy_particles(linked_list_t *list);

#endif
