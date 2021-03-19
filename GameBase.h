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
    //void SetRect(const int& x, const int& y) {rect.x=x, rect.y=y;}
    SDL_Rect GetRect() const {return rect;}
    SDL_Texture* GetObject() const {return p_object;}

    virtual bool loadIMG(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, SDL_Rect* rectt, int i);
    void Render2(SDL_Renderer* des2, SDL_Rect* rectt2, int i);
    void Render3(SDL_Renderer* des3, SDL_Rect* rect3, SDL_Rect* rect4);
    void Free();
    int getWidth();
    int getHeight();
    bool checkCollision();
    double back_groundSpeed[6];
    void increase_background_speed(Uint32 time_);

protected:
    SDL_Texture* p_object;
    int mwidth;
    int mheight;
    SDL_Rect rect;
    SDL_Rect Camera[6];
    SDL_Rect Camera2[6];


};



#endif // GAMEBASE_H_INCLUDED
