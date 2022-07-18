#pragma once 
#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include <windows.h> 
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include "General.h"

void gotoXY(int x, int y, char a, WORD color);
void SetColor(WORD color);
// set size console
void SetScreen(int x, int y);
void clrscr();
void hidecursor(void);
#endif 