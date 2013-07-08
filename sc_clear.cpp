#include "stdafx.h"
#include "loadscript.h"

clear_command::clear_command():cCmdScript("clear_command"){}
cCommand* clear_command::GetCommandTable(){
	static cCommand cleartable[]=
	{
		{"triangle",false,0,_HandleClearTriangle,NULL},
		{"tri",false,0,_HandleClearTriangle,NULL},
		{"rectangle",false,0,_HandleClearRectangle,NULL},
		{"rec",false,0,_HandleClearRectangle,NULL},
		{"square",false,0,_HandleClearSquare,NULL},
		{"squ",false,0,_HandleClearSquare,NULL},
		{"all",false,0,_HandleClearAll,NULL}
	};
	static cCommand commandtable[]=
	{
		{"clear",true,7,NULL,cleartable}
	};
	return commandtable;
}
void clear_command::_HandleClearTriangle(csysmsg msg,cshapeaccess& shapes){
	std::string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. clear triangle has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.TRI.ShapeClear();
	cout << "triangle cleared..." << endl;
	return;
}
void clear_command::_HandleClearRectangle(csysmsg msg,cshapeaccess& shapes){
	std::string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. clear rectangle has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.REC.ShapeClear();
	cout << "rectangle cleared..." << endl;
	return;
}
void clear_command::_HandleClearSquare(csysmsg msg,cshapeaccess& shapes){
	std::string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. clear square has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.SQU.ShapeClear();
	cout << "square cleared..." << endl;
	return;
}
void clear_command::_HandleClearAll(csysmsg msg,cshapeaccess& shapes){
	std::string next=msg.m_token[2];
	if(!next.empty()){
		cout << "Error. clear all has no subcommand '" << next << "'" << endl;
		return;
	}
	shapes.TRI.ShapeClear();
	shapes.REC.ShapeClear();
	shapes.SQU.ShapeClear();
	cout << "all shapes cleared..." << endl;
	return;
}
clear_command* clear_command::AddCmd(){
	return new clear_command;
}