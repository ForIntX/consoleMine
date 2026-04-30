#include "../header/is_ai_playing.hpp"
int ai_play(){

if (bypass_cin) {
        return 1; 
    }
char ans;
int ai_turn_count;
std::cout <<"Oyunu Yapa Zeka'nın oynamasını istiyorsanız lütfen Y giriniz. Devam etmek için herhangi bir tuşa basınız.";
std::cin >> ans;
if (ans == 'y' || ans == 'Y')
{
    std::cout << "Ai'ın arka arkaya kaç tur oynamasını istiyorsunuz:";
    std::cin >> ai_turn_count;
    e_is_ai_playing = true;
    std::cout << "Ai " << ai_turn_count << " farklı oyun için çalışacak."<<std::endl;
    return ai_turn_count;

    
}
else{
    e_is_ai_playing = false;
    return 0;
}
}




