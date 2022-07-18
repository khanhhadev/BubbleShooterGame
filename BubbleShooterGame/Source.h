#pragma once
#include "General.h"
#include "LinkedList.h"
#include "GameInterface.h"
#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>

MODE mymode = WAIT;
PLAYMODE myplay;
LinkedList<Bubble> bubbleList;

//game mode navigation
void navigation()
{
	int key_input;
	do {
		hidecursor();
		startGame();
		char key = _getch();
		key_input = key;
		switch (_getch()) {
		case KEY_SPACE:
		{
			mymode = PLAY;
			myplay = NOTHING;
			clrscr();
			Shooter myShooter;
			GameInterface myGame;
			drawDScore();
			displayScore(0);
			thread newone = thread(std::bind(&GameInterface::createBubble, &myGame));
			thread new2 = thread(std::bind(&Shooter::shootercontrol, &myShooter));
			newone.join();
			new2.join();
			while (mymode == PLAY) {
			
			};
		}
			break;
		case KEY_X:
			return;
			break;
		default:
			break;
		}
	} while (true);

}
