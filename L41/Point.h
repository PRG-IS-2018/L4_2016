#pragma once

#include <iostream>
//#include <conio.h>

class Point{
	int m_x;
	int m_y;
	//friend class Circle;
public:
	Point(int = 0, int = 0);
	friend std::ostream& operator<<(std::ostream&, Point&);

private:

};
