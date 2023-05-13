/*
 * FlowerGem.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#include"FlowerGem.h"

FlowerGem::FlowerGem(float X, float Y, /*float* petalColor, */int id):Gem(X, Y, colors[PURPLE], id) //coordinates required for left most petal(circle)
{
	this->center = new Circle(X, Y, 3, colors[ORANGE]);
	this->c1 = new Circle(X, Y + 3 + 9, 9, colors[BLUE]);
    this->c2 = new Circle(X+ 3 + 9, Y, 9, colors[BLUE]);
    this->c3 = new Circle(X, Y - 3 - 9, 9, colors[BLUE]);
    this->c4 = new Circle(X - 3 - 9, Y, 9, colors[BLUE]);
	this->identity = 3;

}


//
//void FlowerGem::setIdentity(int id)
//{
//	identity =1;
//}
//
//int FlowerGem::getIdentity()
//{
//	return this->identity;
//}

void FlowerGem::ShowGem()
{
    c1->ShowCircle();
    c2->ShowCircle();
    c3->ShowCircle();
    c4->ShowCircle();
    center->ShowCircle();
}

FlowerGem::~FlowerGem()
{

}

