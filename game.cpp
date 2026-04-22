#include <iostream>
#include <string>
#include <random>

class Game;
class Player;


//todo renk eklencek oyuna yakında
const std::string KIRMIZI = "\033[31m";
const std::string YESIL   = "\033[32m";
const std::string SARI    = "\033[33m";
const std::string MAVI    = "\033[34m";
const std::string RESET   = "\033[0m";

const int sizeX = 5;
const int sizeY = 5;
std::random_device rd;
std::mt19937 motor(rd());
std::uniform_int_distribution<int> dagilim{0,4};
const int max_iron_mine = 2;
const int max_copper_mine = 4;



 struct Coords{
    int x;
    int y;
};




class Entity
{
private:
    static int s_entity_num;
protected:


std::string isim = "Entity";
const int getEntityNum()//bu fonksiyonu const bir şekilde tanımlama sebebimiz entity ögesi çağırmadan kullanabilelim diye yani
//Entity::getEntityNum() şeklinde çağrı yapabilelim diye
{
    return s_entity_num;
}
public:
    char yer_tutucu_isim = 'e';
    Entity(){
        print(isim + " öğesi oluşturuldu.");
        s_entity_num++;
        
    };
    ~Entity(){
        print(isim + " ögesi yok edildi.");
        s_entity_num --;

    };

    void print(const std::string& string){
        std::cout << string << std::endl;
    }
    void print(const char * Char)
    {
        std::cout << Char << std::endl;
    }
    void print(int Int)
    {
        std::cout << Int << std::endl;
    }
   
    
};





class Player : public Entity
{
private:

public:
    int skor;
    Player(){
        skor = 0;
        std::string gecici_Isim = "Player" +std::to_string(Entity::getEntityNum());
        
        std::cout <<"Lütfen İsminizi giriniz:";
        getline(std::cin,isim);
        if (isim.empty())
        {
            isim = gecici_Isim;
            print("Herhangi bir değer girmediniz bunun için isminiz:"+isim);
            
        }
        
        yer_tutucu_isim =  isim[0];
    

    };
    void Move(Game& game, Player& player);
    void CollectMine(Game& game, Player& player);
    
};














class Mine : public Entity
{
private:

protected:
static int s_point_amount;
    
public:
Mine(){
    yer_tutucu_isim = 'M';
}
  
};



class CopperMine : public Mine
{
private:

public:
CopperMine(){
    yer_tutucu_isim = 'c';
    s_point_amount = 1;
}
  
};


class IronMine : public Mine
{
private:
public:
IronMine(){
    yer_tutucu_isim = 'd';
    s_point_amount = 2;
}
   
};
















class Game{
    private:
    char game[sizeX][sizeY];
    const int& rows = sizeX;
    const int & cols = sizeY;
    int birinci_sayi = dagilim(motor);
    int ikinci_sayi = dagilim(motor);
    
    public:
    Coords koordinat;
    Player player;
    CopperMine mine;
    IronMine mine2;
    Game(){
       
    start_game();
    place_player(player,koordinat);
    place_mine(mine,player);
    place_mine(mine2,player);
    std::cout << "\n\n\n\n";
    print_game();

    }

