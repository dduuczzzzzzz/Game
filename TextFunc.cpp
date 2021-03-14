#include "TextFunc.h"

TextFunc::TextFunc()
{
    text_color.r = 0;
    text_color.g = 0;
    text_color.b = 0;
    texture_ = NULL;
}

TextFunc::~TextFunc()
{

}

bool TextFunc::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, str_.c_str(), text_color);
    if(surface)
    {
        texture_ = SDL_CreateTextureFromSurface(screen, surface);
        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }

    return texture_ != NULL;

}

void TextFunc::Free()
{
    if(texture_ != NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

void TextFunc::SetColor()
{
    text_color.r = 0;
    text_color.g = 0;
    text_color.b = 0;
}

void TextFunc::RenderText(SDL_Renderer* screen, int xpos, int ypos, SDL_Rect* clip,double angel, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderquad = {xpos,ypos,width,height};
    if(clip != NULL)
    {
        renderquad.w = clip->w;
        renderquad.h = clip->h;
    }
    SDL_RenderCopyEx(screen, texture_, clip, &renderquad, angel, center, flip);
}
