/*
 * Level.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include "Level.h"

Level::Level(int stage, char mode, int points)
{
	level = stage;
	levelMode = mode;
	levelScore = points;
}
void Level::setLevel(int stage)
{
	level = stage;
}
int Level::getLevel()
{
	return level;
}
void Level::setLevelMode(char mode)
{
	levelMode = mode;
}
char Level::getLevelMode()
{
	return levelMode;
}
void Level::setLevelScore(int points)
{
	levelScore = points;
}
int Level::getLevelScore()
{
	return levelScore;
}

//void Level::updateLevel()
//{
//	if()
//}

void Level::displayLevel()
{
	string stringLevel = to_string(level);
	DrawString(100, 500, "Level = "+ stringLevel, colors[GREEN]);
}
void Level::displayLevelMode()
{
	if(levelMode == 'n')
		DrawString(20, 550, "Normal Mode", colors[GREEN]);
	else if(levelMode == 't')
		DrawString(20, 550, "Time Trial Mode", colors[GREEN]);
}
void Level::displayProgress()
{
	Rectangle scoreBox(350-level*50, 490, levelScore/2, 10, colors [BLUE]);
	scoreBox.ShowRectangle();
//	DrawString(300, 460, "Score : "+ to_string(levelScore), colors[GREEN]);
	DrawLine(350-level*50, 490, 350+level*50, 490, 3, colors[BLACK]);
	DrawLine(350+level*50, 490, 350+level*50, 500, 3, colors[BLACK]);
	DrawLine(350+level*50, 500, 350-level*50, 500, 3, colors[BLACK]);
	DrawLine(350-level*50, 500, 350-level*50, 490, 3, colors[BLACK]);

	if(this->levelScore >= 200*level)//should this be getScore() instead?
	{
		level++;
		levelScore = 0;
	}

}


Level::~Level()
{


}

