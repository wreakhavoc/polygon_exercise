#ifndef POLYGON_H
#define POLYGON_H
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class cpolygon{
protected:
	double base;
	double height;
	double area;
	double perimeter;
public:
	cpolygon():base(0),height(0),area(0),perimeter(0){}
	void SetBase(double measure){base=measure;}
	void SetHeight(double measure){height=measure;}
	void SetArea(double measure){area=measure;}
	void SetPerimeter(double measure){perimeter=measure;}
	double GetBase(){return base;}
	double GetHeight(){return height;}
	double GetArea(){return area;}
	double GetPerimeter(){return perimeter;}
	virtual void ShapeClear(){
		base=0,height=0,area=0,perimeter=0;
		return;
	}
};

class ctriangle:public cpolygon{
protected:
	double sideA;
	double sideB;
	double sideC;
	double angleA;
	double angleB;
	double angleC;
public:
	ctriangle():cpolygon(){sideA=0,sideB=0,sideC=0,angleA=0,angleB=0,angleC=0;}
	void SetSide(char,double);
	void SetAngle(char,double);
	double GetSide(char);
	double GetAngle(char);
	void PrintAll();
	void ShapeClear(){
		base=0,height=0,area=0,perimeter=0,sideA=0,sideB=0,sideC=0,angleA=0,angleB=0,angleC=0;
		return;
	}
	static ctriangle* GetNewTri(){return new ctriangle;}
};

class crectangle:public cpolygon{
public:
	static crectangle* GetNewRec(){return new crectangle;}
	void PrintAll();
};

class csquare:public crectangle{
public:
	void SetBase(double measure){base=measure;height=base;return;}
	void SetHeight(double measure){height=measure;base=height;return;}
	static csquare* GetNewSqu(){return new csquare;}
	void PrintAll();
};

class cshapeaccess{
public:
	ctriangle TRI;
	crectangle REC;
	csquare SQU;
};

#endif