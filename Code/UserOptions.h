/*
 * UserOptions.h
 *
 *  Created on: Jun 8, 2020
 *      Author: szm
 */

#ifndef USEROPTIONS_H_
#define USEROPTIONS_H_
#include<string>
#include<iostream>
using namespace std;
#include "RoundRectangle.h"
#include "Rectangle.h"
#include"Triangle.h"
#include"Circle.h"
class UserOptions
{
private:

	char option;
	bool newGame;

	//	do i need these??
	bool start;
	bool menuDisplay;
	bool gameInPlay;
	bool settingsDisplay;


	bool hint;
	bool play;
	bool pause;
//	bool musicOptions;
	bool howToPlay;
	bool playerProfile;
	bool quit;


	string name;

public:
	UserOptions();
	void setOption(char choice);
	char getOption();
	void setNewGame(bool begin);
	bool getNewGame();


//  setters/getters

	void setStart(bool flag);
	bool getStart();
	void setMenuDisplay(bool flag);
	bool getMenuDisplay();
	void setGameInPlay(bool flag);
	bool getGameInPlay();
	void setSettingsDisplay(bool flag);
	bool getSettingsDisplay();

	void setHint(bool flag);
	bool getHint();
	void setPlay(bool flag);
	bool getPlay();
	void setPause(bool flag);
	bool getPause();
//	void setMusicOptions(bool flag);
//	bool getMusicOptions();
	void setHowToPlay(bool flag);
	bool getHowToPlay();
	void setPlayerProfile(bool flag);
	bool getPlayerProfile();
	void setQuit(bool flag);
	bool getQuit();

	void setName(string name);
	string getName();

//display functions for drawing buttons
//
	void DrawHintIcon();
	void DrawPlayingIcon();
	void DrawPausedIcon();

	void DisplayMenu();
	void DisplaySettings();
	void DisplayLevels(int currentLevel);
	void DisplayLevelMode(char currentMode);
////	void DrawMusicOptions();
//	void DrawHTP();		//HTP for how to play
//	void DrawPP();	//PP for player profile
//	void DrawQuit();

	virtual ~UserOptions();
};

#endif /* USEROPTIONS_H_ */
