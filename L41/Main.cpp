
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "circle.h"



#define _CRT_SECURE_NO_WARNINGS
#define _SP system("pause");

typedef unsigned int uint;

void main() {


	Point p1 = { 11,12 };
	Point p2 = p1;
	Point p3(p2);

	p3 = p1;
	std::cout << p3;
	Circle C1(p1,p3);
	std::cout << C1;

	_SP








}