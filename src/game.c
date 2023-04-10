#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ground.h"
#include "player.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

static SDL_Window *window;
static SDL_Renderer *renderer;

static int running = 1;

void smb_game_draw(void)
{
    if (SDL_RenderClear(renderer) < 0) {
        fprintf(stderr, "Failed to clear renderer backbuffer: %s\n", SDL_GetError());
        exit(1);
    }
    smb_ground_draw(renderer);
    smb_player_draw(renderer);
    SDL_RenderPresent(renderer);
}

void smb_game_initialize(void)
{
    int img_init_flags = IMG_INIT_PNG;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    if (IMG_Init(img_init_flags) != img_init_flags) {
        fprintf(stderr, "Failed to initialize SDL image: %s\n", IMG_GetError());
        SDL_Quit();
        exit(1);
    }
    window = SDL_CreateWindow("Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        IMG_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        SDL_Quit();
        IMG_Quit();
        SDL_DestroyWindow(window);
        exit(1);
    }
    smb_game_load();
}

int smb_game_is_running(void)
{
    return running;
}

void smb_game_load(void)
{
    smb_player_load(renderer);
    smb_ground_load(renderer);
}

void smb_game_quit(void)
{
    smb_game_unload();
    smb_ground_unload();
    SDL_Quit();
    IMG_Quit();
}

void smb_game_unload(void)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    smb_player_unload();
}

void smb_game_update(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = 0;
        }
    }
}
