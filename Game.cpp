#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(int w, int h, int mines) 
    : board(w, h, mines)
    , state(GameState::PLAYING)
    , minesInitialized(false)
    , width(w)
    , height(h)
    , mineCount(mines) {}

void Game::showHelp() const {
    std::cout << "\n=== CONTROLS ===\n";
    std::cout << "o <row> <col>  - Open cell\n";
    std::cout << "f <row> <col>  - Flag/Unflag cell\n";
    std::cout << "h              - Show this help\n";
    std::cout << "q              - Quit game\n";
    std::cout << "================\n\n";
}

bool Game::isValidPosition(int row, int col) const {
    return row >= 0 && row < height && col >= 0 && col < width;
}

void Game::handleInput(int row, int col, char action) {
    if (!isValidPosition(row, col)) {
        std::cout << "Invalid position! Try again.\n";
        return;
    }
    
    if (action == 'f') {
        board.toggleFlag(row, col);
    } 
    else if (action == 'o') {
        if (!minesInitialized) {
            std::cout << "Placing mines...\n";
            board.initMines(row, col);
            minesInitialized = true;
        }
        
        if (board.isFlagged(row, col)) {
            std::cout << "Remove flag first!\n";
            return;
        }
        
        if (board.isMine(row, col)) {
            state = GameState::LOSE;
        } else {
            board.revealCell(row, col);
            if (board.allSafeCellsRevealed()) {
                state = GameState::WIN;
            }
        }
    }
}

void Game::displayStatus() const {
    if (state == GameState::WIN) {
        std::cout << "\n🎉 CONGRATULATIONS! YOU WON! 🎉\n";
    } else if (state == GameState::LOSE) {
        std::cout << "\n💥 BOOM! YOU LOST! 💥\n";
    }
}

void Game::run() {
    std::cout << "\n=== WELCOME TO MINESWEEPER ===\n";
    std::cout << "Grid size: " << width << "x" << height << " with " << mineCount << " mines\n";
    showHelp();
    
    char action;
    int row;
    int col;
    
    while (state == GameState::PLAYING) {
        board.print();
        std::cout << "Enter command (h for help): ";
        std::cin >> action;
        
        if (action == 'q') {
            std::cout << "Quitting game...\n";
            break;
        } else if (action == 'h') {
            showHelp();
            continue;
        } else if (action == 'o' || action == 'f') {
            std::cin >> row >> col;
            handleInput(row, col, action);
        } else {
            std::cout << "Unknown command!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    if (state == GameState::LOSE) {
        board.revealAllMines();
        board.print();
    } else if (state == GameState::WIN) {
        board.print();
    }
    
    displayStatus();
}
