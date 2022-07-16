#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
//ham delay thoi gian mình muon
void delay(int a)
{
	int add;
	int time;
	int i;

// dieu chinh thoi gian delay o ben duoi
time = a*10000000;
for (i = 0; i < time; i++)
{
	add*=i;
	add++;
	add++;
}
}
int main(){
cout << "Ball 1 \n ";
// cai 5s vao day
delay(5);    
cout << "    * \n";
delay(5);
cout << "        * \n";
delay(5);
cout << "           * \n";
delay(5);
cout <<"                * \n";
delay(5);
cout <<"                    * \n";
delay(5);
cout <<"                         * \n";
delay(5);
cout <<"                             * \n";
delay(5);
cout <<"                                  * \n";
delay(5);
cout <<"                                      * \n"; 
cout <<"                                  Trung bong \n";
}
