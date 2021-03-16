#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "GameBase.h"
#include "MainObject.h"
#include "Enemy.h"
#include "onGroundEnemy.h"
#include "GameUltils.h"
#include "TextFunc.h"

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
TTF_Font* font_score;


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
    else {font_score = TTF_OpenFont("font/pixel.ttf",15);}
    if(font_score == NULL)
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

bool check_coolide(MainObject p_player, Enemy enemy_, onGroundEnemy enemy2_);

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
    srand(time(NULL));
    bool GameRunning = true;

    TextFunc Menu_game;
    Menu_game.SetColor();

    SDL_RenderPresent(g_screen);

    // nhan vat va quai
    MainObject p_player;
    p_player.loadIMG("sprites/run_1.png", g_screen);
    p_player.set_clips();

    Enemy enemy_;
    enemy_.loadIMG("enemy/bat.png", g_screen);
    enemy_.set_clips_enemy();
    onGroundEnemy enemy2_;
    enemy2_.loadIMG("enemy/slime.png", g_screen);
    enemy2_.set_clips_enemy();

    //time
    TextFunc score_game;
    score_game.SetColor();

    Uint32 frameStart;
    int frameTime;

    bool collide = false;
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

            }

            std::string Menu_str_ = "Press Backspace to start game,  ESC to quit, when play , press the up key to jump!";
            Menu_game.SetText(Menu_str_);
            Menu_game.LoadFromRenderText(font_score,g_screen);
            Menu_game.RenderText(g_screen,SCREEN_WIDTH-870, 200);

           // g_Theme.Render3(g_screen,NULL,NULL);
            p_player.Jumpp();
            p_player.Show(g_screen);
            enemy_.Show_enemy(g_screen);
            enemy_.Move();
            enemy2_.Show_enemy(g_screen);
            enemy2_.Move();

            //FPS
            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
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
            g_background[i].back_groundSpeed[i] = 0;
            p_player.Pausee();
            enemy2_.Pause2();
            enemy_.Pause1();
            cout << "LOSE" ;
        }

            //score game
        std::string str_score = "Score: ";
        std::string str_highscore = "HighScore: ";
        Uint32 score_val = SDL_GetTicks() / 100;
        std::string str_ = std::to_string(score_val);
        if(collide == false)
        {
            str_score += str_;
            str_highscore += str_ ;
        }
        score_game.SetText(str_score);
        score_game.LoadFromRenderText(font_score, g_screen);
        score_game.RenderText(g_screen, SCREEN_WIDTH - 200, 15);

        score_game.SetText(str_highscore);
        score_game.LoadFromRenderText(font_score, g_screen);
        score_game.RenderText(g_screen, SCREEN_WIDTH - 200, 45);

        SDL_RenderPresent(g_screen);

    }

    close();
    return 0;
}

bool check_coolide(MainObject p_player, Enemy enemy_, onGroundEnemy enemy2_)
{
    //check collide
        if(p_player.getPosX() + 30 -16 >= enemy2_.getPos__X() && p_player.getPosX() + 12  <= enemy2_.getPos__X() + 57)
        {
            if(p_player.getPosY() + 15>= enemy2_.getPos__Y())
            {
                //GameRunning = false;

                return true;
            }
        }
        // trừ và cộng các vị trí đi 1 số đơn vị để hình ảnh va chạm trông thật hơn
        else if(p_player.getPosX()+30 -15 >= enemy_.getPos_X()+32 -18 && p_player.getPosX()  <= enemy_.getPos_X()+32 )
        {
            if(p_player.getPosY()+45 <= enemy_.getPos_Y()+32 +15&& p_player.getPosY()+45  >= enemy_.getPos_Y()+15)
            {
                //GameRunning = false;

                return true;
            }
        }
}

