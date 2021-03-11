#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "CommonFunc.h"
#include "GameBase.h"
#define BIRDS 2
#define CACTUS 1
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

private:
    float x_value;
    float y_value;

    float x_birds_pos_;
    float y_birds_pos_;
    float x_cactus_pos_;
    float y_cactus_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect Enemy_frame_clips[8];
    SDL_Rect Enemy2_frame_clips[6];

    int frame_num;
    int status;
};


#endif // ENEMY_H_INCLUDED
