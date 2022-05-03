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
    particle_t *particle = malloc(sizeof(particle_t));

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile("assets/rond_blanc.png", NULL);
    if (particle == NULL || particle->texture == NULL || particle-> sprite ==
    NULL)
        my_null_error("Memory Error");
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f){.x = 500, .y = 500});
    particle->lifetime = 100;
    sfSprite_setPosition(particle->sprite, particle->pos);
    add_node(particle, &(game->particles));
    return 0;
}

int update_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->particles;

    if (game->particles == NULL)
        return 0;
    particle = game->particles->data;
    while (index != NULL) {
        particle = index->data;
        particle->pos.x += (rand() % 3) - 3;
        particle->pos.y += (rand() % 3) - 3;
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
    }
    particle->lifetime -= 1;
    return 0;
}

int draw_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->particles;

    if (game->particles == NULL)
        return 0;
    while (index != NULL) {
        particle = index->data;
        sfRenderWindow_drawSprite(game->window, particle->sprite, NULL);
        index = index->next;
    }
    return 0;
}

int destroy_particles(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = NULL;
    linked_list_t *prev = NULL;

    if (game == NULL)
        return 0;
    if (game->particles == NULL)
        return 0;
    while (game->particles != NULL &&
            ((particle_t *)(game->particles->data))->lifetime <= 0)
        del_first_node(&(game->particles));
    return 0;
}
