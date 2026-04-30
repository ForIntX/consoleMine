#include "../header/consts.hpp"
//debugger
bool DEBUG= false;

std::random_device rd;
std::mt19937 motor(rd());
std::uniform_int_distribution<int> dagilimX{0, sizeX - 1};
std::uniform_int_distribution<int> dagilimY{0, sizeY - 1};


//file names
std::string ai_result_file_name = "ai/results.txt"; 
std::string ai_incomplete_file_name = "ai/incomplete.txt";



//ai_bypass
bool bypass_cin =false;