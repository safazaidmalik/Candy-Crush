/*
 * CandyGem.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include"CandyGem.h"


CandyGem::CandyGem(int X, int Y, /*float* Color,*/ int id): Gem(X,Y,colors[ORANGE], id)
{
	this-> candy = new Circle(float(X), float(Y), float(12), colors[ORANGE]);
    this-> leftWrapper = new Triangle(X-12-8, Y+8, X-12-8, Y-8, X-8, Y, colors[ORANGE]);
    this-> leftString = new Line(X-12, Y+2, X-12, Y-2, 1, colors[WHITE]);
    this-> rightWrapper = new Triangle(X+12+8, Y+8, X+12+8, Y-8, X+8, Y, colors[ORANGE]);
    this-> rightString = new Line(X+12, Y+2, X+12, Y-2, 1, colors[WHITE]);
	this->identity = id;

}

//void CandyGem::setIdentity(int id)
//{
//	identity =id;
//}
//
//int CandyGem::getIdentity()
//{
//	return this->identity;
//}

void CandyGem::ShowLine()
{
	DrawLine(0, 240, 50, 240, 3, colors[BLACK]);
}
void CandyGem::ShowGem()
{
    candy->ShowCircle();
    leftWrapper->ShowTriangle();
    leftString->ShowLine();
//    DrawLine(X-12, Y+2, X-12, Y-2, 3, colors[WHITE]);
//    DrawLine(X-12, Y+2, X-12, Y-2, 3, Color);

    rightWrapper->ShowTriangle();
    rightString->ShowLine();

//    DrawLine(X+12, Y+2, X+12, Y-2, 3, colors[WHITE]);
//    DrawLine(X+12, Y+2, X+12, Y-2, 3, Color);
//
}

CandyGem::~CandyGem()
{

}

