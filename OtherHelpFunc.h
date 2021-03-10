#ifndef OTHERHELPFUNC_H_INCLUDED
#define OTHERHELPFUNC_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"
#include <SDL.h>

bool Init();
bool loadBackground();
void close();

void GroundScrolling(int& speed, GameBase p_ground, SDL_Renderer* ren);


#endif // OTHERHELPFUNC_H_INCLUDED
