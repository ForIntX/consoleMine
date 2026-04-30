#pragma once
#include "mines/copper_mine.hpp"
#include "mines/iron_mine.hpp"

struct Mine_struct
{
    CopperMine **coppermines;
    IronMine **ironmines; // diziler bir işaretçi olduğu için böyle yaptık
};

class MineManager
{
private:
    CopperMine *coppermines[max_copper_mine]; // neden pointer yaptım bunu araştır cidden bilmiyorum
    IronMine *ironmines[max_iron_mine];
    static int s_current_copper_mine;
    static int s_current_iron_mine;
    int current_mine_size;

protected:
public:
    int Temporary_copper_mine;
    int Temporary_iron_mine;

    Mine_struct Mine_array;
    MineManager();
    ~MineManager();
    void Create_mine();

    void Delete_mine(Mine &mine, int i);

    Mine_struct& getMines();
    int getCurrentMineSize();
    void setCurrentMineSize(int size);
};
