#include "../../header/gamer/player_plays.hpp"
bool player_plays(Game& game,Player& player,char yon)
{
    Coords temp;
    Coords p_koordinat = game.playercoords(player.koordinat);
    
    if (p_koordinat.y == 0 && yon == 'a')
    {
        std::cout << "sola hareket edilemez. bir daha değer giriniz.\n";
        return false;
        
    }
    else if (p_koordinat.y == sizeY - 1 && yon == 'd')
    {
        std::cout << "sağa hareket edilemez. bir daha değer giriniz.\n";
        return false;

        
    }
    else if (p_koordinat.x == sizeX - 1 && yon == 's')
    {
        std::cout << "aşağı hareket edilemez. bir daha değer giriniz.\n";
        return false;

    }
    else if (p_koordinat.x == 0 && yon == 'w')
    {
        std::cout << "yukarı hareket edilemez. bir daha değer giriniz.\n";
        return false;

        
    }
   
    
  
        if (yon == 'd')
        {
            temp = p_koordinat;
            p_koordinat.y = p_koordinat.y + 1;
            

            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            
            game.print_game();
            return true;
        }
        else if (yon == 'a')
        {
            temp = p_koordinat;
            p_koordinat.y = p_koordinat.y - 1;
            game.move_player(player, game.playercoords(p_koordinat), game, temp);
        game.print_game();
            return true;

        }
        else if (yon == 's')
        {
            temp = p_koordinat;
            p_koordinat.x = p_koordinat.x + 1;
            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            game.print_game();
            return true;

        }
        else if (yon == 'w')
        {
            temp = p_koordinat;
            p_koordinat.x = p_koordinat.x - 1;

            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            game.print_game();
            return true;

        }
     else
    {
        std::cout << "Beklenmeyen bir değer girdiniz lütfen düzeltiniz girilen değer:" <<yon <<std::endl;
        return false;
    }
}
