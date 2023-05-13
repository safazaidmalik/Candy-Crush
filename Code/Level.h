/*
 * Level.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include"Rectangle.h"
#include<iostream>
#include<string>
using namespace std;

class Level
{
protected:
	int level;
	char levelMode;
	int levelScore;

public:
	Level(int stage, char mode, int points);

	void setLevel(int stage);
	int getLevel();
	void setLevelMode(char mode);
	char getLevelMode();
	void setLevelScore(int points);
	int getLevelScore();

	void displayLevel();
	void displayLevelMode();
	void displayProgress();	//drawing progress bar which gets full when getLevelScore()== 100

//display Level at all times

	~Level();
};

#endif /* LEVEL_H_ */
