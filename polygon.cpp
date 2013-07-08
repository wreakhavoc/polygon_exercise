#include "stdafx.h"
#include <iostream>
#include "polygon.h"
double ctriangle::GetSide(char ind){
	switch(ind){
	case 'A': return sideA;
	case 'B': return sideB;
	case 'C': return sideC;
	default: printf("Error. default in switch reached in GetSide fxcall\n");
	}
	return 0;
}

double ctriangle::GetAngle(char ind){
	switch(ind){
	case 'A': return angleA;
	case 'B': return angleB;
	case 'C': return angleC;
	default: printf("Error. default case reached in switch in GetAngle fxcall\n");
	}
	return 0;
}

void ctriangle::PrintAll(){
	printf("\nTRIANGLE\n");
	printf("area=%f\n",GetArea());
	printf("perimeter=%f\n",GetPerimeter());
	printf("height=%f\n",GetHeight());
	printf("base=%f\n",GetBase());
	printf("sideA=%f\n",GetSide('A'));
	printf("sideB=%f\n",GetSide('B'));
	printf("sideC=%f\n",GetSide('C'));
	printf("angleA=%f\n",GetAngle('A'));
	printf("angleB=%f\n",GetAngle('B'));
	printf("angleC=%f\n",GetAngle('C'));
	return;
}

void crectangle::PrintAll(){
	printf("\nRECTANGLE\n");
	printf("area=%f\n",GetArea());
	printf("perimeter=%f\n",GetPerimeter());
	printf("height=%f\n",GetHeight());
	printf("base=%f\n",GetBase());
	return;
}

void csquare::PrintAll(){
	printf("\nSQUARE\n");
	printf("area=%f\n",GetArea());
	printf("perimeter=%f\n",GetPerimeter());
	printf("height=%f\n",GetHeight());
	printf("base=%f\n",GetBase());
}