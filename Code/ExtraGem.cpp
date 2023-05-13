/*
 * ExtraGem.cpp
 *
 *  Created on: Jun 10, 2020
 *      Author: szm
 */

#include "ExtraGem.h"

ExtraGem::ExtraGem(int X, int Y, /*float* Color,*/ int id) : Gem(X, Y, colors[PURPLE], id)
{
	identity =0;
	r = new Rectangle(X-25, Y-25, 50, 50, colors[PURPLE]);
}

void ExtraGem::ShowGem()
{
	r->ShowRectangle();
}

ExtraGem::~ExtraGem() {
	// TODO Auto-generated destructor stub
}

