#include "../header/mine_manager.hpp"
int MineManager::s_current_copper_mine = 0;
int MineManager::s_current_iron_mine = 0;
MineManager::MineManager()
{
    Mine_array.coppermines = coppermines;
    Mine_array.ironmines = ironmines;
    current_mine_size = 0;
    Create_mine();
}
MineManager::~MineManager()
{
    // İleride pointer temizliği için kullanılacak
}
void MineManager::Create_mine()
{
    int i = 0;

    while (i < MAX_MİNE)
    {
        if (s_current_copper_mine < max_copper_mine)
        {
            coppermines[s_current_copper_mine] = new CopperMine();
            s_current_copper_mine++;
        }
        if (s_current_iron_mine < max_iron_mine)
        {
            ironmines[s_current_iron_mine] = new IronMine();
            s_current_iron_mine++;
        }
        i++;
    }
}

void MineManager::Delete_mine(Mine &mine, int i)
{

    if (mine.yer_tutucu_isim == 'c')
    {
        delete coppermines[i];
        coppermines[i] = nullptr;
        current_mine_size--;
    }
    if (mine.yer_tutucu_isim == 'd')
    {
        delete ironmines[i];
        ironmines[i] = nullptr;
        current_mine_size--;
    }
}

Mine_struct &MineManager::getMines()
{
    return Mine_array;
}

int MineManager::getCurrentMineSize()
{
    return current_mine_size;
}
void MineManager::setCurrentMineSize(int size)
{
    current_mine_size = size;
}


