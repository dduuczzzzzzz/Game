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

void GameBase::Render(SDL_Renderer* des,  SDL_Rect* clip, SDL_Rect* renderquad)
{
    SDL_RenderCopy(des, p_object, clip, renderquad);

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
