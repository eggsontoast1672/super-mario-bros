#include "ground.h"

#include <SDL2/SDL_image.h>

#include "consts.h"

const int GROUND_SIZE = 100;

SDL_Texture *ground_texture;

void smb_ground_load(SDL_Renderer *renderer) {
    ground_texture = IMG_LoadTexture(renderer, "../images/ground.png");
}

int smb_ground_draw(SDL_Renderer *renderer) {
    int x, result;
    SDL_Rect ground_rect;

    for (x = 0; x < SCREEN_WIDTH; x += GROUND_SIZE) {
        ground_rect.x = x;
        ground_rect.y = SCREEN_HEIGHT - GROUND_SIZE;
        ground_rect.w = GROUND_SIZE;
        ground_rect.h = GROUND_SIZE;
        result = SDL_RenderCopy(renderer, ground_texture, NULL, &ground_rect);
    }
    return result;
}

void smb_ground_unload(void) {
    SDL_DestroyTexture(ground_texture);
}
