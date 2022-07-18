
#include "Graphic.h"
#include "General.h"
using namespace std;


void drawWall() {
	for (int x = SCREEN_COLUMN_BEGIN; x <= SCREEN_COLUMN_END; x++) {
		gotoXY(x, SCREEN_ROW_BEGIN, (char)MULTI, GREEN);
		gotoXY(x, SCREEN_ROW_END, (char)MULTI, GREEN);
	}
	for (int y = SCREEN_ROW_BEGIN; y <= SCREEN_ROW_END; y++) {
		gotoXY(SCREEN_COLUMN_BEGIN, y, (char)MULTI, GREEN);
		gotoXY(SCREEN_COLUMN_END, y, (char)MULTI, GREEN);
	}
}
void drawDScore() {
	for (int x = 1; x <= 17; x++) {
		gotoXY(x, 1, (char)HORIZONTAL, GREEN);
		gotoXY(x, 3, (char)HORIZONTAL, GREEN);
	}
	for (int y = 1; y <= 3; y++) {
		gotoXY(1, y, (char)VERTICAL, GREEN);
		gotoXY(17, y, (char)VERTICAL, GREEN);
	}
}
void displayScore(int score) {
	gotoXY(4, 2, '\0', GREEN);
	cout << "SCORE: " << score;
}
void drawButtonStart() {
	for (int x = 10; x <= 35; x++) {
		gotoXY(x, 6, (char)HASHTAG, GREEN);
		gotoXY(x, 8, (char)HASHTAG, GREEN);
	}
	for (int y = 6; y <= 8; y++) {
		gotoXY(10, y, (char)HASHTAG, GREEN);
		gotoXY(35, y, (char)HASHTAG, GREEN);
	}
	for (int x1 = 10; x1 <= 35; x1++) {
		gotoXY(x1, 10, (char)HASHTAG, GREEN);
		gotoXY(x1, 12, (char)HASHTAG, GREEN);
	}
	for (int y1 = 10; y1 <= 12; y1++) {
		gotoXY(10, y1, (char)HASHTAG, GREEN);
		gotoXY(35, y1, (char)HASHTAG, GREEN);
	}

}
void startGame() {
	char a[] = "BUBBLE SHOOTER";
	for (int i = 0; i < strlen(a); i++) {
		int color[7] = { 1,2,3,4,5,6,7 };
		int r = rand() % 7;

		gotoXY(14 + i, 3, a[i], (WORD)color[r]);
	}
	SetColor(9);
	drawButtonStart();
	gotoXY(13, 7, '\0', GREEN);
	cout << "START GAME = SPACE";
	gotoXY(17, 11, '\0', GREEN);
	cout << "EXIT = ESC";
}

void endGame(){
	clrscr();
	gotoXY(30,9, '\0', 2);
	cout << "---GAME OVER---";
}
