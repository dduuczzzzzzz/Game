#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED
#include "GameBase.h"
#include "CommonFunc.h"

#define JUMP 1
#define FALL 2
#define RUN 0


class MainObject : public GameBase
{
public:
    MainObject();
    ~MainObject();

    static const int Jumpspeed = 15;
    static const int Fallspeed = 15;

    bool loadIMG(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();
    bool onGround();
    void Jumpp();
    int getPosX();
    int getPosY();

private:
    float x_value;
    float y_value;

    float x_pos_;
    float y_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect frame_clips[8];

    int frame_num;
    int status;
};


#endif // MAINOBJECT_H_INCLUDED
