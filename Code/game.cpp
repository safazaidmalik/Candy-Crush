//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include<fstream>
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#include"Player.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include"RoundRectangle.h"
#include"Line.h"
#include"Gem.h"
#include"DiamondGem.h"
#include"CandyGem.h"
#include"LollipopGem.h"
#include"LadyBugGem.h"
#include"FlowerGem.h"
#include"Level.h"
#include"Board.h"
#include"UserOptions.h"
#include"GameState.h"
#include"ExtraGem.h"

GameState GS;
//int a=0;
//UserOptions o;
//bool paused = false;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

//Setting canvas to LIGHT_STEEL_BLUE
	glClearColor(0.690196078431373, 0.768627450980392, 0.870588235294118, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
//	if(GS.o->getNewGame() == true)
	if(GS.o->getOption() == 'n')
	{
	glClearColor(0.690196078431373, 0.768627450980392, 0.870588235294118, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


		//		ExtraGem eG(50, 175,colors[PURPLE], 0);
//		eG.ShowGem();

	/*
		FlowerGem flower(142, 97, colors[DEEP_SKY_BLUE], 3);
		DiamondGem DG(142, 142, colors[GOLD], 2);
		CandyGem candy(142, 187, colors[ORANGE], 1);
		LollipopGem lolly(142, 232, colors[GRAY], 4);
		LadyBugGem bug(142, 277, 4);
	*/
	//	Level stage(1, 'n', 0);

	//	UserOptions button;

	//	Board b(150, 50, colors[PURPLE]);
	//	b.GenerateGems();

		GS.b->setX(150);
		GS.b->setY(50);
		GS.b->setColor(colors[PURPLE]);
		GS.b->GenerateGems();
		GS.l->setLevel(1);
		GS.l->setLevelMode('n');
		GS.l->setLevelScore(0);

		GS.b->drawBoard();
		GS.o->DrawPlayingIcon();
		GS.o->DrawHintIcon();
		GS.l->displayLevel();



	//Screen is black at default
	//	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour

	//Setting canvas to LIGHT_STEEL_BLUE

		GS.o->setOption('c');
//		GS.o->setNewGame(false);
//		GS.o->setMenuDisplay(false);
//		GS.o->setGameInPlay(true);
	}
//	else if(GS.o->getGameInPlay() == true)
	else if(GS.o->getOption() == 'c')

	{
		//glutPostRedisplay();
		glClearColor(0.690196078431373, 0.768627450980392, 0.870588235294118, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour



		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

//		a++;
//		DrawString(320, 550,to_string(a), colors[BLACK]);

	//drawing axes
		for(int X=0; X<600; X++)
		{
			if(X%50 == 0)
			{
				DrawLine(X,0, X, 5, 3, colors[BLACK]);
				DrawString(X, 6,to_string(X), colors[BLACK]);
				DrawLine(0,X, 5, X, 3, colors[BLACK]);
				DrawString(6, X,to_string(X), colors[BLACK]);
			}
		}

		GS.b->drawBoard();
		GS.o->DrawPlayingIcon();
		GS.o->DrawHintIcon();
		GS.l->displayLevel();
		GS.l->displayProgress();
		GS.p->setCurLevel(GS.l->getLevel());
		GS.p->setScore(GS.l->getLevelScore());



		for(int i=0; i<8;i++)
		{
			for(int j=0; j<8; j++)
			{
				GS.b->g[i][j]->ShowGem();
			}
		}
		GS.b->update_Chain_Numbers();
//		GS.b->cascadeGems(0,0,7,7);
		GS.l->setLevelScore(GS.l->getLevelScore()+GS.b->popGems());
//		cout<<"Level Score = "<<GS.l->getLevelScore()<<endl;
		DrawString(320, 460, "Score: "+to_string(GS.l->getLevelScore()), colors[BLACK] );
		GS.b->CascadeGems();
		GS.b->DropNewGem();
	}


//	else if(GS.o->getStart() == true)
	else if(GS.o->getOption() == 'b')
	{
		GS.p->setName("Safa");
		DrawString(300, 530,"Player: "+GS.p->getName(), colors[BLACK]);
//		string playerID;
//		getline(cin, playerID);
		DrawString(280, 350, "Menu    (m)", colors[WHITE]);
		DrawString(200, 280,"New Game     (n)", colors[WHITE]);
		DrawString(210, 210, "Resume Game     (r)", colors[WHITE]);
	}


//	else if(GS.o->getMenuDisplay()== true)
	else if(GS.o->getOption()== 'm')
	{
		glClearColor(0, 0, 0, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT);

		//glutPostRedisplay();
//		GS.o->setSettingsDisplay(false);
		DrawString(280, 560, "Menu", colors[WHITE]);
		GS.o->DisplayMenu();
	}

	else if(GS.o->getOption() == 's')
//	else if(GS.o->getSettingsDisplay()== true)
	{
		glClearColor(0, 0, 0, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT);
		//glutPostRedisplay();
//		GS.o->setStart(false);
//		GS.o->setMenuDisplay(false);
		GS.o->DisplaySettings();
	}
	else if(GS.o->getOption() == 'l')
	{
		glClearColor(0, 0, 0, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT);
		//glutPostRedisplay();
		cout<<"GS.l->getLevel() = "<<GS.l->getLevel()<<endl;
		GS.o->DisplayLevels(GS.l->getLevel());
//		GS.o->DisplayLevels(1);
	}
	else if(GS.o->getOption() == 'd')
	{
		glClearColor(0, 0, 0, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT);
		//glutPostRedisplay();
//		cout<<"GS.l->getLevelMode() = "<<GS.l->getLevelMode()<<endl;
		cout<<GS.p->getCurLevelMode()<<",";
		cout<<GS.l->getLevelMode()<<"    ";
		GS.o->DisplayLevelMode(GS.l->getLevelMode());
		//drawing axes
			for(int X=0; X<600; X++)
			{
				if(X%50 == 0)
				{
					DrawLine(X,0, X, 5, 3, colors[WHITE]);
					DrawString(X, 6,to_string(X), colors[WHITE]);
					DrawLine(0,X, 5, X, 3, colors[WHITE]);
					DrawString(6, X,to_string(X), colors[WHITE]);
				}
			}
//			DrawLine(240, 340, 250, 400, 3, colors[RED]);

//		GS.o->DisplayLevels(1);
	}
	else if(GS.o->getOption() == 'h')
	{
		string score1;
		ifstream fin ("high score.txt"); //name of the file it is supposed to read
		if (fin.is_open())
		{
			int lineCount=0;
			DrawString( 360, 600 , "HIGH SCORES ", colors[GREEN]);
			while ( getline (fin, score1) ) //this loop will run depending on the number of lines in the file
			{
				DrawString( 360, 500 - 30*lineCount, to_string(lineCount+1)+ "    " + score1, colors[GOLD]);
				lineCount++;
			}
		}
		fin.close();
	}


		//should read file of "High Scores" and display 4 highest scores of all players
//		DrawString()
	else if(GS.o->getOption() == 'f')
	{

	}
	else
		DrawString(300, 300, "GAME NOT WORKING", colors[BLACK]);
	glutSwapBuffers(); // do not modify this line..


}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

//	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		GS.writePStatus();
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'm' || key == 'M') //Key for going to Menu
	{
		//do something if b is pressed
		cout<<"Should display Menu"<<endl;
		GS.o->setOption('m');
//		GS.o->setMenuDisplay(true);
//		GS.o->setStart(false);
	}
	else if(key == 's' || key == 'S') //Key for going to Settings
	{
		cout<<"Should display Settings"<<endl;
		GS.o->setOption('s');
//		GS.o->setSettingsDisplay(true);
//		GS.o->setStart(false);
//		GS.o->setMenuDisplay(false);
	}
	else if(key == 'n' || key == 'N')	//Key for starting new game
	{
		cout<<"Should start new game."<<endl;
		GS.o->setOption('n');
		GS.o->setNewGame(true);
//		GS.o->setStart(false);
//		GS.o->setMenuDisplay(false);
	}
	else if((GS.o->getNewGame() == true) &&(key == 'c' || key == 'C' || key == 'r' || key == 'R'))	//Key for resuming paused game
	{
		cout<<"Should resume game / Keep game running."<<endl;
		GS.o->setOption('c');
	}
	else if(key == 'l' || key == 'L')	//Key for resuming paused game
	{
		cout<<"Should display levels choice."<<endl;
		GS.o->setOption('l');
	}
	else if(key == 'd' || key == 'D')	//Key for resuming paused game
	{
		cout<<"Should display level modes choice."<<endl;
		GS.o->setOption('d');
	}
	else if(key=='p' || key == 'P')
	{
		cout<<"Pause game:"<<endl;
		GS.o->setOption('p');	//not implemented yet
	}
	else if(key == 'h' || key == 'H')
	{
		cout<<"Should display high scores"<<endl;
		GS.o->setOption('h');
	}






	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(700, Timer, 0);
	glutPostRedisplay();
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{

//	GS.b->cascadeGems(0,0,7,7);
	if(GS.MousePressedAndMoving == false)
	{
		GS.PressStartX = (x-150)/50;		//for finding grid array id's of gems where clicked
		GS.PressStartY = ((600-y)-50)/50;
		GS.MousePressedAndMoving = true;
	}
	else
	{
		GS.PressCurrentX = (x-150)/50;		//for finding grid array id's of gems where released
		GS.PressCurrentY = ((600-y)-50)/50;
	}
	switch(int xDiff = GS.PressCurrentX-GS.PressStartX)
	{
	case(1):	//when cursor is moved right
		if(GS.PressStartX < 7 && GS.PressStartX>-1)
		{
			if(GS.PressStartY == GS.PressCurrentY)
				GS.l->setLevelScore(GS.l->getLevelScore()+GS.b->swapGems(GS.PressStartX, GS.PressStartY, GS.PressStartX+1, GS.PressStartY));
		}
		GS.MousePressedAndMoving = false;
		cout <<GS.PressStartX << "," << GS.PressStartY<<"      "<<GS.PressCurrentX<<","<<GS.PressCurrentY<< endl;
		break;
	case(-1):	//when cursor is moved left
		if(GS.PressStartX < 8 && GS.PressStartX > 0)
		{
			if(GS.PressStartY == GS.PressCurrentY)
				GS.l->setLevelScore(GS.l->getLevelScore()+GS.b->swapGems(GS.PressStartX, GS.PressStartY, GS.PressStartX-1, GS.PressStartY));
		}
		GS.MousePressedAndMoving = false;
		cout <<GS.PressStartX << "," << GS.PressStartY<<"      "<<GS.PressCurrentX<<","<<GS.PressCurrentY<< endl;
		break;
	}
	switch(int yDiff = GS.PressCurrentY-GS.PressStartY)
	{
	case(1):	//when cursor is moved right
		if(GS.PressStartY < 7 && GS.PressStartY > -1)
		{
			if(GS.PressStartX == GS.PressCurrentX)
				GS.l->setLevelScore(GS.l->getLevelScore()+GS.b->swapGems(GS.PressStartX, GS.PressStartY, GS.PressStartX, GS.PressStartY+1));
		}
		GS.MousePressedAndMoving = false;
		cout <<GS.PressStartX << "," << GS.PressStartY<<"      "<<GS.PressCurrentX<<","<<GS.PressCurrentY<< endl;
		break;
	case(-1):	//when cursor is moved left
		if(GS.PressStartY < 8 && GS.PressStartY > 0)
		{
			if(GS.PressStartX == GS.PressCurrentX)
				GS.l->setLevelScore(GS.l->getLevelScore()+GS.b->swapGems(GS.PressStartX, GS.PressStartY, GS.PressStartX, GS.PressStartY-1));
		}
		GS.MousePressedAndMoving = false;
		cout <<GS.PressStartX << "," << GS.PressStartY<<"      "<<GS.PressCurrentX<<","<<GS.PressCurrentY<< endl;
		break;
	}


//	cout <<GS.PressStartX << "," << GS.PressStartY<<"      "<<GS.PressCurrentX<<","<<GS.PressCurrentY<< endl;

	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {
//	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if(GS.o->getOption() == 'l')
		{
			if(x>=285 && x<=315)		//for choosing level 1
			{
				if(y>=(600-380) && y<=(600- 420))
				{
					if(GS.l->getLevel()>=1)
					{
						GS.p->setCurLevel(1);
						GS.l->setLevel(1);
						cout<<GS.p->getCurLevel()<<' ';
						cout<<GS.l->getLevel()<<"  ";
					}
				}
				else if(y>=(600-325) && y<=(600- 265))
				{
					if(GS.l->getLevel()>=2)
					{
						GS.p->setCurLevel(2);
						GS.l->setLevel(2);
						cout<<GS.p->getCurLevel()<<' ';
						cout<<GS.l->getLevel()<<"  ";
					}
				}
				else if(y>=(600-270) && y<=(600- 310))
				{
					if(GS.l->getLevel()>=3)
					{
						GS.p->setCurLevel(3);
						GS.l->setLevel(3);
						cout<<GS.p->getCurLevel()<<' ';
						cout<<GS.l->getLevel()<<"  ";
					}
				}
				else if(y>=(600-215) && y<=(600- 255))
				{
					if(GS.l->getLevel()>=4)
					{
						GS.p->setCurLevel(4);
						GS.l->setLevel(4);
						cout<<GS.p->getCurLevel()<<' ';
						cout<<GS.l->getLevel()<<"  ";
					}
				}
				else if(y>=(600-160) && y<=(600- 200))
				{
					if(GS.l->getLevel()>=5)
					{
						GS.p->setCurLevel(5);
						GS.l->setLevel(5);
						cout<<GS.p->getCurLevel()<<' ';
						cout<<GS.l->getLevel()<<"  ";
					}
				}
			}
		}

		else if(GS.o->getOption() == 'd')
		{
			if(x>=200 && x<=400)
			{
				if((600-y)>=320 && (600-y)<= 390)
				{
					GS.p->setCurLevelMode('n');
					GS.l->setLevelMode('n');
				}
				else if((600-y)>=220 && (600-y)<=290)
				{
					GS.o->setOption('m');
					GS.p->setCurLevelMode('t');
					GS.l->setLevelMode('t');
//					cout<<GS.p->getCurLevelMode()<<",";
//					cout<<GS.l->getLevelMode()<<"    ";
					DrawLine(x, 600-y, x+10, 600-y, 3, colors[RED]);
				}
			}

		}

	}



	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
//	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 600, height = 600; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(700.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
