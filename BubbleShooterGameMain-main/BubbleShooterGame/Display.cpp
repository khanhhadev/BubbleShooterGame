
#include "Graphic.h"
#include "General.h"
#include <string>
using namespace std;

//int ReadFileModeOpen(string fileName)
//{
//	ifstream fsFile();
//	fsFile.open(fileName, ios::in);
//	int n;
//	if (fsFile >> n) {
//		return n;
//	}
//	fsFile.close();
//}
//void WriteFileMode(char* file_name, int score)
//{
//	if (file_name != NULL)
//	{
//		fstream data_file;
//		data_file.open(file_name, ios::out);
//		data_file << score;
//		data_file.close();
//	}
//}

//draw wall main game 
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

//draw wall display score 
void drawDScore() {
	for (int x = 1; x <= 17; x++) {
		gotoXY(x, 1, (char)HORIZONTAL, GREEN);
		gotoXY(x, 3, (char)HORIZONTAL);
	}
	for (int y = 1; y <= 3; y++) {
		gotoXY(1, y, (char)VERTICAL);
		gotoXY(17, y, (char)VERTICAL);
	}
}

//display score
void displayScore(int score) {
	gotoXY(4, 2, '\0', GREEN);
	cout << "SCORE: " << score;
}

//draw wall game interface 
void drawButtonStart() {
	for (int x = 10; x <= 35; x++) {
		gotoXY(x, 6, (char)HASHTAG, GREEN);
		gotoXY(x, 8, (char)HASHTAG);
	}
	for (int y = 6; y <= 8; y++) {
		gotoXY(10, y, (char)HASHTAG);
		gotoXY(35, y, (char)HASHTAG);
	}
	for (int x1 = 10; x1 <= 35; x1++) {
		gotoXY(x1, 10, (char)HASHTAG);
		gotoXY(x1, 12, (char)HASHTAG);
	}
	for (int y1 = 10; y1 <= 12; y1++) {
		gotoXY(10, y1, (char)HASHTAG);
		gotoXY(35, y1, (char)HASHTAG);
	}

}

//draw button start game and exit button
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

//end game
void endGame(){
	system("cls");
	drawWall();
	drawDScore();
	gotoXY(21, 9, '\0', 2);
	cout << "--GAME OVER--";
	gotoXY(2, 4, '\0', 2);
	cout << "Press SPACE \n  to replay";
}
