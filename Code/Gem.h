/*
 * Gem.h
 *
 *  Created on: Jun 7, 2020
 *      Author: szm
 */

#ifndef GEM_H_
#define GEM_H_


class Gem	//abstract class
{
protected:
	int identity;
	int x;
	int y;
	float* color;
	int h_chain_num;	//variable to store a number for similar gems are together in a row
	int v_chain_num;	//variable to store a number for similar gems are together in a column
	int h_poppingLength;	//counting how many similar gems are in a chain in a row
	int v_poppingLength;	//counting how many similar gems are in a chain in a column

public:
	Gem(int X,int Y, float* Color, int id);
//	int getType();
    void setX(int X);
    void setY(int Y);
    int getX();
    int getY();
    void setColor(float* Color);
    float* getColor();

	void setH_Chain_Num(int count);
	int getH_Chain_Num();
	void setV_Chain_Num(int count);
	int getV_Chain_Num();
	void setH_PLength(int length);
	int getH_PLength();
	void setV_PLength(int length);
	int getV_PLength();

//	virtual int setIdentity(int id) =0;
//   void setIdentity(int id);
//	virtual int getIdentity() =0;
   int getIdentity();
   virtual void ShowGem() =0; 		//virtual function
	virtual ~Gem();
};

#endif /* GEM_H_ */
