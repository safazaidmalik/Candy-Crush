/*
 * Board.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: szm
 */

#include "Board.h"
#include <cstdlib> 	//to generate random types of gems
#include<ctime>


Board::Board(int X, int Y, float* Color)
{
	x= X;
	y= Y;
	color = Color;
//	g = nullptr;	//should not point to anything before gems are instantiated.
	g = new Gem**[8];
	for(int i=0; i<8; i++)
		g[i] = new Gem*[8];

}

void Board::setX(int X)
{
	x= X;
}
int Board::getX()
{
	return x;
}
void Board::setY(int Y)
{
	y = Y;
}
int Board::getY()
{
	return y;
}
void Board::setColor(float* Color)
{
	color = Color;
}
float* Board::getColor()
{
	return color;
}
void Board::drawBoard()
{
	Rectangle rec(x, y, x+250, y+350, color);
	rec.ShowRectangle();
//vertical lines
	DrawLine(x, y, x, y+400, 2, colors[BLACK]);
	DrawLine(x+50, y, x+50, y+400, 2, colors[BLACK]);
	DrawLine(x+100, y, x+100, y+400, 2, colors[BLACK]);
	DrawLine(x+150, y, x+150, y+400, 2, colors[BLACK]);
	DrawLine(x+200, y, x+200, y+400, 2, colors[BLACK]);
	DrawLine(x+250, y, x+250, y+400, 2, colors[BLACK]);
	DrawLine(x+300, y, x+300, y+400, 2, colors[BLACK]);
	DrawLine(x+350, y, x+350, y+400, 2, colors[BLACK]);
	DrawLine(x+400, y, x+400, y+400, 2, colors[BLACK]);

//horizontal lines
	DrawLine(x, y, x+400, y, 2, colors[BLACK]);
	DrawLine(x, y+50, x+400, y+50, 2, colors[BLACK]);
	DrawLine(x, y+100, x+400, y+100, 2, colors[BLACK]);
	DrawLine(x, y+150, x+400, y+150, 2, colors[BLACK]);
	DrawLine(x, y+200, x+400, y+200, 2, colors[BLACK]);
	DrawLine(x, y+250, x+400, y+250, 2, colors[BLACK]);
	DrawLine(x, y+300, x+400, y+300, 2, colors[BLACK]);
	DrawLine(x, y+350, x+400, y+350, 2, colors[BLACK]);
	DrawLine(x, y+400, x+400, y+400, 2, colors[BLACK]);
}


