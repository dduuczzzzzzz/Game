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
    void Move2();
    int getPos__X();
    int getPos__Y();
    void Pause2();
    void increase_speed2(Uint32 time_);
    void Set_default_enemy2();

private:
    float x_value;
    float y_value;

    float x_cactus_pos_;
    float y_cactus_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy2_frame_clips[8];

    int frame_num;
    bool pause;
    int slime_speed;
};

#endif // ONGROUNDENEMY_H_INCLUDED
