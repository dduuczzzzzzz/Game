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

    int Jumpspeed = 15;
    int Fallspeed = 15;

    //player
    bool loadIMG_player1(std::string path, SDL_Renderer* screen);
    bool loadIMG_player2(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des, int p);
    void HandleAction(SDL_Event events, Mix_Chunk *gJump, bool collide);
    void set_clips(int p);
    bool onGround();
    void Jumpp();

    int getPosX();
    int getPosY();

    void Pausee();
    void Set_default_player();


private:
    float x_value;
    float y_value;

    float x_pos_;
    float y_pos_;

    int width_frame;
    int height_frame;

    SDL_Rect frame_clips[8];
    SDL_Rect dino_frame_clips[6];

    int frame_num;
    int status;
    bool pause;
};


#endif // MAINOBJECT_H_INCLUDED
