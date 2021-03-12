#include "GameUltils.h"

bool check_collision(MainObject player, Enemy birds, onGroundEnemy dino)
{

    const int TRASH_PIXEL_1 = 25;
    const int TRASH_PIXEL_2 = 30;
    bool collide = false;
    int left_player = player.getPosX();
    int right_player = player.getPosX() + 30;
    int top_player = player.getPosY();
    int bot_player = player.getPosY() + 45;

    int left_dino = dino.getPos__X();
    int right_dino = dino.getPos__X() + 57;
    int top_dino = dino.getPos__Y();
    int bot_dino = dino.getPos__Y() + 57;

    if (right_player - TRASH_PIXEL_1 >= left_dino && left_player + TRASH_PIXEL_1 <= right_dino)
		{
			if (bot_player - TRASH_PIXEL_2 >= top_dino)
			{
				collide = true;
			}
		}
		return collide;
}