    void reset_game(){
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < cols; y++)
            {
                game[x][y] = '0';
            }
            
        }
        
    }

    void print_game(){
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < cols; y++)
            {
            
            
                if (y==cols - 1)
                {
                    std::cout << game[x][y]<<std::endl;
                }
                else{
                    std::cout << game[x][y];
                }
            
            }
            
        }
        
    }

    void start_game(){
        std::cout << "Oyun başlatılıyor....\n";
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < cols; y++)
            {
            
                if (y==cols - 1)
                {
                    game[x][y]='0';
                    std::cout << game[x][y]<<std::endl;
                }
                else{
                    game[x][y]='0';
                    std::cout << game[x][y];
                }
            }
            
        }
       
        std::cout << "Oyun başlatıldı. Oyun hakkında bilgi almak için info yazınız.\n";
    }

    void info(){
        std::cout << "\nBu bir 2D mining oyunudur.\nOyunda İsminizin baş harfi sizin karakterinizi temsil eder.\nKarakterinizi hareket ettirmek için w,a,s,d kullanabilirsiniz.\nOyun içerisindeki madenler sırasıyla bakır(b) ve demirdir(d).\nDemir madenini toplayabilmek için bakır madeninden 10 tane toplamış olmanız gereklidir.\nOyun alanında mapta sınırlardan sağa sola yukarı ve aşağı gittiğinizde mapin devamı gelir ve geride bıraktığınız alan yeniden oluşturulur.\n(Maalesef kayıt sistemini bilmiyorum öğrendiğim zaman onu da güncelleyeceğim.)"<<std::endl;
        

    }
    void place_player(Player& player,Coords coords){
    game[birinci_sayi][ikinci_sayi]=player.yer_tutucu_isim;
    koordinat.x = birinci_sayi;
    koordinat.y = ikinci_sayi;

    }

    //bu fonksiyon game objesi içerisinde playerı hareket ettirmeye yarıyor
    void move_player(Player& player,Coords coords,Game& oyun,Coords temp){
        
        Coords old_coords = playercoords(temp);
        std::cout << "Temp:" << temp.x<<temp.y << std::endl;
        std::cout << "Coords:" << coords.x<<coords.y << std::endl;
        std::cout <<"[" <<  old_coords.x << old_coords.y << "]\n";
        oyun.game[old_coords.x][old_coords.y] = '0';
        oyun.game[coords.x][coords.y] = player.yer_tutucu_isim;
        

    }

    Coords playercoords(Coords coords){
        return coords;

        
    }
    char getCell(int x, int y) const {//birazdan x ve y koordinatlarını alınca kullancaksın bunu
        return game[x][y];}




















    void place_mine(Mine& mine,Player& player){
    int yerlesen_mine = 0;


    if (mine.yer_tutucu_isim == 'd')
    {
        yerlesen_mine = 0;
        while (yerlesen_mine<max_iron_mine)
        {
        
        int rastgele_X = dagilim(motor);
        int rastgele_Y = dagilim(motor); 
        if (game[rastgele_X][rastgele_Y]!='0')
        {
            continue;
        }
        else{
            
            game[rastgele_X][rastgele_Y] = mine.yer_tutucu_isim;
            yerlesen_mine++;
        }

        }

    }


    else if(mine.yer_tutucu_isim == 'c'){
    yerlesen_mine = 0;
    while (yerlesen_mine<max_copper_mine)
        {
        
        int rastgele_X = dagilim(motor);
        int rastgele_Y = dagilim(motor); 
        if (game[rastgele_X][rastgele_Y]!='0')
        {
        continue;
            
        }
        else {
            game[rastgele_X][rastgele_Y] = mine.yer_tutucu_isim;
            yerlesen_mine++;
        }
        }



    }
    }
 
    
    
   
   
};





//Playerın Puanını ayarlıyor
void Player::CollectMine(Game& game, Player& player){
    std::cout << "şimdilik böyle git atcam";
}



//bu fonksiyon playerın hareketini sağlıyor.
    void Player::Move(Game& game,Player& player){
        char yon;
        Coords temp;
        Coords p_koordinat = game.playercoords(game.koordinat);
        while (true)
        {
        
            std::cout << "Gidilecek yönü giriniz:";
            std::cin >> yon;
            
            if (p_koordinat.y==0 && yon == 'a')
            {
                std::cout <<"sola hareket edilemez. bir daha değer giriniz.\n";
                continue;
            }
            else if(p_koordinat.y == 4 && yon == 'd'){
            std::cout <<"sağa hareket edilemez. bir daha değer giriniz.\n";
                continue;
            }
            else if(p_koordinat.x == 4 && yon == 's'){
            std::cout <<"aşağı hareket edilemez. bir daha değer giriniz.\n";
                continue;
            }else if(p_koordinat.x == 0 && yon == 'w'){
                std::cout <<"yukarı hareket edilemez. bir daha değer giriniz.\n";
                continue;
            }
            else{
                if (yon == 'd')
                {
                    temp = p_koordinat;
                    p_koordinat.y= p_koordinat.y + 1;
                    game.move_player(player,game.playercoords(p_koordinat),game,temp);
                    game.print_game();
                    // std::cout << p_koordinat.y;

                
                }
                else if(yon == 'a')
                {
                    temp = p_koordinat;
                    p_koordinat.y = p_koordinat.y - 1;
                    game.move_player(player,game.playercoords(p_koordinat),game,temp);
                    game.print_game();
                    // std::cout << p_koordinat.y;


                }
                else if(yon == 's')
                {
                    temp = p_koordinat;
                    p_koordinat.x = p_koordinat.x + 1 ;
                    game.move_player(player,game.playercoords(p_koordinat),game,temp);
                    game.print_game();
                    // std::cout << p_koordinat.y;



                }
                else if(yon == 'w'){
                    temp = p_koordinat;
                    p_koordinat.x = p_koordinat.x - 1;
    
                    game.move_player(player,game.playercoords(p_koordinat),game,temp);
                    game.print_game();
                    // std::cout << p_koordinat.y;



                }
                
            }
        }

    }





int Entity::s_entity_num = 0;// şu allahın cezası şeyi tanımla
int Mine::s_point_amount = 0;
int main(){
  
    Game oyun;
    oyun.player.Move(oyun,oyun.player);
    
    

}