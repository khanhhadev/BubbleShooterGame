#include "Source.h"
//#include "graphic.h"

//#include "mylib.h"
LinkedList<Point> pointList;
LinkedList<Bubble> bubbleList; 
Shooter myShooter;

int main()
{
	GameInterface MyGame;
	thread newone = thread(std::bind(&GameInterface::createBubble, &MyGame));
	thread new2 = thread(shooter);
	newone.join();
	new2.join();
	_getch();
	return 0;
}