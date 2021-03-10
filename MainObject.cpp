#include "MainObject.h"
#include "CommonFunc.h"

MainObject::MainObject()
{
    frame_num = 0;
    x_pos_ = 160;
    y_pos_ = 415;
    x_value = 0;
    width_frame = 0;
    height_frame = 0;
    status = -1;
}

MainObject::~MainObject()
{

}

bool MainObject::onGround()
{
    return y_pos_ == GROUND;
}

bool MainObject::loadIMG(std::string path, SDL_Renderer* screen)
{
    bool ret = GameBase::loadIMG(path, screen);
    if(ret == true)
    {
        width_frame = rect.w / 8;
        height_frame = rect.h;
    }
    return ret;
}

void MainObject::set_clips()
{
    if(width_frame > 0 && height_frame > 0)
    {
        frame_clips[0].x = 0;
        frame_clips[0].y = 0;
        frame_clips[0].w = width_frame;
        frame_clips[0].h = height_frame;

        frame_clips[1].x = width_frame;
        frame_clips[1].y = 0;
        frame_clips[1].w = width_frame;
        frame_clips[1].h = height_frame;

        frame_clips[2].x = width_frame * 2;
        frame_clips[2].y = 0;
        frame_clips[2].w = width_frame;
        frame_clips[2].h = height_frame;

        frame_clips[3].x = width_frame * 3;
        frame_clips[3].y = 0;
        frame_clips[3].w = width_frame;
        frame_clips[3].h = height_frame;

        frame_clips[4].x = width_frame * 4;
        frame_clips[4].y = 0;
        frame_clips[4].w = width_frame;
        frame_clips[4].h = height_frame;

        frame_clips[5].x = width_frame * 5;
        frame_clips[5].y = 0;
        frame_clips[5].w = width_frame;
        frame_clips[5].h = height_frame;

        frame_clips[6].x = width_frame * 6;
        frame_clips[6].y = 0;
        frame_clips[6].w = width_frame;
        frame_clips[6].h = height_frame;

        frame_clips[7].x = width_frame * 7;
        frame_clips[7].y = 0;
        frame_clips[7].w = width_frame;
        frame_clips[7].h = height_frame;
    }
}

void MainObject::Show(SDL_Renderer* des)
{
    if(onGround() == true)
    {
        loadIMG("sprites/run_1.png", des);
        frame_num++;
        if(frame_num>=8) frame_num = 0;

    }
    rect.x = x_pos_;
    rect.y = y_pos_;

    SDL_Rect* current_clip = &frame_clips[frame_num];

    SDL_Rect renderQuad = {rect.x , rect.y, width_frame, height_frame};

    SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
}

void MainObject::HandleAction(SDL_Event events, SDL_Renderer* screen)
{

	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_UP:
			{
				if (onGround())
				{
					status = JUMP;
				}
			}
		}
	}
}
void MainObject::Jumpp()
{
    if(status == JUMP && y_pos_ >= 250)
    {
        y_pos_+= -Jumpspeed;
    }
    if(y_pos_ <= 250)
    {
        status = FALL;
    }
    if(status == FALL && y_pos_ < GROUND )
    {
        y_pos_ += Fallspeed;

    }
}
