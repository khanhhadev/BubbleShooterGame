#ifndef BUBBLE_H
#define BUBBLE_H
#include "General.h"
#include "Point.h"
#include"mylib.h"
class Bubble
{
public:
	void fall();
	void setColor(COLOR);
	COLOR getColor() const;
	Bubble();
	Bubble(int, int, COLOR);
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
