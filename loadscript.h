#ifndef LOADSCRIPT_H
#define LOADSCRIPT_H
#include "command.h"
#include "sysmsg.h"
#include "polygon.h"

///***forward declare command scripts here***///
class print_command:public cCmdScript{
public:
	print_command();
	cCommand* GetCommandTable();
	static void _HandlePrintTriangle(csysmsg,cshapeaccess&);
	static void _HandlePrintRectangle(csysmsg,cshapeaccess&);
	static void _HandlePrintSquare(csysmsg,cshapeaccess&);
	static void _HandlePrintAll(csysmsg,cshapeaccess&);
	static print_command* AddCmd();
};
class clear_command:public cCmdScript{
public:
	clear_command();
	cCommand* GetCommandTable();
	static void _HandleClearTriangle(csysmsg,cshapeaccess&);
	static void _HandleClearRectangle(csysmsg,cshapeaccess&);
	static void _HandleClearSquare(csysmsg,cshapeaccess&);
	static void _HandleClearAll(csysmsg,cshapeaccess&);
	static clear_command* AddCmd();
};
class help_command:public cCmdScript{
public:
	help_command();
	cCommand* GetCommandTable();
	static void _HandleHelpCommand(csysmsg,cshapeaccess&);
	static help_command* AddCmd();
};
#endif