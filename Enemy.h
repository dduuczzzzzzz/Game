#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "CommonFunc.h"
#include "GameBase.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#define UP 2
#define DOWN 1


class Enemy : public GameBase
{
public:
    Enemy();
    ~Enemy();

    bool loadIMG2(std::string path, SDL_Renderer* screen);
    void Show_enemy(SDL_Renderer* des);
    void set_clips_enemy();
    void Move();
    int getPos_X();
    int getPos_Y();
    void Pause1();
    void harder(Uint32 time_);
    void increase_speed(Uint32 time_);
    void Set_default_enemy1();

private:
    float x_value;
    float y_value;

    float x_birds_pos_;
    float y_birds_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy_frame_clips[5];

    int frame_num;
    bool pause;
    int enemy_speed ;
    int status;
    float up_down_speed;

};


#endif // ENEMY_H_INCLUDED
