
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "circle.h"
#include "List.h"


#define _CRT_SECURE_NO_WARNINGS
#define _SP system("pause");

typedef unsigned int uint;

void main() {


	Point p1 = { 1,1 };
	Point p10(5, 5);
	Point p2 = p1;
	Point p3(p2);
	Point p4 (2,2);
	p3 = p1;
	//std::cout << p3;
	Circle C1(p1,4);
	Circle C2(p4, p1);
	//std::cout << C1;

	List L1;
	L1.AddNode(C1);
	L1.AddNode(C2);
	L1.AddNode(Circle(p10, p1));
	
	//std::cout << L1;
	//_SP
	List L2(L1);
	//std::cout << L2;
	//_SP
	List L3(std::move(L2));
	std::cout << L3;
	_SP
	L3.Sort();
	std::cout << L3;
	_SP



}