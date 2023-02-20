#ifndef ground_h
#define ground_h

#include <SDL2/SDL.h>

const extern int GROUND_SIZE;

void smb_ground_load(SDL_Renderer *);
void smb_ground_unload(void);

int smb_ground_draw(SDL_Renderer *);

#endif // ground_h
