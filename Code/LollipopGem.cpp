/*
 * Lollipop.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#include "LollipopGem.h"
LollipopGem::LollipopGem(int X, int Y, /*float* Color,*/ int id): Gem(X,Y,colors[DEEP_PINK], id)
{
    this->stick = new Line(X, Y+5, X-12, Y-20, 3, colors[WHITE]);
    this->candy = new Circle(X, Y+5, 13, colors[DEEP_PINK]);
	this->identity = id;
}

//
//void LollipopGem::setIdentity(int id)
//{
//	identity =1;
//}
//
//int LollipopGem::getIdentity()
//{
//	return this->identity;
//}

void LollipopGem::ShowGem()
{
    stick->ShowLine();
    candy->ShowCircle();
}

LollipopGem::~LollipopGem()
{

}

