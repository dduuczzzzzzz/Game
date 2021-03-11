#include "Enemy.h"

Enemy::Enemy()
{
    frame_num = 0;
    x_birds_pos_ = rand()% (350) + SCREEN_WIDTH;
    y_birds_pos_ = 350;
    x_cactus_pos_ = rand()% (415) + SCREEN_WIDTH;
    y_cactus_pos_ = 415;
    x_value= 0;
    width_frame = 0;
    height_frame = 0;
    //status = rand() % (1);
    srand(time(0));
	status = rand() % (2)+1;
}
Enemy::~Enemy()
{

}

bool Enemy::loadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = GameBase::loadIMG(path, screen);
    if(status == BIRDS)
    {
        if(ret == true)
        {
            width_frame = rect.w / 8;
            height_frame = rect.h;
        }
    }
    else if (status == CACTUS)
    {
        if(ret == true)
        {
            width_frame = rect.w/6;
            height_frame = rect.h;
        }
    }
}

void Enemy::set_clips_enemy()
{
    if(width_frame > 0 && height_frame > 0)
    {
        if(status == BIRDS)
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

            Enemy_frame_clips[5].x = width_frame * 5;
            Enemy_frame_clips[5].y = 0;
            Enemy_frame_clips[5].w = width_frame;
            Enemy_frame_clips[5].h = height_frame;

            Enemy_frame_clips[6].x = width_frame * 6;
            Enemy_frame_clips[6].y = 0;
            Enemy_frame_clips[6].w = width_frame;
            Enemy_frame_clips[6].h = height_frame;

            Enemy_frame_clips[7].x = width_frame * 7;
            Enemy_frame_clips[7].y = 0;
            Enemy_frame_clips[7].w = width_frame;
            Enemy_frame_clips[7].h = height_frame;
        }
        else if (status == CACTUS)
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
        }
    }
}

void Enemy::Show_enemy(SDL_Renderer* des)
{   std::cout << status << std::endl << x_birds_pos_ << std::endl;
    if(status == BIRDS)
    {
        loadIMG("enemy/birds.png", des);
        frame_num++;
        if(frame_num>=8) frame_num = 0;

        rect.x = x_birds_pos_;
        rect.y = y_birds_pos_;

        SDL_Rect* current_clip = &Enemy_frame_clips[frame_num];

        SDL_Rect renderQuad = {rect.x , rect.y, width_frame, height_frame};

        SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
    }
    else if (status == CACTUS)
    {
        loadIMG("enemy/monster.png", des);
        frame_num++;
        if(frame_num>=6) frame_num=0;
        rect.x = x_cactus_pos_;
        rect.y = y_cactus_pos_;

        SDL_Rect* current_clip = &Enemy2_frame_clips[frame_num];

        SDL_Rect renderQuad = {rect.x , rect.y, width_frame, height_frame};

        SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
    }
}

void Enemy::Move()
{
    x_birds_pos_ = x_birds_pos_ -10;
    if(x_birds_pos_ < 0) {x_birds_pos_ = rand()% ( 350) + SCREEN_WIDTH; }
    x_cactus_pos_ = x_cactus_pos_ -10;
    if(x_cactus_pos_ < 0) {x_cactus_pos_ = rand()% ( 415) + SCREEN_WIDTH; }
}
