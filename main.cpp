#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "GameBase.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"
#include "GameUltils.h"


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
GameBase g_Theme;
GameBase g_menu;
TTF_Font* font;


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
    else
        {SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
        int IMGFlags = IMG_INIT_PNG;
        if(!(IMG_Init(IMGFlags) && IMGFlags))
            success = false;
        }
    if(TTF_Init() == -1)  {success = false;}
    else {font = TTF_OpenFont("font/pixel.ttf",15);}
    if(font == NULL)
    {
        success = false;
    }

    return success;

}
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
    }
    if (!g_Theme.loadIMG("background/theme.png",g_screen))
    {
        success = false;
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
        cout << "error -- 1" << endl;
    }
    if(loadBackground()==false)
    {
        cout << "error -- 2" << endl;
    }

    // Menu
    GameBase Menu_game;

    SDL_RenderPresent(g_screen);

    // player and monsters
    MainObject p_player;
    p_player.loadIMG("sprites/run_1.png", g_screen);
    p_player.set_clips();

    Enemy enemy_;
    enemy_.loadIMG("enemy/bat.png", g_screen);
    enemy_.set_clips_enemy();

    onGroundEnemy enemy2_;
    enemy2_.loadIMG("enemy/slime.png", g_screen);
    enemy2_.set_clips_enemy();

    // score
    GameBase score_game;

    Uint32 frameStart;
    int frameTime;
    Uint32 current_time;

    bool GameRunning = false;
    bool collide = false;
    bool Menu = true;
    bool Play_Again = false;
    Uint32 score_val = 0;

    while(Menu)
            {
                    while(SDL_PollEvent(&g_event)!= 0)
                {
                    if(g_event.type == SDL_QUIT)
                        {
                            Menu = false;
                        }

                }
                current_time = SDL_GetTicks() / 100;
                g_Theme.Render3(g_screen,NULL,NULL);
                std::string Menu_str_ = "PRESS KEY UP TO START GAME,  ESC TO QUIT, WHEN PLAY, PRESS THE KEY UP TO JUMP!";
                Menu_game.SetColor();
                Menu_game.SetText(Menu_str_);
                Menu_game.LoadFromRenderText(font,g_screen);
                Menu_game.RenderText(g_screen,SCREEN_WIDTH-920, 200);
                if (g_event.type == SDL_KEYDOWN && g_event.key.repeat == 0)
                    {
                        switch (g_event.key.keysym.sym)
                        {
                            case SDLK_UP:
                            {
                                Menu = false;
                                GameRunning = true;
                            }
                            break;
                            case SDLK_ESCAPE:
                            {
                                 GameRunning = false;
                                 Menu = false;
                            }
                            break;
                        }
                    }
                SDL_RenderPresent(g_screen);
            }
    while(GameRunning)
    {
            while(SDL_PollEvent(&g_event)!= 0)
            {
                if(g_event.type == SDL_QUIT)
                    {
                        GameRunning = false;
                    }

            }
            frameStart = SDL_GetTicks();

            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);



                // tinh diem tu luc bat dau tro choi
            score_val += 4;


            for(int i=0;i<Background;i++)
            {
                g_background[i].Render(g_screen,NULL,i);
                g_background[i].Render2(g_screen,NULL,i);
                g_background[i].increase_background_speed(score_val/10);
            }

            p_player.Jumpp();
            p_player.Show(g_screen);
            p_player.HandleAction(g_event /*, g_screen*/);

            enemy_.Show_enemy(g_screen);
            enemy_.Move();
            enemy_.increase_speed(score_val/10);
            enemy_.harder(score_val/10);

            enemy2_.Show_enemy(g_screen);
            enemy2_.Move2();
            enemy2_.increase_speed2(score_val/10);

            //check collide
            if(p_player.getPosX() + 30 -16 >= enemy2_.getPos__X() && p_player.getPosX() + 12  <= enemy2_.getPos__X() + 57)
            {
                if(p_player.getPosY() + 15>= enemy2_.getPos__Y())
                {
                    collide =  true;
                }
            }
            // trừ và cộng các vị trí đi 1 số đơn vị để hình ảnh va chạm trông thật hơn
            else if(p_player.getPosX()+30 - 15  >= enemy_.getPos_X() +32 - 18 && p_player.getPosX()   <= enemy_.getPos_X()+32 )
            {
            if(p_player.getPosY()+45 <= enemy_.getPos_Y()+32 +15&& p_player.getPosY()+45  >= enemy_.getPos_Y()+15)
            {
                collide =  true;
            }
            }
            if(collide == true)
            {
                for(int i=0;i <Background;i++)
                {
                    g_background[i].back_groundSpeed[i] = 0;
                }
                p_player.Pausee();
                enemy2_.Pause2();
                enemy_.Pause1();
                if (g_event.type == SDL_KEYDOWN && g_event.key.repeat == 0)
                    {
                        switch (g_event.key.keysym.sym)
                        {
                            case SDLK_UP:
                            {
                                Play_Again = true;
                                score_val = 0;
                                collide = false;
                            }
                            break;
                            case SDLK_ESCAPE:
                            {
                                 GameRunning = false;
                            }
                            break;
                        }
                    }
            }
            if(Play_Again == true)
            {
                    for(int i=0;i<Background;i++)
                    {
                        g_background[i].Set_default();
                        g_background[i].increase_background_speed(score_val/10);
                    }
                    p_player.Set_default_player();

                    enemy_.Set_default_enemy1();

                    enemy2_.Set_default_enemy2();

                    Play_Again = false;
            }

            //FPS
            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }


            //score game
            //if(Menu == false)
            //{
            std::string str_score = "SCORE: ";
            std::string str_ = std::to_string(score_val/10);
            str_score += str_;
            if (collide == true) score_val-= 4;
            score_game.SetColor();
            score_game.SetText(str_score);
            score_game.LoadFromRenderText(font, g_screen);
            score_game.RenderText(g_screen, SCREEN_WIDTH - 200, 15);

            SDL_RenderPresent(g_screen);
            //}


    }

    close();
    return 0;
}

