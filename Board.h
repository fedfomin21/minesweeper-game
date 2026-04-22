#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdlib>

class Board {
private:
    int width;
    int height;
    int mineCount;
    std::vector<std::vector<char>> board;
    std::vector<std::vector<bool>> mines;
    std::vector<std::vector<bool>> revealed;
    std::vector<std::vector<bool>> flagged;

    int countAdjacentMines(int row, int col) const;

public:
    Board(int w, int h, int minesCount);
    
    void initMines(int firstRow, int firstCol);
    void revealCell(int row, int col);
    void toggleFlag(int row, int col);
    bool isMine(int row, int col) const;
    bool isRevealed(int row, int col) const;
    bool isFlagged(int row, int col) const;
    int getMineCount() const;
    int getFlaggedCount() const;
    char getCellChar(int row, int col) const;
    bool allSafeCellsRevealed() const;
    
    void print() const;
    void revealAllMines();
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif
