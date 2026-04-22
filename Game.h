#ifndef GAME_H
#define GAME_H

#include "Board.h"

enum class GameState {
    PLAYING,
    WIN,
    LOSE
};

class Game {
private:
    Board board;
    GameState state;
    bool minesInitialized;
    int width;
    int height;
    int mineCount;

public:
    Game(int w, int h, int mines);
    
    void run();
    void handleInput(int row, int col, char action);
    void displayStatus() const;
    GameState getState() const { return state; }
    
private:
    void showHelp() const;
    bool isValidPosition(int row, int col) const;
};

#endif
