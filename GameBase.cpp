#include "GameBase.h"

GameBase::GameBase()
{
        p_object = NULL;
        rect.x = 0;
        rect.y = 0;
        rect.w = 0;
        rect.h = 0;
        mwidth = 0;
        mheight = 0;

        Camera[0].x = 0;
        Camera[0].y = 0;
        Camera[0].h = 495;
        Camera[0].w = 990;

        Camera[1].x = 0;
        Camera[1].y = 0;
        Camera[1].h = 495;
        Camera[1].w = 990;

        Camera[2].x = 0;
        Camera[2].y = 0;
        Camera[2].h = 495;
        Camera[2].w = 990;

        Camera[3].x = 0;
        Camera[3].y = 0;
        Camera[3].h = 495;
        Camera[3].w = 990;

        Camera[4].x = 0;
        Camera[4].y = 0;
        Camera[4].h = 495;
        Camera[4].w = 990;

        Camera[5].x = 0;
        Camera[5].y = 0;
        Camera[5].h = 495;
        Camera[5].w = 990;
        // ---------------------------------------------------------------------

        Camera2[0].x = 990;
        Camera2[0].y = 0;
        Camera2[0].h = 495;
        Camera2[0].w = 990;

        Camera2[1].x = 990;
        Camera2[1].y = 0;
        Camera2[1].h = 495;
        Camera2[1].w = 990;

        Camera2[2].x = 990;
        Camera2[2].y = 0;
        Camera2[2].h = 495;
        Camera2[2].w = 990;

        Camera2[3].x = 990;
        Camera2[3].y = 0;
        Camera2[3].h = 495;
        Camera2[3].w = 990;

        Camera2[4].x = 990;
        Camera2[4].y = 0;
        Camera2[4].h = 495;
        Camera2[4].w = 990;

        Camera2[5].x = 990;
        Camera2[5].y = 0;
        Camera2[5].h = 495;
        Camera2[5].w = 990;

        back_groundSpeed[0] = BG1_speed;
        back_groundSpeed[1] = BG2_speed;
        back_groundSpeed[2] = BG3_speed;
        back_groundSpeed[3] = BG4_speed;
        back_groundSpeed[4] = BG5_speed;
        back_groundSpeed[5] = GROUND_SPEED;

}

GameBase::~GameBase()
{
    Free();
}

bool GameBase::loadIMG(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;

    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    new_texture = SDL_CreateTextureFromSurface(screen,loadSurface);
    if(new_texture!=NULL)
    {
        rect.w = loadSurface->w;
        rect.h = loadSurface->h;
    }
    SDL_FreeSurface(loadSurface);

    p_object = new_texture;
    return p_object!=NULL;
}

void GameBase::Render(SDL_Renderer* des, SDL_Rect* rectt, int i)
{
    Camera[i].x = Camera[i].x - back_groundSpeed[i];
    if(Camera[i].x <= -990)
            {
                Camera[i].x = 0;
            }
    SDL_RenderCopy(des, p_object, rectt, &Camera[i]);

}

void GameBase::Render2(SDL_Renderer* des2, SDL_Rect* rectt2, int i)
{
    Camera2[i].x = Camera2[i].x - back_groundSpeed[i];
    if(Camera2[i].x <= 0)
        {
            Camera2[i].x = 990;
        }
    SDL_RenderCopy(des2, p_object, rectt2, &Camera2[i]);

}

void GameBase::Render3(SDL_Renderer* des3, SDL_Rect* rect3, SDL_Rect* rect4)
{
    SDL_RenderCopy(des3 , p_object, rect3, rect4);
}

void GameBase::Free()
{
    if(p_object!=NULL)
    {
        SDL_DestroyTexture(p_object);
        p_object = NULL;
        rect.w=0;
        rect.h=0;
    }
}

int GameBase::getWidth()
{
    return mwidth;
}

int GameBase::getHeight()
{
    return mheight;
}

bool GameBase::checkCollision()
{

}

void GameBase::increase_background_speed(Uint32 time_)
{
    if(time_ % 150 == 0)
    {
        for(int i=0; i<Background; i++)
        {
            back_groundSpeed[i] += speed_accelerate;
        }
    }
}
