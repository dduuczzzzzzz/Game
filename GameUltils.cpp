#include "GameUltils.h"

bool Check_collision(MainObject &p_player, Enemy &enemy_, Enemy &enemy2_)
{
            bool collide;
            //check collide
            if(p_player.getPosX() + 30 -16 >= enemy2_.getPos__X2() && p_player.getPosX() + 12  <= enemy2_.getPos__X2() + 57)
            {
                if(p_player.getPosY() + 15>= enemy2_.getPos__Y2())
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
            return collide;
}

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

void Text_func(std::string &a, GameBase text, TTF_Font* font, SDL_Renderer *g_screen, int x, int y)
{
    text.SetColor();
    text.SetText(a);
    text.LoadFromRenderText(font, g_screen);
    text.RenderText(g_screen, x, y);
}

std::string GetHSfromFile(std::string path)
{
    std::fstream HighScoreFile;
    std::string highscore;

    HighScoreFile.open(path, std::ios::in);
    HighScoreFile >> highscore;

    return highscore;
}

void GetHighscore(std::string path, const int& score, const std::string & old_high_score)
{
    int oldHighScore = 0;
	std::fstream HighScoreFile;
	std::string newHighScore;
	std::stringstream ConvertToInt(old_high_score);

	HighScoreFile.open(path, std::ios::out);

	ConvertToInt >> oldHighScore;
	if (score > oldHighScore)
	{
		oldHighScore = score;
	}
	newHighScore = std::to_string(oldHighScore);

	HighScoreFile << newHighScore;
}
