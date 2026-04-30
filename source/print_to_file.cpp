#include "../header/print_to_file.hpp"
int file_printer_counter = 0;
void print_to_file(const Entity &e)
{

    std::ofstream dosya("ai/kayit.txt", std::ios::app);
    if (dosya.is_open())
    {
        dosya << "\n";
        file_printer_counter++;
        dosya << e.koordinat.x << "," << e.koordinat.y << "," << e.yer_tutucu_isim << std::endl;

        dosya.close();
    }
    else
    {
        std::cout << "Dosya açılamadı veya oluşturulamadı";
    }
}




void print_last_line(MineManager &mineManager)
{

    int size = mineManager.getCurrentMineSize()+1;
    if (size == file_printer_counter)
    {
        std::ofstream dosya("ai/kayit.txt", std::ios::app);
        if (dosya.is_open())
        {
            dosya << "\n";
            file_printer_counter++;
            dosya << "-------------------------------------------------" << std::endl;
            dosya.close();
        }
        else
        {
            std::cout << "Dosya açılamadı veya oluşturulamadı";
        }
        file_printer_counter = 0;
    }
}

void print_first_line(){
    if (file_printer_counter == 0)
    {
    
        std::ofstream dosya("ai/kayit.txt", std::ios::app);
        if (dosya.is_open())
        {
            dosya << "x,y,entity_name" << std::endl;
            dosya.close();
        }
        else
        {
            std::cout << "Dosya açılamadı veya oluşturulamadı";
        }
        
    }

}