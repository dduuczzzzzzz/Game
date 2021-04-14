#ifndef LBUTTON_H_INCLUDED
#define LBUTTON_H_INCLUDED
#include "CommonFunc.h"
#include "GameBase.h"

class Lbutton
{
public:
        Lbutton();

		//Sets top left position
		void setPosition( int x, int y );

		//Handles mouse event
		bool Inside( SDL_Event* e , int size);

		//Shows button sprite
		void render(SDL_Renderer *ren, GameBase gButton, SDL_Rect *currentClips);

        //Currently used global sprite
		button_sprites mCurrentSprite;

private:
        //Top left position
		SDL_Point mPosition;

		int width_frame;
		int height_frame;

};



#endif // LBUTTON_H_INCLUDED
