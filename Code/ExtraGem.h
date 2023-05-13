/*
 * ExtraGem.h
 *
 *  Created on: Jun 10, 2020
 *      Author: szm
 */

#ifndef EXTRAGEM_H_
#define EXTRAGEM_H_
#include"Gem.h"
#include"util.h"
#include"Rectangle.h"
class ExtraGem :public Gem
{
private:
	Rectangle* r;
public:
	ExtraGem(int X, int Y, /*float* Color,*/ int id);
	void ShowGem();
	virtual ~ExtraGem();
};

#endif /* EXTRAGEM_H_ */
