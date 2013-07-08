#include "stdafx.h"
#include <iostream>
#include <string>
#define MAXCSTRINGLENGTH stringfull.at(counter)
using namespace std;

char* ResizeArray(char* cnarray){  //function that takes a character array as an argument and returns a pointer to a new array that is the right size
	int sizeofarray = 0;
	for(sizeofarray=0;cnarray[sizeofarray]!='\0';sizeofarray++){}
	char* input = new char[sizeofarray];
	for(sizeofarray=0;input[sizeofarray]!='\0';sizeofarray++){
		input[sizeofarray]=cnarray[sizeofarray];
	}
	return input;
}

void ParseArray(char* cnarray,int alldspace){
	cout << "Parsearray called" << endl;
	int counter=0;
	for(;counter<alldspace;counter++){
		cout << "["<<counter<<"] " << cnarray[counter] << " " << char(cnarray[counter]) << " " << int(cnarray[counter]);
		if(cnarray[counter]) cout << " true" << endl;
		else cout << " false" << endl;
		if(cnarray[counter]=='\0') cout << "terminating char reached @ index of " << counter << endl;
	}
	return;
}

void DelSpace(char* input){
	int icnt=0;
	int incnt=0;
	for(;input[icnt];icnt++){
		if(input[icnt]==' '){
			incnt=icnt;
			while(input[incnt]){
				input[incnt]=input[incnt+1];
				incnt++;
			}
			if(input[icnt]==' '){
				icnt--;
				continue;
			}
			else continue;
		}
		else continue;
	}
	return;
}

string GetInput(){
	string input="";
	cout << "Enter input...\n";
	getline(cin,input);
	return input;
}

void AddTermChar(char* cstring){
	int counter=0;
	for(;cstring[counter];counter++){}
	cstring[counter]='\0';
	return;
}

int GetTermLoc(char* cstring){
	if(!cstring){
		cout << "error. false cstring passed" << endl;
		return 0;
	}

	int counter=0;
	for(;;counter++){
		if(cstring[counter]=='\0'){
			return counter;
		}
	}
	return 0; //should never get here
}