#include "../header/game.hpp"

Game::Game()
{
    start_game();
    print_first_line();
    place_player(player, player.koordinat);
    place_mine(mineManager);
    print_game();
}
Game::~Game()
{
    end_game();
}
void Game::reset_game()
{
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            game[x][y] = '0';
        }
    }
}

void Game::print_game()
{
    renderer.print_game(*this);
}

void Game::start_game()
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
    if (!bypass_cin)
    { 
        std::cout << " Oyun hakkında bilgi almak için info yaz istemiyorsanız bir tuşa basınız:\n";
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
    }

    int turn_count = ai_play();

    std::cout << "Oyun Başlatıldı.";
}
void Game::end_game()
{
    int temp_iron_mine = IronMine().getPointAmount();
    int temp_copper_mine = CopperMine().getPointAmount();
    std::cout << "Tüm madenler toplandı.Toplam maden sayısı:" << mineManager.Temporary_copper_mine + mineManager.Temporary_iron_mine << std::endl;
    std::cout << "Elde edilen toplam puan:" << player.skor << std::endl;
    std::cout << "Bakır madeninden elde edilen puan:" << mineManager.Temporary_copper_mine * temp_copper_mine << std::endl;
    std::cout << "Demir madeninden elde edilen puan:" << mineManager.Temporary_iron_mine * temp_iron_mine << std::endl;
    std::cout << "Toplam hareket sayısı:" << move_count << std::endl;
}
void Game::Info()
{
    std::string temp;
    std::cout << "\nBu bir 2D mining oyunudur.\nOyunda İsminizin baş harfi sizin karakterinizi temsil eder.\nKarakterinizi hareket ettirmek için w,a,s,d kullanabilirsiniz.\nOyun içerisindeki madenler sırasıyla bakır(b) ve demirdir(d).\nDemir madenini toplayabilmek için bakır madeninden 10 tane toplamış olmanız gereklidir.\nOyun alanında mapta sınırlardan sağa sola yukarı ve aşağı gittiğinizde mapin devamı gelir ve geride bıraktığınız alan yeniden oluşturulur.\n(Maalesef kayıt sistemini bilmiyorum öğrendiğim zaman onu da güncelleyeceğim.)" << std::endl;
    std::cout << "kapatmak için bir tuşa basınız:";
    std::cin >> temp;
}
void Game::place_player(Player &player, Coords coords) //! koordinatları boşuna içeri yollamışsın sonradan sil bunu
{
    game[birinci_sayi][ikinci_sayi] = player.yer_tutucu_isim;
    player.koordinat.x = birinci_sayi;
    player.koordinat.y = ikinci_sayi;
    print_to_file(player);
}

// bu fonksiyon game objesi içerisinde playerı hareket ettirmeye yarıyor
void Game::move_player(Player &player, Coords coords, Game &oyun, Coords temp)
{

    Coords old_coords = playercoords(temp);
    oyun.game[old_coords.x][old_coords.y] = '0';
    CheckMineAndGetPoints(coords, mineManager);
    oyun.game[coords.x][coords.y] = player.yer_tutucu_isim;
    player.koordinat = coords;
}
Coords Game::playercoords(Coords coords)
{
    return coords;
}

char Game::getCell(int x, int y) const
{ // birazdan x ve y koordinatlarını alınca kullancaksın bunu
    return game[x][y];
}
void Game::CheckMineAndGetPoints(Coords coords, MineManager &mineManager)
{
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

void Game::place_mine(MineManager &mineManager)
// bu kodu refaktör et şu anda bu kodda sürekli kod tekrarları var gelecekte eklenecek yeni minelarda bu tekrarlar bize sıkıntı oluşturabilir.
{
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
    for (int i = 0; i < temp_copper_mine; i++)
    {
        Entity *copper_mine = mineManager.getMines().coppermines[i];
        print_to_file(*copper_mine);
    }
    for (int i = 0; i < temp_iron_mine; i++)
    {
        Entity *iron_mine = mineManager.getMines().ironmines[i];
        print_to_file(*iron_mine);
        std::cout << "maden koordinatları" << iron_mine->koordinat.x << iron_mine->koordinat.y;
    }
    print_last_line(mineManager);

    // std::cout << "demir:" << iron_counter << std::endl;
    // std::cout << "demir: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_iron_mine << std::endl;
    // std::cout << "bakir:" << copper_counter << std::endl;
    // std::cout << "bakir: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_copper_mine << std::endl;
    // std::cout << "tüm madenler:" << iron_counter + copper_counter << std::endl;
    // std::cout << "tüm madenler: fonksiyonla elde edilen sonuc:" << mineManager.Temporary_copper_mine + mineManager.Temporary_iron_mine << std::endl;
}

int Game::getMoveCounter()
{
    return move_count;
}

void Game::setMoveCounter(int count)
{
    move_count = count;
}
// bu fonksiyon playerın hareketini sağlıyor.
void Game::Move(Player &player)
{
    char yon;
    int mine_size = mineManager.getCurrentMineSize();

    while (mine_size > 0)
    {
        mine_size = mineManager.getCurrentMineSize();
        if (mine_size == 0)
        {
            break;
        }
        if (!e_is_ai_playing)
        {
            std::cout << "mine size:" << mine_size << std::endl;

            std::cout << "Gidilecek yönü giriniz:";

            std::cin >> yon;

            bool stop = player_plays(*this, player, yon);
            if (!stop)
            {
                move_count++;
                continue;
            }
            else
            {
                move_count++;
                continue;
            }
        }
        else
        {

            std::vector<char> yon = read_file(e_is_ai_playing);
            move_count = yon.size();

            if (yon.empty())
            {
                std::cout << "Ai değer üretememiş" << std::endl;

                break;
            }
            else
            {
                check_the_answer(yon, *this, player);
                if (mineManager.getCurrentMineSize() > 0)
                {
                    std::ofstream incomp_file(ai_incomplete_file_name, std::ios::app);
                    if (incomp_file.is_open())
                    {
                        incomp_file << "Move_count,remaining_mines" << std::endl;
                        incomp_file << move_count << "," << mineManager.getCurrentMineSize() << std::endl;
                        incomp_file << "----------------------------------" << std::endl;
                        incomp_file << "x,y,entity_name" << std::endl;
                        for (int i = 0; i < mineManager.getCurrentMineSize(); i++)
                        {
                            if (mineManager.getMines().coppermines[i] != nullptr)
                            {

                                incomp_file << mineManager.getMines().coppermines[i]->getCoords().x << "," << mineManager.getMines().coppermines[i]->getCoords().y << "," << mineManager.getMines().coppermines[i]->yer_tutucu_isim << std::endl;
                            }
                        }
                        for (int i = 0; i < mineManager.getCurrentMineSize(); i++)
                        {
                            if (mineManager.getMines().ironmines[i] != nullptr)
                            {

                                incomp_file << mineManager.getMines().ironmines[i]->getCoords().x << "," << mineManager.getMines().ironmines[i]->getCoords().y << "," << mineManager.getMines().ironmines[i]->yer_tutucu_isim << std::endl;
                            }
                        }
                        incomp_file << "----------------------------------" << std::endl;
                        incomp_file.close();
                    }
                    else
                    {
                        std::cerr << "The incomplete file could not be opened.";
                    }
                }

                break;
            }
        }
    }
}
ColAndRows Game::getColAndRow() const
{

    ColAndRows temp;
    temp.row = rows;
    temp.col = cols;
    return temp;
}
