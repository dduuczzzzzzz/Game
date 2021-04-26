#ifndef GAMEULTILS_H_INCLUDED
#define GAMEULTILS_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"

void Draw_EndGame(GameBase endgame1, GameBase endgame2, TTF_Font *font);

bool Check_collision(MainObject& p_player, Enemy &enemy_, Enemy &enemy2_);


#endif // GAMEULTILS_H_INCLUDED
