#include "Lbutton.h"

Lbutton::Lbutton()
{
	mPosition.x = 0;
	mPosition.y = 0;

	mCurrentSprite = BUTTON_MOUSE_OUT;
}
void Lbutton::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

bool Lbutton::Inside( SDL_Event* e , int size)
{
    //Check if mouse is in button
    bool inside = true;
    int button_width,button_height;
    if(size == BIG)
    {
        button_width = BIG_BUTTON_WIDTH;
        button_height = BIG_BUTTON_HEIGHT;
    }
    else if(size == SMALL)
    {
        button_width = SMALL_BUTTON_WIDTH;
        button_height = SMALL_BUTTON_HEIGHT;
    }
	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + button_width )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + button_height )
		{
			inside = false;
		}
	}
	return inside;
}

void Lbutton::render(SDL_Renderer *ren, GameBase gButton, SDL_Rect *currentClips)
{

	//Show current button sprite
	gButton.Render3(ren, currentClips, NULL);
}
