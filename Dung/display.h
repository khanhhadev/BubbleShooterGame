#include<iostream>
#include"mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include<windows.h>
#include"graphics.h"
#define MAX 300
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_SPACE 32
#define KEY_ESC 27
using namespace std;

void drawWall(){
	SetColor(226);
	for(int x = 30; x <= 45; x++){
		gotoXY(x,1);
		cout << "x";
		gotoXY(x,15);
		cout << "x";
	}
	for(int y = 1; y <= 14; y++){
		gotoXY(30,y);
		cout << "x";
		gotoXY(45,y);
		cout << "x";
	}
}
void drawDScore(){
	SetColor(226);
	for(int x = 50; x <= 70; x++){
		gotoXY(x,1);
		cout << "-";
		gotoXY(x,3);
		cout << "-";
	}
	for(int y = 1; y <= 3; y++){
		char a = 179;
		gotoXY(50,y);
		cout << a;
		gotoXY(70,y);
		cout << a;
	}
}
void displayScore(int score){
	drawDScore();
	gotoXY(52,2);
	cout << "SCORE: " << score;
}
void drawButtonStart(){
	SetColor(226);
	for(int x = 30; x <= 55; x++){
		gotoXY(x,6);
		cout << "#";
		gotoXY(x,8);
		cout << "#";
	}
	for(int y = 6; y <= 8; y++){
		gotoXY(30,y);
		cout << "#";
		gotoXY(55,y);
		cout << "#";
	}
	for(int x1 = 30; x1 <= 55; x1++){
		gotoXY(x1,10);
		cout << "#";
		gotoXY(x1,12);
		cout << "#";
	}
	for(int y1 = 10; y1 <= 12; y1++){
		gotoXY(30,y1);
		cout << "#";
		gotoXY(55,y1);
		cout << "#";
	}
	
}
void startGame(){
	gotoXY(34,3);
	char a[] = "BUBBLE SHOOTER" ;
	for(int i=0;i<strlen(a);i++){
		int color[7] = {1,2,3,4,5,6,7};
		int r = rand() % 7 ;
		SetColor(color[r]);
		cout << a[i];
	}
    SetColor(9);	
	drawButtonStart();
	gotoXY(33,7);
	cout << "START GAME = SPACE";
	gotoXY(37,11);
	cout << "EXIT = ESC";	
}

void endGame(){
	clrscr();
	gotoXY(30,9);
	SetColor(2);
	cout << "---GAME OVER---";
}
