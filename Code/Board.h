/*
 * Board.h
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#ifndef BOARD_H_
#define BOARD_H_
#include"Line.h"
#include"Gem.h"
#include"Rectangle.h"
#include"CandyGem.h"
#include"DiamondGem.h"
#include"FlowerGem.h"
#include"LadyBugGem.h"
#include"LollipopGem.h"
#include"ExtraGem.h"

class Board
{
private:
	int x;
	int y;
	float* color;
//	Gem* g[8][8];	//pointer to child gem classes(polymorphism applied here)
//	Gem*** g;	//pointer to child gem classes(polymorphism applied here)
//	Gem***g = new Gem**[8][8];


public:
	Gem***g = nullptr;		//pointer to child gem classes(polymorphism applied here)
	Board(int X, int Y, float* Color);
	void setX(int X);
	int getX();
	void setY(int Y);
	int getY();
	void setColor(float* Color);
	float* getColor();
	void drawBoard();
	void update_Chain_Numbers();
	void GenerateGems();
	void DrawGems();
	int popGems();		//returns the total score after gems have popped(for setting to level and player objects)
	void BasicSwap(int i, int j, int i2, int j2);
	void CascadeGems();
	void DropNewGem();
	int swapGems(int, int,int, int);/////////WORKING ON IT............\\\\\\\\\\\\



	virtual ~Board();
};

#endif /* BOARD_H_ */
