#pragma once
#include <thread>
#include "Bubble.h"
#include "General.h"

void createBubbleRow()
{
	while (true)
	{
		for (int i = 0; i < SCREEN_LENGTH; i++)
			Bubble();
		delay(5);
	}
}
//ham delay thoi gian ma` minh muon
void delay(int a)
{
	int add;
	int time;
	int i;

// dieu chinh thoi gian delay o ben duoi
	time = a*1000000000;
	for (i = 0; i < time; i++)
	{
		add*=i;
		add++;
		add++;
	}
}

