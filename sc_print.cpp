#include "stdafx.h"
#include <iostream>
#include "loadscript.h"
#include <string>
using namespace std;
print_command::print_command():cCmdScript("print_command"){}
cCommand* print_command::GetCommandTable(){
	static cCommand printtable[]=
	{
		{"triangle",false,0,_HandlePrintTriangle,NULL},
		{"tri",false,0,_HandlePrintTriangle,NULL},
		{"rectangle",false,0,_HandlePrintRectangle,NULL},
		{"rec",false,0,_HandlePrintRectangle,NULL},
		{"square",false,0,_HandlePrintSquare,NULL},
		{"squ",false,0,_HandlePrintSquare,NULL},
		{"all",false,0,_HandlePrintAll,NULL},
	};
	static cCommand commandtable[]=
	{
		{"print",true,7,NULL,printtable}
	};
	return commandtable;
}

void print_command::_HandlePrintTriangle(csysmsg msg,cshapeaccess& shapes){
	string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. print triangle has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.TRI.PrintAll();
	return;
}
	
void print_command::_HandlePrintRectangle(csysmsg msg,cshapeaccess& shapes){
	string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. print rectangle has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.REC.PrintAll();
	return;
}

void print_command::_HandlePrintSquare(csysmsg msg,cshapeaccess& shapes){
	string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. print square has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.SQU.PrintAll();
	return;
}

void print_command::_HandlePrintAll(csysmsg msg,cshapeaccess& shapes){
	string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. print all has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.TRI.PrintAll();
	shapes.REC.PrintAll();
	shapes.SQU.PrintAll();
	return;
}
print_command* print_command::AddCmd(){
	return new print_command;
}