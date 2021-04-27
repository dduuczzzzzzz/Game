#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "GameBase.h"
#include "MainObject.h"
#include "Enemy.h"
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
GameBase g_instruct;
GameBase g_select_player;
GameBase g_player1;
GameBase g_player2;

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

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return false;
    }
        gMenu = Mix_LoadMUS("sounds/bkgr_audio.wav");
        gPlayer = Mix_LoadWAV("sounds/adventure chose.wav");
        gDino = Mix_LoadWAV("sounds/dino chose.wav");
        gJump = Mix_LoadWAV("sounds/jump.wav");
        gClick = Mix_LoadWAV("sounds/button click.wav");
        gLose = Mix_LoadWAV("sounds/lose.wav");
        gPlay = Mix_LoadMUS("sounds/theme.wav");

    if(gMenu == NULL || gPlayer == NULL || gDino == NULL || gJump == NULL || gClick == NULL || gLose == NULL || gPlay == NULL)
    {
        return false;
    }

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
    if (!g_Theme.loadIMG("background/theme4.png",g_screen))
    {
        success = false;
    }
    if(!g_instruct.loadIMG("background/instructt.png",g_screen))
    {
        success = false;
    }
    if(!g_select_player.loadIMG("background/select player.png",g_screen))
    {
        success = false;
    }
    if(!g_player1.loadIMG("background/adventure chose.png",g_screen))
    {
        success = false;
    }
    if(!g_player2.loadIMG("background/dino chose.png",g_screen))
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
    g_Theme.Free();
    g_instruct.Free();
    g_select_player.Free();
    g_player1.Free();
    g_player2.Free();
    Mix_FreeMusic(gMenu);
    Mix_FreeMusic(gPlay);
    Mix_FreeChunk(gClick);
    Mix_FreeChunk(gPlayer);
    Mix_FreeChunk(gDino);
    Mix_FreeChunk(gJump);
    Mix_FreeChunk(gLose);
    gMenu = NULL;
    gPlay = NULL;
    gClick = NULL;
    gPlayer = NULL;
    gDino = NULL;
    gJump = NULL;
    gLose = NULL;

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    Mix_Quit();
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
    GameBase Menu_game;
    GameBase score_game;
    GameBase highscore_game;
    GameBase endgame1;
    MainObject p_player;

    Enemy enemy_;
    enemy_.loadIMG2("enemy/bat.png", g_screen);
    enemy_.set_clips_enemy();

    Enemy enemy2_;
    enemy2_.loadIMG3("enemy/slime.png", g_screen);
    enemy2_.set_clips_enemy2();

    Uint32 frameStart;
    int frameTime;
    int p = 0;
    bool GameRunning = false;
    bool collide = false;
    bool Menu = true;
    bool Play_Again = false;
    bool Instruct = false;
    bool Chose_player = false;
    bool Player1 = false;
    bool Player2 = false;
    bool end_Game;
    int score_val = 0;
    Mix_PlayMusic(gMenu, -1);
    while(Menu)
            {
                while(SDL_PollEvent(&g_event)!= 0)
                {
                    if(g_event.type == SDL_QUIT)
                        {
                            Menu = false;
                        }
                        switch (g_event.key.keysym.sym)
                        {
                            case SDLK_SPACE:
                            {
                                Instruct = true;
                                Menu = false;
                                Mix_PlayChannel(-1, gClick, 0);
                            }
                            break;
                            case SDLK_ESCAPE:
                            {
                                 GameRunning = false;
                                 Menu = false;
                            }
                }
                g_Theme.Render3(g_screen,NULL,NULL);
                SDL_RenderPresent(g_screen);
                }
            }
    while(Instruct)
            {
                while(SDL_PollEvent(&g_event)!= 0)
                    {
                        if(g_event.type == SDL_QUIT)
                            {
                                Instruct = false;
                            }
                        switch (g_event.key.keysym.sym)
                            {
                                case SDLK_RIGHT:
                                    {
                                        Instruct = false;
                                        Chose_player = true;
                                        Mix_PlayChannel(-1, gClick, 0);
                                    }
                                break;
                            }
                    }
                g_instruct.Render3(g_screen,NULL,NULL);
                SDL_RenderPresent(g_screen);
            }
    while(Chose_player)
    {
            while(SDL_PollEvent(&g_event)!= 0)
            {
                if(g_event.type == SDL_QUIT)
                {
                    Chose_player = false;
                }
                switch (g_event.key.keysym.sym)
                {
                    case SDLK_1:
                        {
                            Chose_player = false;
                            Player1 = true;
                            p = 1;
                            Mix_PlayChannel(-1, gPlayer, 0);
                        }
                    break;
                    case SDLK_2:
                        {
                            Chose_player = false;
                            Player2 = true;
                            p = 2;
                            Mix_PlayChannel(-1, gDino, 0);
                        }
                    break;
                }
            }
            g_select_player.Render3(g_screen,NULL,NULL);
            SDL_RenderPresent(g_screen);
    }
    while(Player1)
    {
        while(SDL_PollEvent(&g_event)!= 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                Player1 = false;
            }
            if( g_event.key.keysym.sym == SDLK_SPACE)
            {
                Player1 = false;
                GameRunning = true;
                Mix_PlayChannel(-1, gClick, 0);
            }
        }
        g_player1.Render3(g_screen, NULL, NULL);
        SDL_RenderPresent(g_screen);
    }
    while(Player2)
    {
        while(SDL_PollEvent(&g_event)!= 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                Player2 = false;
            }
            if( g_event.key.keysym.sym == SDLK_SPACE)
            {
                Player2 = false;
                GameRunning = true;
                Mix_PlayChannel(-1, gClick, 0);
            }
        }
        g_player2.Render3(g_screen, NULL, NULL);
        SDL_RenderPresent(g_screen);
    }
    Mix_FreeMusic(gMenu);

    if(p == RUNNER)
    {
        p_player.loadIMG_player1("sprites/run_1.png", g_screen);
        p_player.set_clips(p);
    }
    else if(p == DINO)
    {
        p_player.loadIMG_player2("sprites/char.png", g_screen);
        p_player.set_clips(p);
    }

    while(GameRunning)
    {
        Mix_PlayMusic(gPlay, -1);
        std::string highscore_val = GetHSfromFile("high_score.txt");
        bool Play = true;
        while(Play)
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
            p_player.Show(g_screen,p);
            p_player.HandleAction(g_event, gJump, collide);

            enemy_.Show_enemy(g_screen);
            enemy_.Move();
            enemy_.increase_speed(score_val/10);
            enemy_.harder(score_val/10);

            enemy2_.Show_enemy2(g_screen);
            enemy2_.Move2();
            enemy2_.increase_speed(score_val/10);
            GetHighscore("high_score.txt", score_val/10, highscore_val);

            //FPS
            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }

            std::string str_score = "SCORE: ";
            std::string str_ = std::to_string(score_val/10);
            str_score += str_;
            if (collide == true) score_val-= 4;
            Text_func(str_score, score_game, font, g_screen, SCREEN_WIDTH - 200, 15);
            std::string highscore = "HIGH SCORE: ";
            highscore += highscore_val;
            Text_func(highscore, highscore_game, font, g_screen, SCREEN_WIDTH- 200, 45);

            if(Check_collision(p_player, enemy_, enemy2_) == true)
            {
                 collide = true;
                std::string end_game1 = "YOU LOSE !!!!  Press SPACE to replay or ESC to quit game !!!";
                Text_func(end_game1, endgame1, font, g_screen, 150, 70);
                SDL_RenderPresent(g_screen);
            }
            //End_Game(collide, p_player, enemy_, enemy2_, Play_Again, Play, GameRunning, score_val, gClick, g_background, endgame1, font, g_event, g_screen);

            if(collide == true)
            {
                Mix_PauseMusic();
                Mix_PlayChannel(-1, gLose, 0);
                for(int i=0;i <Background;i++)
                {
                    g_background[i].back_groundSpeed[i] = 0;
                }
                p_player.Pausee();
                enemy2_.Pause1();
                enemy_.Pause1();

                //SDL_RenderPresent(g_screen);

                end_Game = false;
                while(!end_Game)
                {
                    while(SDL_PollEvent(&g_event) != 0)
                    {
                        if(g_event.type == SDL_QUIT)
                        {
                            GameRunning = false;
                        }
                        if(g_event.type == SDL_KEYDOWN)
                        {
                            switch (g_event.key.keysym.sym)
                            {
                                case SDLK_SPACE:
                                {
                                    Play_Again = true;
                                    score_val = 0;
                                    collide = false;
                                    Mix_PlayChannel(-1, gClick, 0);
                                    end_Game = true;
                                }
                                break;
                                case SDLK_ESCAPE:
                                {
                                    end_Game = true;
                                    Play = false;
                                    GameRunning = false;
                                }
                                break;
                            }
                        }

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

                    enemy2_.Set_default_enemy1();

                    Play = false;

                    Play_Again = false;
            }

            SDL_RenderPresent(g_screen);

        }
    }

    close();
    return 0;
}

