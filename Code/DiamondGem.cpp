/*
 * DiamondGem.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include"DiamondGem.h"
DiamondGem::DiamondGem(int X, int Y, /*float* Color, */int id):Gem(X,Y,colors[CHOCOLATE], id)
{
//    this->T1 = new Triangle(X, Y, X+30, Y, X+15, Y+20, Color);
//    this->T2 = new Triangle(X, Y, X+30, Y, X+15, Y-20, Color);
    this->T1 = new Triangle(X-18, Y, X, Y+18, X+18, Y, colors[CHOCOLATE]);
    this->T2 = new Triangle(X-18, Y, X, Y-18, X+18, Y, colors[CHOCOLATE]);
	this->identity = 2;
}

//void DiamondGem::setIdentity(int id)
//{
//	identity = id;
//}
//
//int DiamondGem::getIdentity()
//{
//	return this->identity;
//}
//
void DiamondGem::ShowGem()
{
    T1->ShowTriangle();
    T2->ShowTriangle();
}

DiamondGem::~DiamondGem()
{
}

