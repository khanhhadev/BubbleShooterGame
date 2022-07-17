#pragma once
#include "Bubble.h"
#include "General.h"
#include "LinkedList.h"
#include "Point.h"
#include "GameInterface.h"
#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_UP 72

extern Shooter myShooter;
void shooter() {
	//int i = 38;
	int value;
	do {
		char key = _getch();
		value = key;
		switch (_getch()) {

		case KEY_UP:
			myShooter.shooting();
			break;
		case KEY_LEFT:
			myShooter.left();
			break;
		case KEY_RIGHT:
			myShooter.right();
			break;
		}
	} while (value != KEY_X);

}
