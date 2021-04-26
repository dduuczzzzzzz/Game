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

static Mix_Music *gMenu = NULL;
static Mix_Chunk *gPlayer = NULL;
static Mix_Chunk *gDino = NULL;
static Mix_Chunk *gJump = NULL;
static Mix_Chunk *gClick = NULL;
static Mix_Music *gPlay = NULL;
static Mix_Chunk *gLose = NULL;

#define DINO 2
#define RUNNER 1

#endif // COMMONFUNC_H_INCLUDED
