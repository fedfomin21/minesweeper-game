#ifndef UTILS_H
#define UTILS_H

#include <string>

int getValidatedInt(const std::string& prompt, int min, int max);
void clearScreen();
void printWelcome();

#endif
