#ifndef GAMEBASE_H_INCLUDED
#define GAMEBASE_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "CommonFunc.h"
#include <string>

class GameBase
{
public:
    GameBase();
    ~GameBase();
    void SetRect(const int& x, const int& y) {rect.x=x, rect.y=y;}
    SDL_Rect GetRect() const {return rect;}
    SDL_Texture* GetObject() const {return p_object;}

    virtual bool loadIMG(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, SDL_Rect* clip, SDL_Rect* renderquad);
    void Free();
    int getWidth();
    int getHeight();

protected:
    SDL_Texture* p_object;
    int mwidth;
    int mheight;
    SDL_Rect rect;

};



#endif // GAMEBASE_H_INCLUDED
