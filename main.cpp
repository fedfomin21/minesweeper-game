#include "Game.h"
#include "utils.h"
#include <iostream>
#include <string>

int main() {
    printWelcome();
    
    int width = 9;
    int height = 9;
    int mineCount = 10;
    
    std::cout << "Default settings: 9x9 board with 10 mines\n";
    std::cout << "Do you want to change settings? (y/n): ";
    char choice;
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        width = getValidatedInt("Enter width (5-20): ", 5, 20);
        height = getValidatedInt("Enter height (5-20): ", 5, 20);
        int maxMines = (width * height) - 1;
        std::string prompt = "Enter number of mines (1-" + std::to_string(maxMines) + "): ";
        mineCount = getValidatedInt(prompt, 1, maxMines);
    }
    
    Game game(width, height, mineCount);
    game.run();
    
    std::cout << "\nThanks for playing!\n";
    return 0;
}
