#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// man hinh
const int SCREEN_WIDTH = 990;
const int SCREEN_HEIGHT = 495;
const int SCREEN_BPP = 32;

//const int COLOR_KEY_R = 167;
//const int COLOR_KEY_G = 175;
//const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff;

const int Background = 6;

const int FPS = 30;
const int frameDelay = 1000/FPS;

#define GROUND 415

//background speed
#define GROUND_SPEED 8
#define BG1_speed  2
#define BG2_speed  5
#define BG3_speed  6
#define BG4_speed  5.0
#define BG5_speed  7

#define player_height 45
#define player_width 30
#define bat_height 32
#define bat_width 32
#define slime_height 57
#define slime_width 57

#define speed_accelerate 1

//Button constants
const int BIG_BUTTON_WIDTH = 150;
const int BIG_BUTTON_HEIGHT = 98;
const int SMALL_BUTTON_WIDTH = 22;
const int SMALL_BUTTON_HEIGHT = 34;

enum button_sprites
    {
        BUTTON_MOUSE_OUT = 0,
        BUTTON_MOUSE_OVER = 1,
        BUTTON_TOTAL_SPRITES = 2,
    };
const int PLAY_BUTON_POSX = 420;
const int PLAY_BUTTON_POSY= 186;
const int HELP_BUTTON_POSX = 420;
const int HELP_BUTTON_POSY = 293;
const int EXIT_BUTTON_POSX = 420;
const int EXIT_BUTTON_POSY = 402;
const int BACK_BUTTON_POSX = 31;
const int BACK_BUTTON_POSY = 29;

static Mix_Music *gMenu = NULL;
static Mix_Chunk *gPlayer = NULL;
static Mix_Chunk *gDino = NULL;
static Mix_Chunk *gJump = NULL;
static Mix_Chunk *gClick = NULL;
static Mix_Music *gPlay = NULL;
static Mix_Chunk *gLose = NULL;

#define BIG 0
#define SMALL 1

#endif // COMMONFUNC_H_INCLUDED
