/*
 * LollipopGem.h
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#ifndef LOLLIPOPGEM_H_
#define LOLLIPOPGEM_H_
#include"Circle.h"
#include"Line.h"
#include"Gem.h"

class LollipopGem : public Gem
{
private:
    Line* stick;
    Circle* candy;
//    int identity;
public:
    LollipopGem(int X, int Y, /*float* Color,*/ int id);
    void ShowGem();
//    void setIdentity(int id);
//    int getIdentity();
	~LollipopGem();
};

#endif /*LOLLIPOPGEM_H_*/
