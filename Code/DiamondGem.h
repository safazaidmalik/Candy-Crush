/*
 * DiamondGem.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef DIAMONDGEM_H_
#define DIAMONDGEM_H_
#include"Triangle.h"
#include"Gem.h"

class DiamondGem : public Gem
{
private:
    Triangle* T1;    // A diamond is composition of two inverted triangles.
    Triangle* T2;
//    int identity;
public:
    DiamondGem(int X, int Y,/* float* Color,*/ int id);    //Only coordinates required are for diamond's center
//    void setIdentity(int id);
//    int getIdentity();
    void ShowGem();
	~DiamondGem();

};

#endif /* DIAMONDGEM_H_ */
