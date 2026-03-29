#include <SDL3/SDL.h>

#include "smbc-core/assets.hpp"
#include "smbc-core/level.hpp"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *const window = SDL_CreateWindow("Super Mario Bros. Clone", 800, 600, 0);
    SDL_Renderer *const renderer = SDL_CreateRenderer(window, nullptr);

    smbc::core::g_assets.load_all(renderer);

    smbc::core::Level level;

    level.tiles.push_back({0, 0, smbc::core::TileType::Ground});
    level.tiles.push_back({1, 0, smbc::core::TileType::Ground});
    level.tiles.push_back({2, 0, smbc::core::TileType::Ground});
    level.tiles.push_back({3, 0, smbc::core::TileType::Ground});
    level.tiles.push_back({4, 0, smbc::core::TileType::Ground});

    while (1) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                goto quit;
            }
        }

        SDL_RenderClear(renderer);

        smbc::core::render_level(level, renderer);

        SDL_RenderPresent(renderer);
    }

quit:
    SDL_Quit();
}
