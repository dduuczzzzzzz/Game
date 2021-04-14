#ifndef GAMEULTILS_H_INCLUDED
#define GAMEULTILS_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"
#include "Lbutton.h"

void Play_button(SDL_Event *e,Lbutton &PlayButton, bool Menu, bool GameRunning);

void Hekp_button(SDL_Event *e, Lbutton &HelpButton, bool Instruct);

void Exit_button(SDL_Event *e, Lbutton &ExitButton, bool Menu);

void Render_play_button(Lbutton &PlayButton, GameBase gPlay);

#endif // GAMEULTILS_H_INCLUDED
