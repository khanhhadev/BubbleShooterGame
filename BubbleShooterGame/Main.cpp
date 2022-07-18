#include "Source.h"
#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include <atomic>
#include <windows.h> 
#include <string>

void SetScreen(int x, int y);
void hidecursor(void);


LinkedList<Point> pointList;
LinkedList<Bubble> bubbleList; 
Shooter myShooter;

bool shootingCheck(false);

int main()
{
	hidecursor();
	SetScreen(50, 50);
	SetConsoleTitle(L"BUBBLE SHOOTER");

	GameInterface MyGame;

	thread newone = thread(std::bind(&GameInterface::createBubble, &MyGame));
	thread new2 = thread(&shooter);
	newone.join();
	new2.join();
	_getch();
	return 0;
	_getch();
}


// set size console
void SetScreen(int x, int y) {
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(cons, 0, font);
	font->dwFontSize.X = x;
	font->dwFontSize.Y = y;
	SetCurrentConsoleFontEx(cons, 0, font);
}
//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
//----hidden pointer in console----------
void hidecursor(void) {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
