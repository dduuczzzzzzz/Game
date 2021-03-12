#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "CommonFunc.h"
#include "GameBase.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


class Enemy : public GameBase
{
public:
    Enemy();
    ~Enemy();

    bool loadIMG(std::string path, SDL_Renderer* screen);
    void Show_enemy(SDL_Renderer* des);
    void set_clips_enemy();
    void Move();
    int getPos_X();
    int getPos_Y();

private:
    float x_value;
    float y_value;

    float x_birds_pos_;
    float y_birds_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy_frame_clips[5];

    int frame_num;
};


#endif // ENEMY_H_INCLUDED