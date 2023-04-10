#ifndef SMB_PLAYER_H
#define SMB_PLAYER_H

#include <SDL2/SDL.h>

void smb_player_draw(SDL_Renderer *renderer);
void smb_player_load(SDL_Renderer *renderer);
void smb_player_unload(void);
void smb_player_update(void);

#endif
