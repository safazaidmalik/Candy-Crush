/*
 * Player.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include "Player.h"
Player::Player(string id, char mode)	//new player starts game with curLevel=0  and score=0
{
	name =id;
	score = 0;
	curLevel = 0;
	curLevelMode = mode;
}

void Player::setName(string id)
{
	name = id;
}
string Player::getName()
{
	return name;
}
void Player::setScore(int points)
{
	score = points;
}
int Player::getScore()
{
	return score;
}
void Player::setCurLevel(int stage)
{
	curLevel = stage;
}
int Player::getCurLevel()
{
	return curLevel;
}
void Player::setCurLevelMode(char mode)
{
	curLevelMode = mode;
}
char Player::getCurLevelMode()
{
	return curLevelMode;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

