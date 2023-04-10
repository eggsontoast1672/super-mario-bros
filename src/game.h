#ifndef SMB_GAME_H
#define SMB_GAME_H

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

void smb_game_draw(void);
void smb_game_initialize(void);
int smb_game_is_running(void);
void smb_game_load(void);
void smb_game_quit(void);
void smb_game_unload(void);
void smb_game_update(void);

#endif
