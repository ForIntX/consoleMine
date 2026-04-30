// version alpha 0.1.2

#include <iostream>
#include <string>
#include <random>
class Game;
class Player;

// todo renk eklencek oyuna yakında
const std::string KIRMIZI = "\033[31m";
const std::string YESIL = "\033[32m";
const std::string SARI = "\033[33m";
const std::string MAVI = "\033[34m";
const std::string RESET = "\033[0m";

const int sizeX = 10;
const int sizeY = 10;
const int MapSize = sizeX * sizeY;
std::random_device rd;
std::mt19937 motor(rd());
std::uniform_int_distribution<int> dagilimX{0, sizeX - 1};
std::uniform_int_distribution<int> dagilimY{0, sizeY - 1};
const int max_iron_mine = 16;
const int max_copper_mine = 4;
const int MAX_MİNE = max_iron_mine + max_copper_mine;

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
    const int getEntityNum() // bu fonksiyonu const bir şekilde tanımlama sebebimiz entity ögesi çağırmadan kullanabilelim diye yani
    // Entity::getEntityNum() şeklinde çağrı yapabilelim diye
    {
        return s_entity_num;
    }

public:
    Coords koordinat;
    char yer_tutucu_isim = 'e';
    Entity()
    {
        print(isim + " öğesi oluşturuldu.");
        s_entity_num++;
    };
    ~Entity()
    {
        print(isim + " ögesi yok edildi.");
        s_entity_num--;
    };

    void print(const std::string &string)
    {
        std::cout << string << std::endl;
    }
    void print(const char *Char)
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
    Player()
    {
        skor = 0;
        std::string gecici_Isim = "Player" + std::to_string(Entity::getEntityNum());

        std::cout << "Lütfen İsminizi giriniz:";
        getline(std::cin, isim);
        if (isim.empty())
        {
            isim = gecici_Isim;
            print("Herhangi bir değer girmediniz bunun için isminiz:" + isim);
        }

        yer_tutucu_isim = isim[0];
    };
    
};

enum MineStatus
{
    Null = -3,
    Full,
    Used

};

class Mine : public Entity
{
private:
    Coords mineCoords;

protected:
    int s_point_amount;
    MineStatus status;

public:
    Mine()
    {
        yer_tutucu_isim = 'M';
        status = Null;
    }
    virtual ~Mine()
    {
    }
    int getPointAmount()
    {
        return s_point_amount;
    }
    int getStatus()
    {
        return status;
    }
    void setStatus(MineStatus setstatus)
    {
        status = setstatus;
    }
    Coords getCoords()
    {
        return mineCoords;
    }
    void setCoords(Coords setCoords)
    {
        mineCoords = setCoords;
    }
};

class CopperMine : public Mine
{
private:
public:
    CopperMine()
    {
        yer_tutucu_isim = 'c';
        s_point_amount = 1;
        
    }
};

class IronMine : public Mine
{
private:
public:
    IronMine()
    {
        yer_tutucu_isim = 'd';
        s_point_amount = 2;
    }
};

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
    MineManager()
    {
        Mine_array.coppermines = coppermines;
        Mine_array.ironmines = ironmines;
        current_mine_size = 0;
        Create_mine();
    }
    ~MineManager()
    {

    }
    void Create_mine()
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
       void Delete_mine(Mine &mine, int i)
    {
        
        if (mine.yer_tutucu_isim == 'c')
        {
            delete coppermines[i];
            coppermines[i] = nullptr;
            current_mine_size --;
        }
        if (mine.yer_tutucu_isim == 'd')
        {
            delete ironmines[i];
            ironmines[i] = nullptr;
            current_mine_size --;
        }
    }
    Mine_struct &getMines()
    {
        return Mine_array;
    }
  
   
    int getCurrentMineSize(){
        return current_mine_size;
    }
    void setCurrentMineSize(int size){
        current_mine_size = size;
    }
    
    
};


