// version alpha 0.1.2
#pragma once

#include <iostream>
#include <string>
#include <random>
#include <fstream>
//debugger
extern bool DEBUG;

class Game;
class Player;

// todo renk eklencek oyuna yakında
const std::string KIRMIZI = "\033[31m";
const std::string YESIL = "\033[32m";
const std::string SARI = "\033[33m";
const std::string MAVI = "\033[34m";
const std::string RESET = "\033[0m";


// --- HARİTA VE MADEN SABİTLERİ ---
const int sizeX = 4;
const int sizeY = 4;
const int MapSize = sizeX * sizeY;
const int max_iron_mine = 16;
const int max_copper_mine = 4;
const int MAX_MİNE = max_iron_mine + max_copper_mine;



// --- RASTGELE SAYI ÜRETİCİLERİ ---
extern std::random_device rd;
extern std::mt19937 motor;
extern std::uniform_int_distribution<int> dagilimX;
extern std::uniform_int_distribution<int> dagilimY;


// --- dosyaya yazdırma ---
extern int file_printer_counter;
extern bool e_is_ai_playing;

// --- ai ile alakalı şeyler
extern int turn_count;


//--- file names ----
extern std::string ai_result_file_name;
extern std::string ai_incomplete_file_name ;
extern bool bypass_cin;