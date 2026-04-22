#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>

Board::Board(int w, int h, int minesCount) 
    : width(w), height(h), mineCount(minesCount) {
    
    board.resize(height, std::vector<char>(width, '#'));
    mines.resize(height, std::vector<bool>(width, false));
    revealed.resize(height, std::vector<bool>(width, false));
    flagged.resize(height, std::vector<bool>(width, false));
}

void Board::initMines(int firstRow, int firstCol) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            mines[i][j] = false;
        }
    }
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int placedMines = 0;
    
    while (placedMines < mineCount) {
        int row = std::rand() % height;
        int col = std::rand() % width;
        
        bool isAdjacentToFirst = (std::abs(row - firstRow) <= 1 && std::abs(col - firstCol) <= 1);
        
        if (!mines[row][col] && !(row == firstRow && col == firstCol) && !isAdjacentToFirst) {
            mines[row][col] = true;
            ++placedMines;
        }
    }
}

int Board::countAdjacentMines(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width) {
                if (mines[newRow][newCol]) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void Board::revealCell(int row, int col) {
    if (revealed[row][col] || flagged[row][col]) {
        return;
    }
    
    revealed[row][col] = true;
    
    if (countAdjacentMines(row, col) == 0) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width) {
                    if (!revealed[newRow][newCol] && !mines[newRow][newCol]) {
                        revealCell(newRow, newCol);
                    }
                }
            }
        }
    }
}

void Board::toggleFlag(int row, int col) {
    if (!revealed[row][col]) {
        flagged[row][col] = !flagged[row][col];
    }
}

bool Board::isMine(int row, int col) const {
    return mines[row][col];
}

bool Board::isRevealed(int row, int col) const {
    return revealed[row][col];
}

bool Board::isFlagged(int row, int col) const {
    return flagged[row][col];
}

int Board::getMineCount() const {
    return mineCount;
}

int Board::getFlaggedCount() const {
    int count = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (flagged[i][j]) {
                ++count;
            }
        }
    }
    return count;
}

char Board::getCellChar(int row, int col) const {
    if (flagged[row][col]) {
        return 'F';
    }
    if (!revealed[row][col]) {
        return '#';
    }
    if (mines[row][col]) {
        return '*';
    }
    
    int adjacentMines = countAdjacentMines(row, col);
    if (adjacentMines == 0) {
        return ' ';
    }
    return static_cast<char>('0' + adjacentMines);
}

bool Board::allSafeCellsRevealed() const {
    int safeCells = width * height - mineCount;
    int revealedSafe = 0;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (revealed[i][j] && !mines[i][j]) {
                ++revealedSafe;
            }
        }
    }
    
    return revealedSafe == safeCells;
}

void Board::print() const {
    std::cout << "\n   ";
    for (int i = 0; i < width; ++i) {
        std::cout << i % 10 << " ";
    }
    std::cout << "\n   ";
    for (int i = 0; i < width; ++i) {
        std::cout << "--";
    }
    std::cout << "\n";
    
    for (int i = 0; i < height; ++i) {
        std::cout << i % 10 << " | ";
        for (int j = 0; j < width; ++j) {
            std::cout << getCellChar(i, j) << " ";
        }
        std::cout << "|\n";
    }
    
    std::cout << "   ";
    for (int i = 0; i < width; ++i) {
        std::cout << "--";
    }
    std::cout << "\n";
    
    std::cout << "Mines left: " << mineCount - getFlaggedCount() << "\n";
}

void Board::revealAllMines() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (mines[i][j]) {
                revealed[i][j] = true;
            }
        }
    }
}
