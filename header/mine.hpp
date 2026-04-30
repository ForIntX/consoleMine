#pragma once
#include "entity.hpp"
enum MineStatus
{
    Null = -3,
    Full,
    Used

};

class Mine : public Entity
{
private:

protected:
    int s_point_amount;
    MineStatus status;

public:
    Mine();
    virtual ~Mine();
    int getPointAmount();
    int getStatus();
    void setStatus(MineStatus setstatus);
    Coords getCoords();
    void setCoords(Coords setCoords);
};
