
#include "Graphic.h"
#include "General.h"

#define MAX 300
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_SPACE 32
#define KEY_ESC 27
using namespace std;


void drawWall() {
	SetColor(226);
	for (int x = 30; x <= 45; x++) {
		gotoXY(x, 1, (char)MULTI);
		gotoXY(x, 15, (char)MULTI);
	}
	for (int y = 1; y <= 14; y++) {
		gotoXY(30, y, (char)MULTI);
		gotoXY(45, y, (char)MULTI);
	}
}
void drawDScore() {
	SetColor(226);
	for (int x = 50; x <= 70; x++) {
		gotoXY(x, 1, (char)HORIZONTAL);
		gotoXY(x, 3, (char)HORIZONTAL);
	}
	for (int y = 1; y <= 3; y++) {
		gotoXY(50, y, (char)VERTICAL);
		gotoXY(70, y, (char)VERTICAL);
	}
}
void displayScore(int score) {
	drawDScore();
	gotoXY(52, 2, '\n');
	cout << "SCORE: " << score;
}
void drawButtonStart() {
	SetColor(226);
	for (int x = 30; x <= 55; x++) {
		gotoXY(x, 6, (char)HASHTAG);
		gotoXY(x, 8, (char)HASHTAG);
	}
	for (int y = 6; y <= 8; y++) {
		gotoXY(30, y, (char)HASHTAG);
		gotoXY(55, y, (char)HASHTAG);
	}
	for (int x1 = 30; x1 <= 55; x1++) {
		gotoXY(x1, 10, (char)HASHTAG);
		gotoXY(x1, 12, (char)HASHTAG);
	}
	for (int y1 = 10; y1 <= 12; y1++) {
		gotoXY(30, y1, (char)HASHTAG);
		gotoXY(55, y1, (char)HASHTAG);
	}

}
void startGame() {
	gotoXY(34, 3, '\0');
	char a[] = "BUBBLE SHOOTER";
	for (int i = 0; i < strlen(a); i++) {
		int color[7] = { 1,2,3,4,5,6,7 };
		int r = rand() % 7;
		SetColor(color[r]);
		cout << a[i];
	}
	SetColor(9);
	drawButtonStart();
	gotoXY(33, 7, '\0');
	cout << "START GAME = SPACE";
	gotoXY(37, 11, '\0');
	cout << "EXIT = ESC";
}
/*
void endGame(){
	clrscr();
	gotoXY(30,9);
	SetColor(2);
	cout << "---GAME OVER---";
}*/
