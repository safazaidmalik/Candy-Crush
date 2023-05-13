/*
 * Gem.cpp
 *
 *  Created on: Jun 7, 2020
 *      Author: szm
 */

#include "Gem.h"

Gem::Gem(int X,int Y, float* Color, int id)
{
	x = X;
	y =Y;
	color = Color;
	h_chain_num = 1;
	v_chain_num = 1;
	h_poppingLength = 0;
	v_poppingLength =0;
	identity = -1;
}

void Gem::setX(int X)
{
    x= X;
}
void Gem::setY(int Y)
{
    y= Y;
}

int Gem::getX(){return x;}
int Gem::getY(){return y;}

void Gem::setColor(float Color[])
{
    color = Color;
}

float* Gem::getColor(){return color;}

//
//void Gem::setIdentity(int id)
//{
//	identity =id;
//}
int Gem::getIdentity()
{
	return this->identity;
}


void Gem::setH_Chain_Num(int count)
{
	h_chain_num = count;
}
int Gem::getH_Chain_Num()
{
	return h_chain_num;
}
void Gem::setV_Chain_Num(int count)
{
	v_chain_num = count;
}
int Gem::getV_Chain_Num()
{
	return v_chain_num;
}

//int Gem::getIdentity()
//{
//	return this->identity;
//}

void Gem::setH_PLength(int length)
{
	h_poppingLength = length;
}
int Gem::getH_PLength()
{
	return h_poppingLength;
}


void Gem::setV_PLength(int length)
{
	v_poppingLength = length;
}
int Gem::getV_PLength()
{
	return v_poppingLength;
}
Gem::~Gem()
{

}

