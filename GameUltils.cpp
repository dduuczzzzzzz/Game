#include "GameUltils.h"

void Play_button(SDL_Event *e,Lbutton &PlayButton, bool Menu, bool GameRunning)
{
    if (e->type == SDL_QUIT)
	{
		Menu = false;
	}

	if (PlayButton.Inside(e, BIG))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			PlayButton.mCurrentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			GameRunning = true;
			Menu = false;
			PlayButton.mCurrentSprite = BUTTON_MOUSE_OVER;
			break;
		}
	}
	else
	{
		PlayButton.mCurrentSprite = BUTTON_MOUSE_OUT;
	}
}

void Exit_button(SDL_Event *e,Lbutton &ExitButton, bool Menu)
{
    if (ExitButton.Inside(e, BIG))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			ExitButton.mCurrentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Menu = false;
			ExitButton.mCurrentSprite = BUTTON_MOUSE_OVER;
			break;
		}
	}
	else
	{
		ExitButton.mCurrentSprite = BUTTON_MOUSE_OUT;
	}
}

void Hekp_button(SDL_Event *e,Lbutton &HelpButton, bool Instruct)
{
    if(HelpButton.Inside(e,BIG))
    {
        switch(e->type)
        {
        case SDL_MOUSEMOTION:
            HelpButton.mCurrentSprite = BUTTON_MOUSE_OVER;
            break;
        case SDL_MOUSEBUTTONDOWN:
            Instruct = true;
            break;
        }
    }
    else
    {
        HelpButton.mCurrentSprite = BUTTON_MOUSE_OUT;
    }
}

void Render_play_button(Lbutton &PlayButton, GameBase gPlay)
{
                    SDL_Rect gPlay_Button[2];
                    gPlay_Button[0].x = 0;
					gPlay_Button[0].y = 0;
					gPlay_Button[0].w = 150;
					gPlay_Button[0].h = 98;

					gPlay_Button[1].x = 150;
					gPlay_Button[1].y = 0;
					gPlay_Button[1].w = 150;
					gPlay_Button[1].h = 98;

					SDL_Rect *current_Play_Button = &gPlay_Button[PlayButton.mCurrentSprite];

					PlayButton.render(g_screen, gPlay, current_Play_Button);

}

