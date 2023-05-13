/*
 * CandyGem.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef CANDYGEM_H_
#define CANDYGEM_H_
#include"util.h"
#include"Triangle.h"
#include"Circle.h"
#include"Line.h"
#include"Gem.h"

class CandyGem : public Gem
{
private:
    Circle* candy;      //a circle in the middle of triangles to show the candy part
    Triangle* leftWrapper;  // left and right triangles will indicate the twist of a candy wrapper
    Line* leftString;
    Triangle* rightWrapper;
    Line* rightString;
//    int identity;
public:
    CandyGem(int X, int Y, /*float* Color,*/ int id); //coordinates required for center of candy.
//    void setIdentity(int id);
//    int getIdentity();
    void ShowGem();
    //testing

    virtual void ShowLine();
	~CandyGem();
};

#endif /*CANDYGEM_H_*/
