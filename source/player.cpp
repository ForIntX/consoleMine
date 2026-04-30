#include "../header/player.hpp"
Player::Player()
{
    skor = 0;
    std::string gecici_Isim = "Player" + std::to_string(Entity::getEntityNum());

   if (bypass_cin) {
        isim = "AI_Bot"; 
    } else {
        std::cout << "Lütfen isminizi giriniz:";
        getline(std::cin, isim);
        if (isim.empty()) {
            isim = gecici_Isim;
            print("Herhangi bir değer girmediniz bunun için isminiz:" + isim);
        }
    }
    yer_tutucu_isim = isim[0];
}