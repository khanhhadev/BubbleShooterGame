#ifndef DISPLAY_H
#define DISPLAY_H
#include "Graphic.h"
#include "General.h"
#include <fstream>
#include <iostream>

#define KEY_NONE	-1

void drawWall();
void drawDScore();
void displayScore(int score);
void drawButtonStart();
void startGame();
void endGame();
int  ReadFileModeOpen(char* fileName);
void WriteFileMode(char* file_name, int score);

#endif // DISPLAY_H