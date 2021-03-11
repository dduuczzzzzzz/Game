#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "GameBase.h"
#include "MainObject.h"
#include "OtherHelpFunc.h"
#include "Enemy.h"

using namespace std;

const string LAYER[Background]={
        "Background/BG1.png",
        "Background/BG2.png",
        "Background/BG3.png",
        "Background/BG4.png",
        "Background/BG5.png",
        "Background/BG6.png"
};


GameBase g_background[Background];
//GameBase g_Ground;

bool Init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Fail to load wwindow! " << endl;
    }

    g_window = SDL_CreateWindow("DUC RUN GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(g_window == NULL) {cout << "Fail to load window" << endl;  success = false;}

    else {g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

    if(g_screen == NULL) {success = false;}
    else {SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
        int IMGFlags = IMG_INIT_PNG;
        if(!(IMG_Init(IMGFlags) && IMGFlags))
            success = false;
    }
    }
    return success;

}

bool loadBackground()
{
    bool success = true;
    for(int i=0; i<Background; i++)
    {
        if(!g_background[i].loadIMG(LAYER[i].c_str(), g_screen))
        {
            success = false;
        }
        /*if(!g_Ground.loadIMG("Background/BG6.png", g_screen))
        {
            success = false;
        }*/
    }
    return success;
}

void close()
{
    for(int i=0;i<Background;i++)
    {
        g_background[i].Free();
    }
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if(Init()==false)
    {
        cout << "error" << endl;
    }
    if(loadBackground()==false)
    {
        cout << "error" << endl;
    }

    MainObject p_player;
    p_player.loadIMG("sprites/run_1.png", g_screen);
    p_player.set_clips();

    Enemy birds;
    birds.loadIMG("enemy/birds.png", g_screen);
    Enemy monster;
    monster.loadIMG("enemy/monster.png", g_screen);
    birds.set_clips_enemy();
    monster.set_clips_enemy();

    Uint32 frameStart;
    int frameTime;

    bool GameRunning = true;
    while(GameRunning)
    {
        while(SDL_PollEvent(&g_event)!= 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                GameRunning = false;
            }
            p_player.HandleAction(g_event , g_screen);
        }

        frameStart = SDL_GetTicks();

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);


        for(int i=0;i<Background;i++)
        {
            g_background[i].Render(g_screen,NULL,i);
            g_background[i].Render2(g_screen,NULL,i);
            //scrollBackground(Camera[i], back_groundSpeed);

        }
        //g_Ground.Render(g_screen, NULL, NULL);
        p_player.Jumpp();
        p_player.Show(g_screen);
        birds.Show_enemy(g_screen);
        birds.Move();
        monster.Show_enemy(g_screen);
        monster.Move();
        SDL_RenderPresent(g_screen);

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    close();
    return 0;
}
