#include "my.h"
#include "game.h"
#include "particle.h"
#include <stdlib.h>
#include "time.h"

game_t *init_game()
{
    game_t *game = my_memset(sizeof(game_t), NULL);

    sfVideoMode mode = {800, 600, 32};
    game->particles = NULL;
    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    return game;
}

int destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    return 0;
}

int update_game(game_t *game)
{
    if (sfClock_getElapsedTime(game->clock).microseconds > 16000) {
        if (update_particle(game) != 0)
            return 84;
        if (draw_particle(game) != 0)
            return 84;
        if (destroy_particles(game) != 0)
            return 84;
        sfClock_restart(game->clock);
        sfRenderWindow_display(game->window);
    }
    return 0;
}

int gameloop(void)
{
    game_t *game = init_game();
    sfEvent event;

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        create_particle(game);
    }
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
                sfRenderWindow_close(game->window);
        }
        if (update_game(game) != 0)
            return 84;
    }
    return destroy_game(game);
}
