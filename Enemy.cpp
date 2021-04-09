#include "Enemy.h"

Enemy::Enemy()
{
    frame_num = 0;
    x_birds_pos_ = rand()% (SCREEN_WIDTH+500) + SCREEN_WIDTH;
    y_birds_pos_ = 340;
    x_value= 0;
    width_frame = 0;
    height_frame = 0;
    //status = rand() % (1);
    pause = false;
    enemy_speed = 8;
    status = 1;
    up_down_speed = 0.1;
}
Enemy::~Enemy()
{

}

bool Enemy::loadIMG(std::string path, SDL_Renderer* screen)
{
    bool a = GameBase::loadIMG(path, screen);
     if(a == true)
        {
            width_frame = rect.w / 5;
            height_frame = rect.h;
        }

}

void Enemy::set_clips_enemy()
{
    if(width_frame > 0 && height_frame > 0)
    {
            Enemy_frame_clips[0].x = 0;
            Enemy_frame_clips[0].y = 0;
            Enemy_frame_clips[0].w = width_frame;
            Enemy_frame_clips[0].h = height_frame;

            Enemy_frame_clips[1].x = width_frame;
            Enemy_frame_clips[1].y = 0;
            Enemy_frame_clips[1].w = width_frame;
            Enemy_frame_clips[1].h = height_frame;

            Enemy_frame_clips[2].x = width_frame * 2;
            Enemy_frame_clips[2].y = 0;
            Enemy_frame_clips[2].w = width_frame;
            Enemy_frame_clips[2].h = height_frame;

            Enemy_frame_clips[3].x = width_frame * 3;
            Enemy_frame_clips[3].y = 0;
            Enemy_frame_clips[3].w = width_frame;
            Enemy_frame_clips[3].h = height_frame;

            Enemy_frame_clips[4].x = width_frame * 4;
            Enemy_frame_clips[4].y = 0;
            Enemy_frame_clips[4].w = width_frame;
            Enemy_frame_clips[4].h = height_frame;

    }
}

void Enemy::Show_enemy(SDL_Renderer* des)
{
    if(pause == false)
    {
        loadIMG("enemy/bat.png", des);
        frame_num++;
        if(frame_num>=5) frame_num = 0;
    }

        rect.x = x_birds_pos_;
        rect.y = y_birds_pos_;

        SDL_Rect* current_clip = &Enemy_frame_clips[frame_num];

        SDL_Rect renderQuad = {rect.x , rect.y, width_frame, height_frame};

        SDL_RenderCopy(des, p_object, current_clip, &renderQuad);


}

void Enemy::Move()
{   if(pause == false)
    {
    x_birds_pos_ = x_birds_pos_ - enemy_speed;
    if(x_birds_pos_ < 0) {x_birds_pos_ = rand()% ( 500) + SCREEN_WIDTH; }
    }
}

int Enemy::getPos_X()
{
    return x_birds_pos_;
}

int Enemy::getPos_Y()
{
    return y_birds_pos_;
}

void Enemy::Pause1()
{
    pause = true;
}

void Enemy::harder(Uint32 time_)
{
    if(pause == false)
    {
        if(time_ >= 150)
        {
            if(status == DOWN)
            {
                y_birds_pos_ += 2 + up_down_speed;
            }
            if(y_birds_pos_ >= 395)
            {
                status = UP;
            }
            if(status == UP && y_birds_pos_ >= 325)
            {
                y_birds_pos_ -= 2 + up_down_speed;
            }
            if(y_birds_pos_ <= 325)
            {
                status = DOWN;
            }
        }
    }
}

void Enemy::increase_speed(Uint32 time_)
{
    if(time_ % 100 == 0)
    {
        enemy_speed = enemy_speed + speed_accelerate;
        up_down_speed += 0.2;
    }
}

 void Enemy::Set_default_enemy1()
 {
    pause = false;
    x_birds_pos_ = rand()% (SCREEN_WIDTH+500) + SCREEN_WIDTH;
    y_birds_pos_ = 340;
    x_value= 0;
    enemy_speed = 8;
    up_down_speed = 0.1;

 }
