#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include "sysmsg.h"
#include "polygon.h"
class cCommand{
public:
	std::string m_name;
	bool m_haschild;
	int m_numchild;
	void (*_HandleCmd)(csysmsg,cshapeaccess&);
	cCommand* m_childcmd;
};
class cCmdScript{
	std::string m_name;
public:
	cCmdScript();
	cCmdScript(std::string name);
	virtual cCommand* GetCommandTable();
};

///***To add a new command script, forward declare the class script in loadscript.h
///then define each member in a new .cpp file. #include loadscript.h in the new file.
///For each new script added, increase m_scriptNum in cCmdLoader by 1. Also increase
///the m_pointer array size by 1. The array size should always equal m_scriptNum.
///Then go to the _HandleMsgin definition in command.cpp and append a call to the 
///script's GetCommandTable function in the static cCommand table definition.***///
class cCmdLoader{
	static const int m_scriptNum=3;   //number of command scripts present
public:
	cCmdScript* m_pointer[3];
	cCmdLoader();
	static int GetScriptNum();
	void _HandleMsgin(csysmsg);
};

cCommand* FindCmdinTable(csysmsg,cCommand*);
#endif