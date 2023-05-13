/*
 * Player.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include"util.h"
#include<string>
#include<iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;
	int curLevel;
	char curLevelMode;

public:
	Player(string id, char mode);	//new player starts game with curLevel=0  and score=0
	void setName(string id);
	string getName();
	void setScore(int points);
	void setCurLevel(int stage);
	int getCurLevel();
	int getScore();
	void setCurLevelMode(char mode);
	char getCurLevelMode();

	~Player();
};

#endif /* PLAYER_H_ */
