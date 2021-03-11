#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>

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
#define GROUND_SPEED 7
#define BG1_speed  3
#define BG2_speed  5
#define BG3_speed  6
#define BG4_speed  5.0
#define BG5_speed  7
#endif // COMMONFUNC_H_INCLUDED
