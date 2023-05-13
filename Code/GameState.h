/*
 * GameState.h
 *
 *  Created on: Jun 10, 2020
 *      Author: szm
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include"Player.h"
#include"Level.h"
#include"Board.h"
#include"UserOptions.h"



class GameState
{
private:

public:
	Player *p;
	Level *l;
	Board *b;
	UserOptions *o;

	bool MousePressedAndMoving;
	int PressStartX;
	int PressStartY;

	int PressCurrentX;
	int PressCurrentY;


	GameState();
	void writePStatus();	//write to binary file "Player Profile"
	void writeHScores();	//write to binary file "High Scores"
	void displayPStatus();	//read from "Player Status" and display
	void displayHScores();	//read from "High Scores" and display
	virtual ~GameState();
};

#endif /* GAMESTATE_H_ */
