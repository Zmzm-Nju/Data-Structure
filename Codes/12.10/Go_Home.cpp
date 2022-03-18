#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct Location
{
	long long x1;
	long long y1;
	long long x2;
	long long y2;
};
void Normalize(Location& Loc);
long long Distance(long long x1, long long y1, long long x2, long long y2);
void Calculate(int depth, Location* Doors, int Num, Location My_Loc, long long* Result, long long Experienced);
int main()
{
	int Num = 0;
	Location My_Loc;
	cin >> Num;
	cin >> My_Loc.x1 >> My_Loc.y1 >> My_Loc.x2 >> My_Loc.y2;
	Location*Doors =  new Location[Num];
	for (int i = 0; i < Num; i++)
		cin >> Doors[i].x1 >> Doors[i].y1 >> Doors[i].x2 >> Doors[i].y2;
	long long Result = Distance(My_Loc.x1, My_Loc.y1, My_Loc.x2, My_Loc.y2);
	if (Num > 0)
		Calculate(10, Doors, Num, My_Loc, &Result, 0);
	printf("%lld\n", Result);
	return 0;
}

void Normalize(Location& Loc)
{
	long long temp = 0;
	if (Loc.x1 > Loc.x2)
	{
		temp = Loc.x1;
		Loc.x1 = Loc.x2;
		Loc.x2 = temp;
	}
	if (Loc.y1 > Loc.y2)
	{
		temp = Loc.y1;
		Loc.y1 = Loc.y2;
		Loc.y2 = temp;
	}
}

long long Distance(long long x1, long long y1, long long x2, long long y2)
{
	return (x1 > x2 ? (x1 - x2) : (x2 - x1)) + (y1 > y2 ? (y1 - y2) : (y2 - y1));
}

void Calculate(int depth, Location* Doors, int Num, Location My_Loc, long long* Result, long long Experienced) 
{
	if (Experienced >= *Result || depth <= 0)return;

	long long Direct_Distance = 0;
	Direct_Distance = Distance(My_Loc.x1, My_Loc.y1, My_Loc.x2, My_Loc.y2);
	if (Direct_Distance + Experienced < *Result)*Result = Direct_Distance + Experienced;

	long long Temp = 0;
	for (int i = 0; i < Num; i++)
	{
		Location My_Loc1, My_Loc2;
		Temp = Distance(My_Loc.x1, My_Loc.y1, Doors[i].x1, Doors[i].y1) + 10;
		if (Temp + Experienced < *Result)
		{
			My_Loc1.x1 = Doors[i].x2;
			My_Loc1.y1 = Doors[i].y2;
			My_Loc1.x2 = My_Loc.x2;
			My_Loc1.y2 = My_Loc.y2;
			Calculate(depth - 1, Doors, Num, My_Loc1, Result, Temp + Experienced);
		}
		Temp = Distance(My_Loc.x1, My_Loc.y1, Doors[i].x2, Doors[i].y2) + 10;
		if (Temp + Experienced < *Result)
		{
			My_Loc2.x1 = Doors[i].x1;
			My_Loc2.y1 = Doors[i].y1;
			My_Loc2.x2 = My_Loc.x2;
			My_Loc2.y2 = My_Loc.y2;
			Calculate(depth - 1, Doors, Num, My_Loc2, Result, Temp + Experienced);
		}
	}
}
