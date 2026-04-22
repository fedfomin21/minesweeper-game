#include "utils.h"
#include <iostream>
#include <limits>

int getValidatedInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between " 
                      << min << " and " << max << ".\n";
        } else {
            std::cin.ignore();
            return value;
        }
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printWelcome() {
    std::cout << "================================\n";
    std::cout << "     MINESWEEPER GAME           \n";
    std::cout << "================================\n";
    std::cout << "Try to clear the board without\n";
    std::cout << "detonating any mines!\n\n";
}
