#pragma once
#include "all.hpp"
#include "../header/print_to_file.hpp"
#include "../header/is_ai_playing.hpp"
#include "../header/read_file.hpp"
#include "../header/ai/check_ai_answer.hpp"
#include "gamer/player_plays.hpp"
#include "ai/check_ai_answer.hpp"




struct ColAndRows
{
    int row;
    int col;
};

class Game
{
private:
    char game[sizeX][sizeY];
    const int &rows = sizeX;
    const int &cols = sizeY;
    int birinci_sayi = dagilimX(motor);
    int ikinci_sayi = dagilimY(motor);
    int move_count = 0;

public:
    Player player;
    MineManager mineManager;
    Renderer renderer;
    Game();
    ~Game();
    ColAndRows getColAndRow()const;

    void reset_game();

    void print_game();
    void start_game();
    void end_game();
    void Info();

    void place_player(Player &player, Coords coords);

    void move_player(Player &player, Coords coords, Game &oyun, Coords temp);

    Coords playercoords(Coords coords);
    char getCell(int x, int y) const;

    void CheckMineAndGetPoints(Coords coords, MineManager &mineManager);

    /// @brief Bir madeni game objesi içerisine ekler ve aynı zamanda o madenin coords değerlerini set eder
    /// @param mineManager
    void place_mine(MineManager &mineManager);
    int getMoveCounter();
    void setMoveCounter(int count);

    void Move(Player &player);
};