class Game
{
private:
    char game[sizeX][sizeY];
    const int &rows = sizeX;
    const int &cols = sizeY;
    int birinci_sayi = dagilimX(motor);
    int ikinci_sayi = dagilimY(motor);
    int move_count = 0;


public:
    Player player;
    MineManager mineManager;

    Game()
    {

        start_game();
        place_player(player, player.koordinat);
        place_mine(mineManager);
        print_game();
    }
    ~Game(){
        end_game();
    }

    void reset_game()
    {
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < cols; y++)
            {
                game[x][y] = '0';
            }
        }
    }

   
    void print_game()
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "\n\n";
        
        std::cout << "┌";
        for (int y = 0; y < cols; y++)
        {
            std::cout << "───";
            if (y < cols - 1)
                std::cout << "┬";
        }
        std::cout << "┐\n";
        for (int x = 0; x < rows; x++)
        {
            std::cout << "│";
            for (int y = 0; y < cols; y++)
            {
                
                    std::cout << " " << game[x][y] << " │";
                
            }
                std::cout << std::endl;
            if (x < rows -1 )
            {   
                std::cout << "├";
                for (int y = cols-1; y >= 0; y--)
                {
                    if (y!= cols -1 )
                    {
                        std::cout << "┼";
                    }
                    std::cout << "───";

                    
                }
                std::cout << "┤" <<std::endl;
                
            }
            
            
            
        }

        std::cout << "└";

         for (int y = cols - 1; y >= 0 ; y--)
            {
                if (y != cols - 1)
                {
                    std::cout << "┴";

                }
                std::cout << "───";
                        
                
            }
            std::cout << "┘" << std::endl;

        std::cout << "Skorunuz:" << player.skor << std::endl;
    }

    void start_game()
    {
        std::cout << "Oyun başlatılıyor....\n";
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < cols; y++)
            {

                if (y == cols - 1)
                {
                    game[x][y] = '0';
                    std::cout << game[x][y] << std::endl;
                }
                else
                {
                    game[x][y] = '0';
                    std::cout << game[x][y];
                }
            }
        }

        std::string info;
        std::cout << " Oyun hakkında bilgi almak için info yazınız. İstemiyorsanız bir tuşa basınız:\n";
        while (true)
        {
            std::cin >> info;
            if (info == "info")
            {
                Info();
                break;
            }
            else
            {
                break;
            }
        }

        std::cout << "Oyun Başlatıldı.";
    }

    void end_game(){
        int temp_iron_mine = IronMine().getPointAmount();
        int temp_copper_mine = CopperMine().getPointAmount();
        std::cout << "Tüm madenler toplandı.Toplam maden sayısı:" << mineManager.Temporary_copper_mine + mineManager.Temporary_iron_mine <<std::endl;
        std::cout << "Elde edilen toplam puan:" << player.skor  << std::endl;
        std::cout << "Bakır madeninden elde edilen puan:" << mineManager.Temporary_copper_mine * temp_copper_mine << std::endl;
        std::cout << "Demir madeninden elde edilen puan:" << mineManager.Temporary_iron_mine * temp_iron_mine << std::endl;
        std::cout << "Toplam hareket sayısı:" << move_count << std::endl;
    }

    void Info()
    {
        std::string temp;
        std::cout << "\nBu bir 2D mining oyunudur.\nOyunda İsminizin baş harfi sizin karakterinizi temsil eder.\nKarakterinizi hareket ettirmek için w,a,s,d kullanabilirsiniz.\nOyun içerisindeki madenler sırasıyla bakır(b) ve demirdir(d).\nDemir madenini toplayabilmek için bakır madeninden 10 tane toplamış olmanız gereklidir.\nOyun alanında mapta sınırlardan sağa sola yukarı ve aşağı gittiğinizde mapin devamı gelir ve geride bıraktığınız alan yeniden oluşturulur.\n(Maalesef kayıt sistemini bilmiyorum öğrendiğim zaman onu da güncelleyeceğim.)" << std::endl;
        std::cout << "kapatmak için bir tuşa basınız:";
        std::cin >> temp;
    }

    void place_player(Player &player, Coords coords) //! koordinatları boşuna içeri yollamışsın sonradan sil bunu
    {
        game[birinci_sayi][ikinci_sayi] = player.yer_tutucu_isim;
        player.koordinat.x = birinci_sayi;
        player.koordinat.y = ikinci_sayi;
    }

    // bu fonksiyon game objesi içerisinde playerı hareket ettirmeye yarıyor
    void move_player(Player &player, Coords coords, Game &oyun, Coords temp)
    {

        Coords old_coords = playercoords(temp);
        oyun.game[old_coords.x][old_coords.y] = '0';
        CheckMineAndGetPoints(coords, mineManager);
        oyun.game[coords.x][coords.y] = player.yer_tutucu_isim;
    }

    Coords playercoords(Coords coords)
    {
        return coords;
    }
    char getCell(int x, int y) const
    { // birazdan x ve y koordinatlarını alınca kullancaksın bunu
        return game[x][y];
    }

    void CheckMineAndGetPoints(Coords coords, MineManager &mineManager)
    {
        char cell = game[coords.x][coords.y];
        for (int i = 0; i < max_copper_mine; i++)
        {
            if (mineManager.getMines().coppermines[i] != nullptr && mineManager.getMines().coppermines[i]->getCoords().x == coords.x && mineManager.getMines().coppermines[i]->getCoords().y == coords.y)
            {
                player.skor += mineManager.getMines().coppermines[i]->getPointAmount();
                mineManager.Delete_mine(*mineManager.getMines().coppermines[i], i);
            
                
                break;
            }
        }

        for (int i = 0; i < max_iron_mine; i++)
        {
            if (mineManager.getMines().ironmines[i] != nullptr && mineManager.getMines().ironmines[i]->getCoords().x == coords.x && mineManager.getMines().ironmines[i]->getCoords().y == coords.y)
            {
                player.skor += mineManager.getMines().ironmines[i]->getPointAmount();
                mineManager.Delete_mine(*mineManager.getMines().ironmines[i], i);
                
            
                break;
            }
        }
    
    }

    /// @brief Bir madeni game objesi içerisine ekler ve aynı zamanda o madenin coords değerlerini set eder
    /// @param mineManager


    void place_mine(MineManager &mineManager)
