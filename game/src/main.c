#include "game.h"

int main(void)
{
    smb_game_initialize();

    while (smb_game_is_running()) {
        smb_game_update();
        smb_game_draw();
    }

    smb_game_quit();

    return 0;
}
