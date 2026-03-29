#include "player.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

static SDL_Texture *texture;
static SDL_FRect rect = {100, 100, 100, 100};

void smb_player_draw(SDL_Renderer *renderer)
{
    if (!SDL_RenderTexture(renderer, texture, NULL, &rect)) {
        fprintf(stderr, "Failed to copy texture to backbuffer: %s\n", SDL_GetError());
        exit(1);
    }
}

void smb_player_load(SDL_Renderer *renderer)
{
    texture = IMG_LoadTexture(renderer, ASSET_DIR "mario.png");
}

void smb_player_unload(void)
{
    SDL_DestroyTexture(texture);
}

void smb_player_update(void)
{
}
