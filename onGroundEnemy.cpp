#include "onGroundEnemy.h"

onGroundEnemy::onGroundEnemy()
{
    frame_num = 0;
    x_cactus_pos_ = rand()% (SCREEN_WIDTH+300) + SCREEN_WIDTH;
    y_cactus_pos_ = 412;
    x_value= 0;
    width_frame = 0;
    height_frame = 0;
    //status = rand() % (1);
    pause = false;
    slime_speed = 11;
}
onGroundEnemy::~onGroundEnemy()
{

}

bool onGroundEnemy::loadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = GameBase::loadIMG(path, screen);

        if(ret == true)
        {
            width_frame = rect.w/8;
            height_frame = rect.h;
        }

}

void onGroundEnemy::set_clips_enemy()
{
    if(width_frame > 0 && height_frame > 0)
    {
            Enemy2_frame_clips[0].x = 0;
            Enemy2_frame_clips[0].y = 0;
            Enemy2_frame_clips[0].w = width_frame;
            Enemy2_frame_clips[0].h = height_frame;

            Enemy2_frame_clips[1].x = width_frame;
            Enemy2_frame_clips[1].y = 0;
            Enemy2_frame_clips[1].w = width_frame;
            Enemy2_frame_clips[1].h = height_frame;

            Enemy2_frame_clips[2].x = width_frame * 2;
            Enemy2_frame_clips[2].y = 0;
            Enemy2_frame_clips[2].w = width_frame;
            Enemy2_frame_clips[2].h = height_frame;

            Enemy2_frame_clips[3].x = width_frame * 3;
            Enemy2_frame_clips[3].y = 0;
            Enemy2_frame_clips[3].w = width_frame;
            Enemy2_frame_clips[3].h = height_frame;

            Enemy2_frame_clips[4].x = width_frame * 4;
            Enemy2_frame_clips[4].y = 0;
            Enemy2_frame_clips[4].w = width_frame;
            Enemy2_frame_clips[4].h = height_frame;

            Enemy2_frame_clips[5].x = width_frame * 5;
            Enemy2_frame_clips[5].y = 0;
            Enemy2_frame_clips[5].w = width_frame;
            Enemy2_frame_clips[5].h = height_frame;

            Enemy2_frame_clips[6].x = width_frame * 6;
            Enemy2_frame_clips[6].y = 0;
            Enemy2_frame_clips[6].w = width_frame;
            Enemy2_frame_clips[6].h = height_frame;

            Enemy2_frame_clips[7].x = width_frame * 7;
            Enemy2_frame_clips[7].y = 0;
            Enemy2_frame_clips[7].w = width_frame;
            Enemy2_frame_clips[7].h = height_frame;

    }
}

void onGroundEnemy::Show_enemy(SDL_Renderer* des)
{
    if(pause == false){
        loadIMG("enemy/slime.png", des);
        frame_num++;
        if(frame_num>=6) frame_num=0;
    }
        rect.x = x_cactus_pos_;
        rect.y = y_cactus_pos_;

        SDL_Rect* current_clip = &Enemy2_frame_clips[frame_num];

        SDL_Rect renderQuad = {rect.x , rect.y, width_frame, height_frame};

        SDL_RenderCopy(des, p_object, current_clip, &renderQuad);

}

void onGroundEnemy::Move()
{ if(pause == false)
    {
        x_cactus_pos_ = x_cactus_pos_ - slime_speed;
        if(x_cactus_pos_ < 0) {x_cactus_pos_ = rand()% (300) + SCREEN_WIDTH; }
    }
}

int onGroundEnemy::getPos__X()
{
    return x_cactus_pos_;
}

int onGroundEnemy::getPos__Y()
{
    return y_cactus_pos_;
}

void onGroundEnemy::Pause2()
{
    pause = true;
}

void onGroundEnemy::increase_speed2(Uint32 time_)
{
    if(time_ % 150 == 0)
    {
        slime_speed = slime_speed + speed_accelerate;
    }
}
