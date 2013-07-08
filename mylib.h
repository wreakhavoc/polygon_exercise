#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <string>
char* ResizeArray(char* cnarray);
void ParseArray(char* cnarray,int sizeofarray);
void DelSpace(char* input);
std::string GetInput();
void AddTermChar(char* cstring);
int GetTermLoc(char* cstring);
#pragma warning(disable:4996)
#endif