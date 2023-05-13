/*
 * GameState.cpp
 *
 *  Created on: Jun 10, 2020
 *      Author: szm
 */

#include "GameState.h"
#include <iostream>
#include <fstream>
GameState::GameState()
{
	this->p = new Player(" ", 'n');
	this->l = new Level(0,'n', 0);
	this->b = new Board(150, 50, colors[PURPLE]);
	this->o = new UserOptions();

	MousePressedAndMoving=0;
	PressStartX =0;
	PressStartY=0;
	PressCurrentX=0;
	PressCurrentY=0;
}

GameState::~GameState()
{

	// TODO Auto-generated destructor stub
}

void GameState::writePStatus()	//write to file "Player Profile"
{
	ofstream scoreRecord;
	scoreRecord.open("Player Profile.txt");
	scoreRecord<<p->getName()<<endl;
	scoreRecord<<p->getScore()<<endl;
	scoreRecord<<p->getCurLevel()<<endl;
	scoreRecord<<p->getCurLevelMode()<<endl;
	scoreRecord.close();
}

void GameState::writeHScores()	//write to binary file "High Scores"
{

}

void GameState::displayPStatus()	//read from "Player Status" and display
{

}
void GameState::displayHScores()	//read from "High Scores" and display
{

}

/*
GameState();
void writePStatus();	//write to binary file "Player Profile"
void writeHScores();	//write to binary file "High Scores"
void displayPStatus();	//read from "Player Status" and display
void displayHScores();	//read from "High Scores" and display
virtual ~GameState();
*/
