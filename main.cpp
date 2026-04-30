#include "header/all.hpp"
#include <cstring> 

int main(int argc, char* argv[]) {
    // Eğer program "ai_mode" şifresiyle çalıştırılırsa bypass aktif olur!
    if (argc > 1 && std::strcmp(argv[1], "ai_mode") == 0) {
        bypass_cin = true;
        e_is_ai_playing = true; 
    }

    Game oyun;
    oyun.Move(oyun.player);
    return 0;
}