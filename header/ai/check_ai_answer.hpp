#pragma once
#include "../all.hpp"
#include "../../header/ai/ai_plays.hpp"
void check_the_answer(std::vector<char> yon,Game& game,Player& player);

 struct Answers
{
int wrong_answer = 0;
int correct_answer = 0;
int empty_move = 0;
int unexpected_value=0;
int total_train_point = 0;
int ai_score = 0;
int total_score = 0;
int movement;
};
extern Answers* answers;