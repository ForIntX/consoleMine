#pragma once
#include "consts.hpp"

struct Coords
{
    int x;
    int y;
};



class Entity
{
private:
    static int s_entity_num;

protected:
    std::string isim = "Entity";
    static int getEntityNum();
public:
    Coords koordinat;
    char yer_tutucu_isim = 'e';
    Entity();
    ~Entity();

    void print(const std::string &string);
    void print(const char *Char);
    void print(int Int);
};
