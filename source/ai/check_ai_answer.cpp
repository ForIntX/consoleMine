#include "../../header/ai/check_ai_answer.hpp"
Answers* answers = new Answers();
void check_the_answer(std::vector<char> yon, Game &game, Player &player)
{
    std::ofstream file(ai_result_file_name, std::ios::app);
    answers->movement = yon.size();
    if (file.is_open())
    {
        while (!yon.empty())
        {
            char ilk = yon.front();
            ai_plays(game, player, ilk);
            yon.erase(yon.begin());
        }
        answers->movement = answers->wrong_answer + answers->correct_answer + answers->empty_move + answers->unexpected_value;
        answers->total_train_point = (answers->correct_answer * 2) - (answers->wrong_answer * 2) - (answers->unexpected_value * 3) -(answers->empty_move * 1);
        answers->total_score = answers->ai_score + answers->total_train_point;
     
        file << "movement,total_train_point,total_score,ai_score"<<std::endl;
        file << answers->movement << "," << answers->total_train_point << "," << answers->total_score << "," <<answers->ai_score <<std::endl;
        file << "-------------------------------------------" << std::endl;
        file.close();
    }

    else
    {

        std::cerr << "Dosya açılamadı! Lütfen dosya yolunu kontrol edin." << std::endl;
    }
}