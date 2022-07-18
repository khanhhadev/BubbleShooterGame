#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include "General.h"
#include <mutex>
using namespace std;
#define PI 3.14

class Point {
protected:
	int m_x, m_y;
	COLOR m_color;
	CHARACTER m_char;
public:
	//default constructor
	Point();

	Point(int x, int y, CHARACTER mychar);

	Point(int x, int y, CHARACTER mychar, COLOR color);

	//copy constructor
	Point(Point& p);

	//destructor
	~Point();
	//return m_x value of Point object
	int getX() const;

	//return m_y value of Point object
	int getY() const;

	//return color value of Point object
	COLOR getColor() const;

	//set value for m_x of Point object
	void setX(int);

	//set value for m_y of Point object
	void setY(int);

	//set value for m_x, m_y of Point object
	void set(int, int);

	void draw();

	void erase();

	static void swap(Point&, Point&);

	//calculate distance between 2 points
	static float distance(Point&, Point&);

	//calculate dot product between 2 points
	static int dotProduct(Point&, Point&);

	//assignment operator = oveloading
	Point& operator= (Point& p);

	//assignment operator = oveloading
	Point& operator= (const Point& p);

	//addition operator + oveloading
	Point operator+ (Point& p);

	//subtraction operator - oveloading
	Point operator- (Point& p);

	//multiplication operator * overloading
	Point operator* (int p);

	//devision operator / overloading
	Point operator/ (int p);

	//assignment operator += overloading
	Point& operator+= (Point& p);

	//assignment operator -= overloading
	Point& operator-= (Point& p);

	//assignment operator *= overloading
	Point& operator*= (int p);

	//assignment operator /= overloading
	Point& operator/= (int p);

	bool operator> (Point& p);

	bool operator>= (Point& p);

	bool operator< (Point& p);

	bool operator<= (Point& p);

	bool operator== (Point& p);

	bool operator== (const Point& p);

};
#endif