void Board::update_Chain_Numbers()
{
	//updating h_chain_num
	for(int i=0;i<8; i++)
	{
		for(int j=0;j<8; j++)
		{
			if(i==0)				//left most corner gem
				g[i][j]->setH_Chain_Num(1);

			else
			{
				if(g[i][j]->getIdentity() == g[i-1][j]->getIdentity() && g[i][j]->getIdentity() !=0 )				//same gem type as on its left
				{
					if(j!=0)
					{
						if( g[i][j-1]->getIdentity() !=0 && g[i-1][j-1]->getIdentity() !=0)
						{
							g[i][j]->setH_Chain_Num(g[i-1][j]->getH_Chain_Num() + 1);
						}
					}
					else
					{
						g[i][j]->setH_Chain_Num(g[i-1][j]->getH_Chain_Num() + 1);
					}

					int n = g[i][j]->getH_Chain_Num();
					if(g[i][j]->getH_Chain_Num()>=3)
					{
						for(int a=0; a<n; a++)
						{
							g[i-a][j]->setH_PLength(n);
						}

					}
					else
					{
						for(int a=0; a<n; a++)
						{
//							g[i-a][j]->setH_PLength(n);
							g[i-a][j]->setH_PLength(0);

						}
					}
				}
				else				//different gem type than on its left
					g[i][j]->setH_Chain_Num(1);
			}
		}
	}

	//updating v_chain_num
	for(int i=0;i<8; i++)
	{
		for(int j=0;j<8; j++)
		{

			if(j==0)				//bottom most gem
				g[i][j]->setV_Chain_Num(1);
			else
			{
				if(g[i][j]->getIdentity() == g[i][j-1]->getIdentity() && g[i][j]->getIdentity()!=0 )				//same gem type as under it
				{
					g[i][j]->setV_Chain_Num(g[i][j-1]->getV_Chain_Num() + 1);


					int n = g[i][j]->getV_Chain_Num();
					if(g[i][j]->getV_Chain_Num()>=3)
					{
						for(int a=0; a<n; a++)
						{
							g[i][j-a]->setV_PLength(n);
						}

					}
					else
					{
						for(int a=0; a<n; a++)
						{
//							g[i-a][j]->setH_PLength(n);
							g[i][j-a]->setV_PLength(0);

						}
					}
				}

				else				//different gem type than under it
					g[i][j]->setV_Chain_Num(1);
			}
		}
//		cout<<endl;
	}

	for(int i=7; i>=0; i-- )
	{
		for(int j=0; j<8; j++)
		{
//			cout<<"("<< g[j][i]->getH_PLength()<<","<<g[j][i]->getV_PLength()<<") ";
//			cout<<"("<< g[j][i]->getH_Chain_Num()<<", "<<g[j][i]->getV_Chain_Num()<<") ";
//			cout<<"i="<<j<<",j"<<i<<"   ";
		}
//		cout<<endl;
	}

}
void Board::DropNewGem()		//only applied to top most gem
{
	InitRandomizer();
	for(int i=0; i<8;i++)
	{
		int random = GetRandInRange(1, 6);
		if(g[i][7]->getIdentity() != 0)
		{
			continue;
		}
		if(random == 1)
		{
			g[i][7] = new CandyGem(i*50 + 175,7*50+75, 1);		//150+ center of each box
//				cout<<g[i][j]->getIdentity();
		}
		else if(random == 2)
		{
			g[i][7] = new DiamondGem(i*50 + 175,7*50+75, 2);
//				cout<<g[i][j]->getIdentity();

		}
		else if(random == 3)
		{
			g[i][7] = new FlowerGem(i*50 + 175,7*50+75, 3);
//				cout<<g[i][j]->getIdentity();

		}
		else if(random == 4)
		{
			g[i][7] = new LollipopGem(i*50 + 175,7*50+75, 4);
//				cout<<g[i][j]->getIdentity();

		}
		else if(random == 5)
		{
			g[i][7] = new LadyBugGem(i*50 + 175,7*50+75, 5);
//				cout<<g[i][j]->getIdentity();

		}

		g[i][7]->ShowGem();


	}

}

int Board::swapGems(int a1, int b1, int a2, int b2)
{
//	Gem* temp = new ExtraGem(0, 0, colors[PURPLE], 0);
//	temp =	g[a1][b1];
	//	int tempI , tempJ, tempID;
	//	tempI = a1, tempJ = b1, tempID = g[a1][b1]->getIdentity();
	this->BasicSwap(a1, b1, a2, b2);
//	g[a1][b1] = g[a2][b2];
//	g[a1][b1]->ShowGem();
//	g[a2][b2] = g[tempI][tempJ];
//	g[a2][b2]->ShowGem();
//	cout<<"Successfully swapped"<<endl;

	this->update_Chain_Numbers();		// resetting chain number and pop-length after swapping 2 gems

	int score = popGems();
	if(score ==0)
	{
		this->BasicSwap(a1, b1, a2, b2);
		cout<<"Unsuccessful swap"<<endl;
		this->update_Chain_Numbers();
	}
	return score;
}

void Board::GenerateGems()
{
	cout<<"Entered generation"<<endl;
	InitRandomizer();
	for(int i=0; i<8; i++)
	{

		for(int j=0; j<8; j++)
		{
			int random = GetRandInRange(1,6);
			if(random == 1)
			{
				g[i][j] = new CandyGem(i*50 + 175,j*50+75, 1);		//150+ center of each box
//				cout<<g[i][j]->getIdentity();
			}
			else if(random == 2)
			{
				g[i][j] = new DiamondGem(i*50 + 175,j*50+75, 2);
//				cout<<g[i][j]->getIdentity();

			}
			else if(random == 3)
			{
				g[i][j] = new FlowerGem(i*50 + 175,j*50+75, 3);
//				cout<<g[i][j]->getIdentity();

			}
			else if(random == 4)
			{
				g[i][j] = new LollipopGem(i*50 + 175,j*50+75, 4);
//				cout<<g[i][j]->getIdentity();

			}
			else if(random == 5)
			{
				g[i][j] = new LadyBugGem(i*50 + 175,j*50+75, 5);
//				cout<<g[i][j]->getIdentity();

			}

			g[i][j]->ShowGem();
		}
//		cout<<endl;
	}
}


