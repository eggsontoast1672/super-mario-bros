#include "player.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

static SDL_Texture *texture;
static SDL_Rect rect = {100, 100, 100, 100};

void smb_player_draw(SDL_Renderer *renderer)
{
    if (SDL_RenderCopy(renderer, texture, NULL, &rect) < 0) {
        fprintf(stderr, "Failed to copy texture to backbuffer: %s\n", SDL_GetError());
        exit(1);
    }
}

void smb_player_load(SDL_Renderer *renderer)
{
    texture = IMG_LoadTexture(renderer, "../images/mario.png");
}

void smb_player_unload(void)
{
    SDL_DestroyTexture(texture);
}

void smb_player_update(void)
{
}
