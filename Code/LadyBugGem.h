/*
 * LadyBugGem.h
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */
#ifndef LADYBUGGEM_H_
#define LADYBUGGEM_H_

#include"Circle.h"
#include"Line.h"
#include"Gem.h"

class LadyBugGem : public Gem
{
private:
    Circle* head;
    Line* rightAntenna;
    Circle* rightDot;
    Line* leftAntenna;
    Circle* leftDot;

    Circle* body;
    Circle* spot1;
    Circle* spot2;
    Circle* spot3;
    Circle* spot4;
    Line* midLine;
    Line* rightSlant;
    Line* leftSlant;
//    int identity;
public:
    LadyBugGem(int X, int Y, int id);
//    void setIdentity(int id);
//    int getIdentity();
    void ShowGem();
	~LadyBugGem();

};

#endif /* LADYBUGGEM_H_ */
