#include "GameUltils.h"





void Draw_EndGame(GameBase endgame1, GameBase endgame2,  TTF_Font *font)
{
    std::string end_game1 = "YOU LOSE !!!!";
    std::string end_game2 = "Press SPACE to replay or ESC to quit game !!!";
    endgame1.SetColor();
    endgame2.SetColor();

    endgame1.SetText(end_game1);
    endgame2.SetText(end_game2);

    endgame1.LoadFromRenderText(font, g_screen);
    endgame2.LoadFromRenderText(font, g_screen);

    endgame1.RenderText(g_screen, 430, 350);
    endgame2.RenderText(g_screen, 100 , 500);

}