// bu kodu refaktör et şu anda bu kodda sürekli kod tekrarları var gelecekte eklenecek yeni minelarda bu tekrarlar bize sıkıntı oluşturabilir.
    {
        MineStatus status = Full;
        Coords coords;
        int mine_size = mineManager.getCurrentMineSize();
        int iron_counter = 0;
        int copper_counter = 0;
        int random_X = dagilimX(motor);
        int random_Y = dagilimY(motor);
        int temp_copper_mine = max_copper_mine;
        int temp_iron_mine = max_iron_mine;
        if (temp_copper_mine >= MapSize)
        {
            temp_copper_mine = MapSize / 4;
        }
        if (temp_iron_mine >= MapSize)
        {
            temp_iron_mine = MapSize / 8;
        }
        mineManager.Temporary_copper_mine = temp_copper_mine;
        mineManager.Temporary_iron_mine = temp_iron_mine;

        while (temp_copper_mine > copper_counter)
        {

            if (game[random_X][random_Y] == '0')
            {
                CopperMine *current_copper_mine = mineManager.getMines().coppermines[copper_counter];
                game[random_X][random_Y] = current_copper_mine->yer_tutucu_isim;
                coords.x = random_X;
                coords.y = random_Y;
                current_copper_mine->setCoords(coords);
                copper_counter++;
                mine_size++;
                std::cout << "çalıştı";
            }
            else
            {
                random_X = dagilimX(motor);
                random_Y = dagilimY(motor);
            }
        }
        while (temp_iron_mine > iron_counter)
        {

            if (game[random_X][random_Y] == '0')
            {
                IronMine *current_iron_mine = mineManager.getMines().ironmines[iron_counter];
                game[random_X][random_Y] = current_iron_mine->yer_tutucu_isim;
                coords.x = random_X;
                coords.y = random_Y;
                current_iron_mine->setCoords(coords);
                iron_counter++;
                mine_size++;
            }
            else
            {
                random_X = dagilimX(motor);
                random_Y = dagilimY(motor);
            }
        }
        for (int i = copper_counter; i < max_copper_mine; i++)
        {
            mineManager.Delete_mine(*mineManager.getMines().coppermines[i], i);
        }
        for (int i = iron_counter; i < max_iron_mine; i++)
        {
            mineManager.Delete_mine(*mineManager.getMines().ironmines[i], i);
        }
        mineManager.setCurrentMineSize(mine_size);

        std::cout << "demir:" << iron_counter << std::endl;
        std::cout << "demir: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_iron_mine << std::endl;
        std::cout << "bakir:" << copper_counter << std::endl;
        std::cout << "bakir: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_copper_mine << std::endl;
        std::cout << "tüm madenler:" << iron_counter + copper_counter << std::endl;
        std::cout << "tüm madenler: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_copper_mine + mineManager.Temporary_iron_mine << std::endl;

    }
   
    int getMoveCounter(){
        return move_count;
    }
    void setMoveCounter(int count){
        move_count = count;
    }
   
    void Move(Player &player);
};



