#pragma once
#include "Point.h"
#include "Common.h"
class Shooter
{
public:
	Point m_shootingpoint;
	float m_shootingangle;

	//refrence to list of Point belonging to Shooter
	Point* m_shooterptr;
private:
	Shooter();
	~Shooter();
};

Shooter::Shooter()
{

}

Shooter::~Shooter()
{

}