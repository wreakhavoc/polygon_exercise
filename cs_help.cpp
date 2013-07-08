#include "stdafx.h"
#include "loadscript.h"

help_command::help_command():cCmdScript("help_command"){}
cCommand* help_command::GetCommandTable(){
	static cCommand commandtable[]=
	{
		{"help",false,0,_HandleHelpCommand,NULL}
	};
	return commandtable;
}
void help_command::_HandleHelpCommand(csysmsg msg,cshapeaccess& shapes){
	printf("\navailable shapes to work with are: triangle,rectangle,square\n");
	printf("'print <shape>' prints the shape's current values, <all> prints all shapes and their current values\n");
	printf("'clear <shape>' deletes the shape and restores it to its default values. <all> clears all shapes.\n");
	printf("'help' prints all available commands\n\n");
	return;
}
help_command* help_command::AddCmd(){
	return new help_command;
}