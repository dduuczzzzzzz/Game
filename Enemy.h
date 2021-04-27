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
    bool loadIMG3(std::string path, SDL_Renderer* screen);

    void Show_enemy(SDL_Renderer* des);
    void Show_enemy2(SDL_Renderer* des);

    void set_clips_enemy();
    void set_clips_enemy2();

    void Move();
    void Move2();

    int getPos_X();
    int getPos_Y();
    int getPos__X2();
    int getPos__Y2();

    void Pause1();
    void harder(int time_);
    void increase_speed(int time_);
    void Set_default_enemy1();

    void increase_speed2(int time_);

private:
    float x_value;
    float y_value;

    float x_birds_pos_;
    float y_birds_pos_;

    float x_slime_pos_;
    float y_slime_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy_frame_clips[5];
    SDL_Rect Enemy2_frame_clips[8];

    int frame_num;
    bool pause;
    int enemy_speed ;
    int slime_speed;
    int status;
    float up_down_speed;

};


#endif // ENEMY_H_INCLUDED
