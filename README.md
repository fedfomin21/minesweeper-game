# Minesweeper (Сапёр)

Классическая игра "Сапёр" в консоли на C++. Нужно открыть все клетки, не содержащие мины, и пометить флажками все мины.

## Сборка и запуск

### Способ 1: Прямая компиляция (рекомендуется)

```bash
# Клонируйте или скачайте проект
cd minesweeper-game

# Скомпилируйте
g++ -std=c++11 main.cpp Board.cpp Game.cpp utils.cpp -o minesweeper

# Запустите
./minesweeper

### Способ 2: CMake

```bash
# Клонируйте или скачайте проект
cd minesweeper-game

# Введите
cd minesweeper-game
mkdir build && cd build
cmake ..
make
./minesweeper
