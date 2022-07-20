#pragma once
#include "General.h"
#include "LinkedList.h"
#include "GameInterface.h"
#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>

extern MODE mymode;
extern PLAYMODE myplay;
extern LinkedList<Bubble> bubbleList;

//selection keys after losing the game
void loseGame()
{
	char key;
	do
	{
		key = _getch();
		switch (key) {
		case KEY_SPACE:
		{
			mymode = WAIT;/*
			system("cls");
			hidecursor();
			startGame();*/
			return;
		}
			break;
		case KEY_ESC:
		{
			mymode = EXIT; //exit game
			return;
		}
		break;
		default:
			break;
		}
	} while (key != KEY_SPACE);
}

//game mode navigation
void navigation()
{
	char key;
	do {
		system("cls");
		hidecursor();
		startGame();
		key = _getch();

		switch (key) {
		case KEY_SPACE:
		{
 			mymode = PLAY;
			myplay = NOTHING;

			bubbleList.clear();
			GameInterface myGame;
			Shooter myShooter;
			thread newone = thread(std::bind(&GameInterface::createBubble, &myGame)); //create board bubble
			thread new2 = thread(std::bind(&Shooter::shootercontrol, &myShooter)); // shooter bubble

			newone.join();
			new2.join();
			while (mymode == PLAY) 
			{
			};
			if (mymode == LOSE)
			{
				endGame();
				displayScore(myShooter.getScore());
				loseGame();
			}
		}
			break;
		case KEY_ESC:
			mymode = EXIT;
			return;
			break;
		default:
			break;
		}
	} while (mymode != EXIT);

}
