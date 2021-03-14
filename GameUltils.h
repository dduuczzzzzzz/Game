#ifndef GAMEULTILS_H_INCLUDED
#define GAMEULTILS_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"

bool check_collision(MainObject p_player, Enemy enemy_, onGroundEnemy enemy2_);
//bool check_coolide(MainObject p_player, Enemy enemy_, onGroundEnemy enemy2_);


#endif // GAMEULTILS_H_INCLUDED
