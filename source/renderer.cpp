#include "../header/all.hpp"
#include "../header/engine/renderer.hpp"

void Renderer::print_game(const Game &g)
{
    ColAndRows map = g.getColAndRow();

    // std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[1;1H";
    std::cout << "\n\n";
    std::cout << "┌";
    for (int y = 0; y < map.col; y++)
    {
        std::cout << "───";
        if (y < map.col - 1)
            std::cout << "┬";
    }
    // std::cout << "┐\n";
    std::cout << "┐\033[K\n";
    for (int x = 0; x < map.row; x++)
    {
        std::cout << "│";
        for (int y = 0; y < map.col; y++)
        {

            std::cout << " " << g.getCell(x, y) << " │";
        }
        // std::cout << std::endl;
        std::cout << "\033[K" << std::endl;
        if (x < map.row - 1)
        {
            std::cout << "├";
            for (int y = map.col - 1; y >= 0; y--)
            {
                if (y != map.col - 1)
                {
                    std::cout << "┼";
                }
                std::cout << "───";
            }
            // std::cout << "┤" << std::endl;
            std::cout << "┤\033[K" << std::endl;
        }
    }

    std::cout << "└";

    for (int y = map.col - 1; y >= 0; y--)
    {
        if (y != map.col - 1)
        {
            std::cout << "┴";
        }
        std::cout << "───";
    }
    // std::cout << "┘" << std::endl;
    std::cout << "┘\033[K" << std::endl;

    // std::cout << "Skorunuz:" << g.player.skor << std::endl;
    std::cout << "Skorunuz:" << g.player.skor << "\033[K" << std::endl;
    std::cout << "\033[J"; 

}







void print_middle(char **grid, int rows, int cols)
{
    for (int x = 0; x < rows; x++)
    {
        std::cout << "│";
        for (int y = 0; y < cols; y++)
        {

            std::cout << " " << grid[x][y] << " │";
        }
        std::cout << std::endl;
        if (x < cols - 1)
        {
            std::cout << "├";
            for (int y = cols - 1; y >= 0; y--)
            {
                if (y != cols - 1)
                {
                    std::cout << "┼";
                }
                std::cout << "───";
            }
            std::cout << "┤" << std::endl;
        }
    }
}