// bu fonksiyon playerın hareketini sağlıyor.
void Game::Move(Player &player)
{
    char yon;
    int mine_size = mineManager.getCurrentMineSize();
    Coords temp;
    Coords p_koordinat = this->playercoords(player.koordinat);
    while (mine_size > 0)
    {
    mine_size = mineManager.getCurrentMineSize();
    if (mine_size == 0)
    {
        break;;
    }
    
        std::cout << "mine size:" << mine_size;


        std::cout << "Gidilecek yönü giriniz:";

        std::cin >> yon;
        move_count++;

        if (p_koordinat.y == 0 && yon == 'a')
        {
            std::cout << "sola hareket edilemez. bir daha değer giriniz.\n";
            continue;
        }
        if (p_koordinat.y == sizeY - 1 && yon == 'd')
        {
            std::cout << "sağa hareket edilemez. bir daha değer giriniz.\n";
            continue;
        }
        if (p_koordinat.x == sizeX - 1 && yon == 's')
        {
            std::cout << "aşağı hareket edilemez. bir daha değer giriniz.\n";
            continue;
        }
        if (p_koordinat.x == 0 && yon == 'w')
        {
            std::cout << "yukarı hareket edilemez. bir daha değer giriniz.\n";
            continue;
        }
        else
        {
            if (yon == 'd')
            {
                temp = p_koordinat;
                p_koordinat.y = p_koordinat.y + 1;

                this->move_player(player, this->playercoords(p_koordinat), *this, temp);
                this->print_game();
            }
            else if (yon == 'a')
            {
                temp = p_koordinat;
                p_koordinat.y = p_koordinat.y - 1;
                this->move_player(player, this->playercoords(p_koordinat), *this, temp);
                this->print_game();
            }
            else if (yon == 's')
            {
                temp = p_koordinat;
                p_koordinat.x = p_koordinat.x + 1;
                this->move_player(player, this->playercoords(p_koordinat), *this, temp);
                this->print_game();
            }
            else if (yon == 'w')
            {
                temp = p_koordinat;
                p_koordinat.x = p_koordinat.x - 1;

                this->move_player(player, this->playercoords(p_koordinat), *this, temp);
                this->print_game();
            }
        }
    }
}

int Entity::s_entity_num = 0; // şu allahın cezası şeyi tanımla
int MineManager::s_current_copper_mine = 0;
int MineManager::s_current_iron_mine = 0;
int main()
{

    Game oyun;
    oyun.Move(oyun.player);
}