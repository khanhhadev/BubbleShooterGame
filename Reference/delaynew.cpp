#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
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
void createNewBubbleRow()
{
	for (int i = 0; i < = 10; i++) Bubble();
}

int main(){
while (true)
	{
		createNewBubbleRow();
		delay(5);
	}
}
