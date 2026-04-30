#include "../../header/ai/ai_plays.hpp"
void ai_plays(Game& game,Player& player,char yon)
{
    Coords temp;
    Coords p_koordinat = game.playercoords(player.koordinat);
    int temp_player_skor = player.skor;
    
    if (p_koordinat.y == 0 && yon == 'a')
    {
        std::cout << "sola hareket edilemez. bir daha değer giriniz.\n";
        answers->wrong_answer++;
        return;
        
    }
    else if (p_koordinat.y == sizeY - 1 && yon == 'd')
    {
        std::cout << "sağa hareket edilemez. bir daha değer giriniz.\n";
        answers->wrong_answer++;
        return;

        
    }
    else if (p_koordinat.x == sizeX - 1 && yon == 's')
    {
        std::cout << "aşağı hareket edilemez. bir daha değer giriniz.\n";
        answers->wrong_answer++;
        return;
        

    }
    else if (p_koordinat.x == 0 && yon == 'w')
    {
        std::cout << "yukarı hareket edilemez. bir daha değer giriniz.\n";
        answers->wrong_answer++;
        return;

        
    }
   
    
  
        if (yon == 'd')
        {
            temp = p_koordinat;
            p_koordinat.y = p_koordinat.y + 1;
            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            is_true_ai_movement(temp_player_skor,player);
            
            
            
            
            game.print_game();
        }
        else if (yon == 'a')
        {
            temp = p_koordinat;
            p_koordinat.y = p_koordinat.y - 1;
            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            is_true_ai_movement(temp_player_skor,player);

            
            game.print_game();

        }
        else if (yon == 's')
        {
            temp = p_koordinat;
            p_koordinat.x = p_koordinat.x + 1;
            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            is_true_ai_movement(temp_player_skor,player);

            game.print_game();

        }
        else if (yon == 'w')
        {
            temp = p_koordinat;
            p_koordinat.x = p_koordinat.x - 1;

            game.move_player(player, game.playercoords(p_koordinat), game, temp);
            is_true_ai_movement(temp_player_skor,player);

            game.print_game();

        }
     else
    {
        std::cout << "Beklenmeyen bir değer girdiniz lütfen düzeltiniz girilen değer:" <<yon <<std::endl;
        answers->unexpected_value++;

        return;
    }
}
