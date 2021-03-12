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
    int right_dino = dino.getPos__X() + 81;
    int top_dino = dino.getPos__Y();
    int bot_dino = dino.getPos__Y() + 51;

    if (right_player >= left_dino && left_player <= right_dino)
		{
			if (bot_player  >= top_dino)
			{
				collide = true;
			}
		}
		return collide;
}
