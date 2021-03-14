#ifndef TEXTFUNC_H_INCLUDED
#define TEXTFUNC_H_INCLUDED
#include "CommonFunc.h"

class TextFunc
{
public:
    TextFunc();
    ~TextFunc();

    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void Free();
    void SetColor();
    void RenderText(SDL_Renderer* screen, int xpos, int ypos, SDL_Rect* clip = NULL,double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWidth() const {return width;}
    int GetHeight() const {return height;}
    void SetText(const std::string& text) {str_ = text;}
    std::string GetText() const {return str_;}

private:
    std::string str_;
    SDL_Texture* texture_;
    SDL_Color text_color;
    int width;
    int height;
};


#endif // TEXTFUNC_H_INCLUDED
