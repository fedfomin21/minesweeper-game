# Minesweeper (Сапёр)

Классическая игра "Сапёр" в консоли на C++. Нужно открыть все клетки, не содержащие мины, и пометить флажками все мины.

## Сборка и запуск

### Способ 1: Прямая компиляция (рекомендуется)

# Клонируйте или скачайте проект
```bash
cd minesweeper-game
```

# Скомпилируйте
```bash
g++ -std=c++11 main.cpp Board.cpp Game.cpp utils.cpp -o minesweeper
```

# Запустите
```bash
./minesweeper
```

### Способ 2: CMake

# Клонируйте или скачайте проект
```bash
cd minesweeper-game
```

# Введите
```bash
cd minesweeper-game
mkdir build && cd build
cmake ..
make
./minesweeper
```
