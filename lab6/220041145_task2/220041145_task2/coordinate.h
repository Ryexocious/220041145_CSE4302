#ifndef coordinate_H
#define coordiante_H
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class coordinate
{
private:
	float abscissa;
	float ordinate;
public:
	coordinate() :abscissa(0), ordinate(0){}
	coordinate(float x,float y): abscissa(x),ordinate(y){}
	void display();
	~coordinate(){}
	float operator-(coordinate c);
	float getdistance();
	void move_x(float val);
	void move_y(float val);
	void move(float x_val, float y_val);
	friend bool operator>(coordinate x,coordinate y);
	friend bool operator<(coordinate x, coordinate y);
	friend bool operator>=(coordinate x, coordinate y);
	friend bool operator<=(coordinate x, coordinate y);
	friend bool operator==(coordinate x, coordinate y);
	friend bool operator!=(coordinate x, coordinate y);
};
#endif // coordinate_H
