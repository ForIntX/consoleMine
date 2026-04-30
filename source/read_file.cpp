#include "../header/read_file.hpp"
bool e_is_ai_playing = false;
std::vector<char> read_file(bool is_ai_playing)
{
    std::ifstream dosya("ai/girdi.txt");
    if (is_ai_playing)
    {

        if (dosya.is_open())
        {
            char letter;
            std::vector<char>letters;

            while (dosya.get(letter))
            {
            letters.push_back(letter);
            }
            dosya.close();
            return letters;

        }
        else
        {
            std::cerr << "Dosya açılamadı! Lütfen dosya yolunu kontrol edin." << std::endl;
            
        }
    }
    return std::vector<char>();

}


