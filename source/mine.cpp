#include "../header/mine.hpp"

Mine::Mine()
{
    yer_tutucu_isim = 'M';
    status = Null;
}
Mine::~Mine(){
    //bir şeyler eklerim bir ara aklıma gelirse
}
int Mine::getPointAmount()
{
    return s_point_amount;
}
int Mine::getStatus()
{
    return status;
}
void Mine::setStatus(MineStatus setstatus)
{
    status = setstatus;
}

Coords Mine::getCoords()
{
    return koordinat;
}

void Mine::setCoords(Coords setCoords)
{
    koordinat = setCoords;
}