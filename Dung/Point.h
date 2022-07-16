#pragma once
#include <iostream>
#include <string>
#include"mylib.h"
using namespace std;

#define PI 3.14

//convert from string to integer
int toInt(const string& s);

class Point {
protected:
	int m_x, m_y,m_color;
public:
	//default constructor
	Point();
	~Point();

	
	Point(int x, int y,int color);

	//copy constructor
	Point(Point& p);

	//return m_x value of Point object
	int getX() const;

	//return m_y value of Point object
	int getY() const;

	//set value for m_x of Point object
	void setX(int);

	//set value for m_y of Point object
	void setY(int);

	//set value for m_x, m_y of Point object
	void set(int, int);

	//calculate distance between 2 points
	static float distance(Point&, Point&);

	//calculate dot product between 2 points
	static int dotProduct(Point&, Point&);

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
};
