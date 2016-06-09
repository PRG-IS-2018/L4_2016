
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "circle.h"
#include "List.h"


#define _CRT_SECURE_NO_WARNINGS
#define _SP system("pause");

typedef unsigned int uint;

void main() {


	Point p1 = { 11,12 };
	Point p10(5, 5);
	Point p2 = p1;
	Point p3(p2);
	Point p4 (1,2);
	p3 = p1;
	//std::cout << p3;
	Circle C1(p1,p3);
	Circle C2(p1, p4);
	//std::cout << C1;

	List L1;
	L1.AddNode(C1);
	L1.AddNode(C2);
	L1.AddNode(Circle(p10, p1));

	List L2(L1);
	List L3(std::move(L2));
	std::cout << L3;

	_SP



}