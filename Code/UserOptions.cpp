/*
 * UserOptions.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: szm
 */

#include "UserOptions.h"

UserOptions::UserOptions() {

	option = 'b'; //b for beginning program
	//	start = false;
	//	newGame = true;
	start = true;
	menuDisplay = false;
	newGame = false;
	gameInPlay = false;
	settingsDisplay = false;


	hint = false;
	play = false;
	pause = false;
//	musicOptions = false;
	howToPlay = false;
	playerProfile = false;
	quit = false;
	name = " ";



}

		//setters and getter functions

void UserOptions::setOption(char choice)
{
	option = choice;
}
char UserOptions::getOption()
{
	return option;
}


void UserOptions::setGameInPlay(bool flag)
{
	gameInPlay = flag;
}
bool UserOptions::getGameInPlay()
{
	return gameInPlay;
}

void UserOptions::setNewGame(bool begin)
{
	newGame = begin;
}
bool UserOptions::getNewGame()
{
	return newGame;
}

void UserOptions::setStart(bool flag)
{
	start = flag;
}
bool UserOptions::getStart()
{
	return start;
}

void UserOptions::setMenuDisplay(bool flag)
{
	menuDisplay = flag;
}
bool UserOptions::getMenuDisplay()
{
	return menuDisplay;
}
void UserOptions::setSettingsDisplay(bool flag)
{
	settingsDisplay = flag;
}
bool UserOptions::getSettingsDisplay()
{
	return settingsDisplay;
}







void UserOptions::setHint(bool flag)
{
	hint = flag;
}
bool UserOptions::getHint()
{
	return hint;
}
void UserOptions::setPlay(bool flag)
{
	play = flag;
}
bool UserOptions::getPlay()
{
	return play;
}
void UserOptions::setPause(bool flag)
{
	pause = flag;
}
bool UserOptions::getPause()
{
	return pause;
}
//	void UserOptions::setMusicOptions(bool flag);
//	bool UserOptions::getMusicOptions();
void UserOptions::setHowToPlay(bool flag)
{
	howToPlay = flag;
}
bool UserOptions::getHowToPlay()
{
	return howToPlay;
}
void UserOptions::setPlayerProfile(bool flag)
{
	playerProfile = flag;
}
bool UserOptions::getPlayerProfile()
{
	return playerProfile;
}
void UserOptions::setQuit(bool flag)
{
	quit = flag;
}
bool UserOptions::getQuit()
{
	return quit;
}

void UserOptions::setName(string username)
{
	name = username;
}
string UserOptions::getName()
{
	return name;
}




//display functions for drawing buttons



void UserOptions::DrawHintIcon()
{
	RoundRectangle hintButton(40, 40, 30, 30, 6, colors[MISTY_ROSE]);
	hintButton.ShowRoundRectangle();
	DrawString(46, 46, "H", colors[DARK_VIOLET]);

//drawing a bulb

//	Circle bulbHead(60, 65, 13, colors[ORANGE]);
//	bulbHead.ShowCircle();
//	RoundRectangle bulbEnd(55, 50, 15, 15, 4, colors[ORANGE]);
//	bulbEnd.ShowRoundRectangle();
//	RoundRectangle metal(55, 45, 17, 10, 3, colors[GRAY]);
//	metal.ShowRoundRectangle();


}
void UserOptions::DrawPlayingIcon()
{
	RoundRectangle playButton(40, 90, 30, 30, 6, colors[MISTY_ROSE]);
	playButton.ShowRoundRectangle();
	DrawLine(51, 96, 51, 114,3, colors[DARK_VIOLET]);
	DrawLine(59, 96, 59, 114,3, colors[DARK_VIOLET]);
}
void UserOptions::DrawPausedIcon()
{
	RoundRectangle playButton(40, 90, 30, 30, 6, colors[MISTY_ROSE]);
	playButton.ShowRoundRectangle();
	Triangle icon(49, 94, 49, 116, 66, 105, colors[DARK_VIOLET]);
	icon.ShowTriangle();
}
////	void UserOptions::DrawMusicOptions();
//void UserOptions::DrawHTP()		//HTP for how to play

//void UserOptions::DrawPP();	//PP for player profile
//void UserOptions::DrawQuit();
void UserOptions::DisplaySettings()
{
	DrawString(275, 570, "Settings", colors[WHITE]);
	RoundRectangle settingsBox(150, 200, 300, 150, 8, colors[BURLY_WOOD]);
	settingsBox.ShowRoundRectangle();

	Rectangle profileButton(190, 290, 220, 40, colors[CHOCOLATE]);
	profileButton.ShowRectangle();
	DrawString(240, 300, "Player Profile", colors[SEA_SHELL]);

	Rectangle rulesButton(190, 220, 220, 40, colors[CHOCOLATE]);
	rulesButton.ShowRectangle();
	DrawString(240, 230, "How To Play", colors[SEA_SHELL]);

}

void UserOptions::DisplayMenu()
{
	RoundRectangle menuBox(150, 150, 300, 300, 8, colors[BURLY_WOOD]);
	menuBox.ShowRoundRectangle();

	Rectangle levelsButton(190, 370, 220, 40, colors[CHOCOLATE]);
	levelsButton.ShowRectangle();
	DrawString(270, 380, "Levels", colors[SEA_SHELL]);

	Rectangle levelModesButton(190, 310, 220, 40, colors[CHOCOLATE]);
	levelModesButton.ShowRectangle();
	DrawString(240, 320, "Level Modes", colors[SEA_SHELL]);


	Rectangle highScoresButton(190, 250, 220, 40, colors[CHOCOLATE]);
	highScoresButton.ShowRectangle();
	DrawString(240, 260, "High Scores", colors[SEA_SHELL]);

	Rectangle settingsButton(190, 190, 220, 40, colors[CHOCOLATE]);
	settingsButton.ShowRectangle();
	DrawString(265, 200, "Settings", colors[SEA_SHELL]);
}

void UserOptions::DisplayLevels(int currentLevel)
{
	DrawString(220, 500, "Levels Choice", colors[MINT_CREAM]);

	RoundRectangle levelsDisplayBox(180, 120, 240, 350, 8, colors[BURLY_WOOD]);
	levelsDisplayBox.ShowRoundRectangle();
	Circle** levels = nullptr;
	levels = new Circle*[5];
	for(int i=0; i<5; i++)
	{
		levels[i] = new Circle(300, 400-i*55, 20, colors[GOLD]);
	}

	int j=0;
	for(j=0; j<currentLevel; j++)
	{
		levels[j]->setColor(colors[ORANGE]);
	}

	for(int i=0; i<5; i++)
	{
		levels[i]->ShowCircle();
	}
	for(int a=0; a<5; a++)
	{
		DrawString(292, 395-55*a, to_string(a+1), colors[BLACK]);
	}
}
void UserOptions::DisplayLevelMode(char currentMode)
{
	DrawString(180, 500, "Level Mode Choice", colors[MINT_CREAM]);
	RoundRectangle modeDisplayBox(170, 200, 260, 220, 8, colors[BURLY_WOOD]);
	modeDisplayBox.ShowRoundRectangle();

	Rectangle* normal= new Rectangle(200, 320,200,70, colors[CHOCOLATE]);
	normal->ShowRectangle();
	DrawString(225, 350, "Normal Mode", colors[BLACK]);

	Rectangle* timeTrial= new Rectangle(200, 220,200,70, colors[CHOCOLATE]);
	timeTrial->ShowRectangle();
	DrawString(220, 240, "Time Trial Mode", colors[BLACK]);
}


UserOptions::~UserOptions() {
	// TODO Auto-generated destructor stub
}

