#ifndef ONGROUNDENEMY_H_INCLUDED
#define ONGROUNDENEMY_H_INCLUDED
#include "CommonFunc.h"
#include "GameBase.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class onGroundEnemy : public GameBase
{
public:
    onGroundEnemy();
    ~onGroundEnemy();

    bool loadIMG(std::string path, SDL_Renderer* screen);
    void Show_enemy(SDL_Renderer* des);
    void set_clips_enemy();
    void Move();
    int getPos__X();
    int getPos__Y();

private:
    float x_value;
    float y_value;

    float x_cactus_pos_;
    float y_cactus_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy2_frame_clips[8];

    int frame_num;
};

#endif // ONGROUNDENEMY_H_INCLUDED