int Board::popGems()
{
//	cout<<"Entered popper"<<endl;
	int score=0, increment =0;
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			bool popped=false;
			//catering for horizontal chains
			if(g[i][j]->getH_PLength() == 3)
			{
				increment=1;
				if(g[i][j]->getV_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
	//			cout<<"GEM ("<<i<<','<<j<<") popped!"<<endl;
				score+=increment;
			}
			else if(g[i][j]->getH_PLength() == 4)
			{
				increment=3;
				if(g[i][j]->getV_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
	//			cout<<"GEM ("<<i<<','<<j<<") popped!"<<endl;
				score+=increment;
			}
			else if(g[i][j]->getH_PLength() == 5)
			{
				increment=5;
				if(g[i][j]->getV_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
	//			cout<<"GEM ("<<i<<','<<j<<") popped!"<<endl;
				score+=increment;
			}

			//catering for vertical chains
			if(g[i][j]->getV_PLength() == 3)
			{
				increment=1;
				if(g[i][j]->getH_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
				score+=increment;
			}
			else if(g[i][j]->getV_PLength() == 4)
			{
				increment=3;
				if(g[i][j]->getH_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
				score+=increment;
			}
			else if(g[i][j]->getV_PLength() == 5)
			{
				increment=5;
				if(g[i][j]->getH_PLength() > 2)
				{
					increment*=2;
				}
				popped = true;
				score+=increment;
			}

			if(popped==true)
			{
				g[i][j] = new ExtraGem(i*50 + 175,j*50+75, 0);
				g[i][j]->ShowGem();

			}
		}
	}
	return score;
}

void Board::BasicSwap(int i, int j, int i2, int j2)
{
	int id2 = g[i][j]->getIdentity();
	int id = g[i2][j2]->getIdentity();
	if(id == 0)
	{
		g[i][j] = new ExtraGem(i*50 + 175,j*50+75, 1);		//150+ center of each box
	}
	else if(id == 1)
	{
		g[i][j] = new CandyGem(i*50 + 175,j*50+75, 1);		//150+ center of each box
	}
	else if(id == 2)
	{
		g[i][j] = new DiamondGem(i*50 + 175,j*50+75, 2);
	}
	else if(id == 3)
	{
		g[i][j] = new FlowerGem(i*50 + 175,j*50+75, 3);
	}
	else if(id == 4)
	{
		g[i][j] = new LollipopGem(i*50 + 175,j*50+75, 4);
	}
	else if(id == 5)
	{
		g[i][j] = new LadyBugGem(i*50 + 175,j*50+75, 5);
	}
	g[i][j]->ShowGem();
	j=j2;
	id = id2;
	i=i2;
	if(id == 0)
	{
		g[i][j] = new ExtraGem(i*50 + 175,j*50+75, 1);		//150+ center of each box
	}
	else if(id == 1)
	{
		g[i][j] = new CandyGem(i*50 + 175,j*50+75, 1);		//150+ center of each box
	}
	else if(id == 2)
	{
		g[i][j] = new DiamondGem(i*50 + 175,j*50+75, 2);
	}
	else if(id == 3)
	{
		g[i][j] = new FlowerGem(i*50 + 175,j*50+75, 3);
	}
	else if(id == 4)
	{
		g[i][j] = new LollipopGem(i*50 + 175,j*50+75, 4);
	}
	else if(id == 5)
	{
		g[i][j] = new LadyBugGem(i*50 + 175,j*50+75, 5);
	}
	g[i][j]->ShowGem();

//	cout<<"Lower Candy's Updated ID = "<<g[i][j]->getIdentity()<<"  ";
//	cout<<"Upper Candy's Updated ID = "<<g[i2][j2]->getIdentity()<<"  ";
}

void Board::CascadeGems()
{
	for(int i=0; i<8; i++){
		for(int j=0; j<7;j++)
		{
			if(g[i][j]->getIdentity()==0)
			{
				BasicSwap(i,j,i, j+1);
			}
		}
	}
}


Board::~Board()
{

}

