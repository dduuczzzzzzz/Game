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

    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void SetColor();
    void RenderText(SDL_Renderer* screen, int xpos, int ypos, SDL_Rect* clip = NULL,double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void SetText(const std::string& text) {str_ = text;}
    std::string GetText() const {return str_;}

    void Free();

    int getWidth();
    int getHeight();
    double back_groundSpeed[6];
    void increase_background_speed(Uint32 time_);
    void Set_default();

protected:
    SDL_Texture* p_object;
    std::string str_;
    SDL_Color text_color;
    int width;
    int height;
    SDL_Rect rect;
    SDL_Rect Camera[6];
    SDL_Rect Camera2[6];


};



#endif // GAMEBASE_H_INCLUDED
