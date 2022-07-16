#include "Point.h"
#include <math.h>
#include"mylib.h"

//convert from string to integer
int toInt(const string& s)
{
	int Result = 0;
	int n = s.length();
	int con = (s[0] == '-') ? -1 : 1;
	int i = (con == -1) ? 1 : 0;
	for (; i < n; i++)
	{
		Result *= pow(10, i - ((con == -1) ? 1 : 0));
		Result += s[i] - '0';
	}
	Result *= con;
	return Result;
}

//default constructor
Point::Point()
{
	
	gotoXY((short)getX(),(short)getY());
	cout << "O";
};

Point::~Point()
{
	gotoXY((short)getX(),(short)getY());
	cout << '\0';
};

Point::Point(int x, int y,int color):m_x(x), m_y(y),m_color(color)
{
	SetColor(color);
};

//copy constructor
Point::Point(Point& p):m_x(p.m_x), m_y(p.m_y)
{

};

//return m_x value of Point object
int Point::getX() const
{
	return m_x;
};

//return m_y value of Point object
int Point::getY() const
{
	return m_y;
};

//set value for m_x of Point object
void Point::setX(int value)
{
	m_x = value;
};

//set value for m_y of Point object
void Point::setY(int value)
{
	m_y = value;
};

//set value for m_x, m_y of Point object
void Point::set(int x, int y)
{
	m_x = x;
	m_y = y;
};

//calculate distance between 2 points
float Point::distance(Point& pA, Point& pB)
{
	return sqrt((pB.m_x - pA.m_x) * (pB.m_x - pA.m_x) + (pB.m_y - pA.m_y) * (pB.m_y - pA.m_y));
};

//calculate dot product between 2 points
int Point::dotProduct(Point& pA, Point& pB)
{
	return (pA.m_x * pB.m_y + pA.m_y * pB.m_x);
};

//addition operator + oveloading 
Point Point::operator+ (Point& p)
{
	Point Result;
	Result.m_x = m_x + p.m_x;
	Result.m_y = m_y + p.m_y;
	return Result;
};

//subtraction operator - oveloading
Point Point::operator- (Point& p)
{
	Point Result;
	Result.m_x = m_x - p.m_x;
	Result.m_y = m_y - p.m_y;
	return Result;
};

//multiplication operator * overloading
Point Point::operator* (int p)
{
	Point Result;
	Result.m_x = m_x * p;
	Result.m_y = m_y * p;
	return Result;
};

//devision operator / overloading
Point Point::operator/ (int p)
{
	Point Result;
	if (p != 0)
	{
		Result.m_x = m_x / p;
		Result.m_y = m_y / p;
	}
	return Result;
};

//assignment operator += overloading
Point& Point::operator+= (Point& p)
{
	m_x = m_x + p.m_x;
	m_y = m_y + p.m_y;
	return *this;
};

//assignment operator -= overloading
Point& Point::operator-= (Point& p)
{
	m_x = m_x - p.m_x;
	m_y = m_y - p.m_y;
	return *this;
};

//assignment operator *= overloading
Point& Point::operator*= (int p)
{
	m_x = m_x * p;
	m_y = m_y * p;
	return *this;
};

//assignment operator /= overloading
Point& Point::operator/= (int p)
{
	if (p != 0)
	{
		m_x = m_x / p;
		m_y = m_y / p;
	}
	return *this;
};


bool Point::operator> (Point& p)
{
	if (m_x > p.m_x) return true;
	else if (m_x == p.m_x) return (m_y > p.m_y);
	return false;
}

bool Point::operator< (Point& p)
{
	if (m_x > p.m_x) return true;
	else if (m_x == p.m_x) return (m_y > p.m_y);
	return false;
};

bool Point::operator== (Point& p)
{
	return ((m_x == p.m_x)&& (m_y == p.m_y));
};
