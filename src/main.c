#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "consts.h"
#include "ground.h"

int quit = 0;

SDL_Rect mario_rect = {100, 100, 100, 100};
SDL_Renderer *renderer;
SDL_Window *window;

SDL_Texture *mario_texture;

int smb_initialize();
void smb_load_content();
void smb_update();
void smb_draw();
void smb_quit();

int main(int argc, char *argv[]) {
  if (smb_initialize() != 0) {
    fprintf(stderr, "Failed to initialize the program. Exiting...");
    return 1;
  }

  smb_load_content();

  while (!quit) {
    smb_update();
    smb_draw();
  }

  smb_quit();

  return 0;
}

int smb_initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }

  int flags = IMG_INIT_PNG;
  if (IMG_Init(flags) != flags) {
    fprintf(
      stderr,
      "Failed to initialize specified codecs: %s\n",
      IMG_GetError()
    );
    return 1;
  }

  window = SDL_CreateWindow(
    "Mario",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  if (window == NULL) {
    fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
    return 1;
  }

  return 0;
}

void smb_load_content() {
  mario_texture = IMG_LoadTexture(renderer, "../images/mario.png");
  smb_ground_load(renderer);
}

void smb_update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = 1;
    }
  }
}

void smb_draw() {
  if (SDL_RenderClear(renderer) != 0) {
    fprintf(
      stderr,
      "Failed to clear the renderer backbuffer: %s\n",
      SDL_GetError()
    );
  }

  SDL_RenderCopy(renderer, mario_texture, NULL, &mario_rect);
  smb_ground_draw(renderer);

  SDL_RenderPresent(renderer);
}

void smb_quit() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  SDL_DestroyTexture(mario_texture);
  smb_ground_unload();

  SDL_Quit();
  IMG_Quit();
}
