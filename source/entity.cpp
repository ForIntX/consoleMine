#include "../header/entity.hpp"

int Entity::s_entity_num = 0;


int Entity::getEntityNum()
{
    // bu fonksiyonu const bir şekilde tanımlama sebebimiz entity ögesi çağırmadan kullanabilelim diye yani
    // Entity::getEntityNum() şeklinde çağrı yapabilelim diye

    return s_entity_num;
}

Entity::Entity()
{
    if (DEBUG)
    {
        print(isim + " öğesi oluşturuldu.");
        
    }
    
    s_entity_num++;
}
Entity::~Entity()
{
    if (DEBUG)
    {
        print(isim + " ögesi yok edildi.");
    
    }
    
    s_entity_num--;
}
void Entity::print(const std::string &string)
{
    std::cout << string << std::endl;
}
void Entity::print(const char *Char)
{
    std::cout << Char << std::endl;
}
void Entity::print(int Int)
{
    std::cout << Int << std::endl;
}