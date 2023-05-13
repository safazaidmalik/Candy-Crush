/*
 * FlowerGem.h
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#ifndef FLOWERGEM_H_
#define FLOWERGEM_H_
#include"Circle.h"
#include"Gem.h"
class FlowerGem : public Gem
{
private:
    Circle* center;
    Circle* c1;
    Circle* c2;
    Circle* c3;
    Circle* c4;
//    int identity;
public:
//    FlowerGem(float X, float Y, float centerRadius, float petalRadius, float* petalColor); //coordinates required for left most petal(circle)
    FlowerGem(float X, float Y, /*float* petalColor, */int id); //coordinates required for left most petal(circle)
//    int getIdentity();
//    void setIdentity(int id);
    void ShowGem();
	~FlowerGem();
};

#endif /* FLOWERGEM_H_ */
