#ifndef GAMEULTILS_H_INCLUDED
#define GAMEULTILS_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"

bool Check_collision(MainObject& p_player, Enemy &enemy_, Enemy &enemy2_);

void Text_func(std::string &a, GameBase text, TTF_Font* font, SDL_Renderer *g_screen, int x, int y);

std::string GetHSfromFile(std::string path);

void GetHighscore(std::string path, const int& score, const std::string & old_high_score);


#endif // GAMEULTILS_H_INCLUDED
