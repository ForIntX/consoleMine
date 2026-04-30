#include "../../header/ai/check_ai_movement.hpp"
void is_true_ai_movement(int temp_player_skor, Player& player){
    if (temp_player_skor == player.skor)
            {
                answers->empty_move++;
            }
            else{ 
               if (temp_player_skor==2)
               {
                temp_player_skor+=2;
                answers->correct_answer++;
                answers->ai_score+=2;
               }
               else{
                temp_player_skor++;
                answers->correct_answer++;
                answers->ai_score++;
               }
            }
}