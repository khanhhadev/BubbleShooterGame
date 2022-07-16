#ifndef BUBBLE_H
#define BUBBLE_H
#include "General.h"
#include "Point.h"
#include "LinkedList.h"
class Bubble
{
public:
	void fall();
	void setColor(COLOR);
	COLOR getColor() const;
	Point& getXY() const;
	void down();

	Bubble();
	Bubble(Point& P);
	Bubble(int x, int y);
	Bubble(int x, int y, COLOR);
	Bubble(Bubble& Obj);
	~Bubble();

	bool operator==(Bubble& Obj);
	bool operator==(const Bubble& Obj);
	//assignment operator = oveloading
	Bubble& operator= (Bubble& Obj);
	//assignment operator = oveloading
	Bubble& operator= (const Bubble& Obj);
private:
	//refrence to list of Point belonging to Bubble
	Point* m_bubbleptr;
	COLOR m_color;
};

#endif // !BUBBLE_H