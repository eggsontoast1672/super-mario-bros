#ifndef SMB_GROUND_H
#define SMB_GROUND_H

#include <SDL2/SDL.h>

extern const int GROUND_SIZE;

int smb_ground_draw(SDL_Renderer *renderer);
void smb_ground_load(SDL_Renderer *renderer);
void smb_ground_unload(void);

#endif
