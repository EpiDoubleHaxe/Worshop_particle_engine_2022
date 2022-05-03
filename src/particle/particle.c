/*
** EPITECH PROJECT, 2022
** particle_engine
** File description:
** particle
*/

#include "linked_list.h"
#include "particle.h"
#include "game.h"
#include <stdlib.h>

int create_particle(game_t *game)
{
    particle_t *particle = malloc(sizeof(particle));

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile("assets/rond_blanc.png", NULL);
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f){.x = 500, .y = 500});
    sfSprite_setPosition(particle->sprite, particle->pos);
    add_end_node(particle, &(game->particles));
    return 0;
}

int update_particle(game_t *game)
{
    particle_t *particle = game->particles->data;
    linked_list_t *index = game->particles;

    while (index != NULL) {
        particle = index->data;
        particle->pos.x += (rand() % 3) - 2;
        particle->pos.y += (rand() % 3) - 2;
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
    }
    return 0;
}

int draw_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->particles;

    while (index != NULL) {
        particle = index->data;
        sfRenderWindow_drawSprite(game->window, particle->sprite, NULL);
        index = index->next;
    }
    return 0;
}

int destroy_particles(linked_list_t *list)
{
    return 0;
}
