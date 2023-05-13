/*
 * LadyBugGem.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#include "LadyBugGem.h"


LadyBugGem::LadyBugGem(int X, int Y, int id): Gem(X, Y, colors[BLACK], id)
{
    this-> head = new Circle(X, Y+9, 6, colors[BLACK]);
    this-> rightAntenna = new Line(X+2, Y+12, X+5, Y+20, 2, colors[BLACK]);
    this-> rightDot = new Circle(X+5, Y+20, 2, colors[BLACK]);
    this-> leftAntenna = new Line(X-2, Y+12, X-8, Y+20, 2, colors[BLACK]);
    this-> leftDot = new Circle(X-8, Y+20, 2, colors[BLACK]);

    this-> body = new Circle(X, Y-5, 16, colors[RED]);
    this-> spot1 = new Circle(X-9, Y-10, 3, colors[BLACK]);
    this-> spot2 = new Circle(X-7, Y+1, 3, colors[BLACK]);
    this-> spot3 = new Circle(X+6, Y+4, 3, colors[BLACK]);
    this-> spot4 = new Circle(X+10, Y-9, 3, colors[BLACK]);
    this-> midLine = new Line(X, Y+13, X, Y-17, 2, colors[BLACK]);
    this-> rightSlant = new Line(X, Y-14, X+6, Y-21, 3, colors[BLACK]);
    this-> leftSlant = new Line(X, Y-14, X-6, Y-21, 3, colors[BLACK]);
	this->identity = 5;

}


//void LadyBugGem::setIdentity(int id)
//{
//	identity =id;
//}
//
//int LadyBugGem::getIdentity()
//{
//	return this->identity;
//}

void LadyBugGem::ShowGem()
{

	head->ShowCircle();
	rightAntenna->ShowLine();
	rightDot->ShowCircle();
	leftAntenna->ShowLine();
	leftDot->ShowCircle();

	body->ShowCircle();
	spot1->ShowCircle();
	spot2->ShowCircle();
	spot3->ShowCircle();
	spot4->ShowCircle();
	midLine->ShowLine();
	rightSlant->ShowLine();
	leftSlant->ShowLine();
}


LadyBugGem::~LadyBugGem()
{

}

