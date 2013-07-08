#include "stdafx.h"
#include <iostream>
#include "polygon.h"
#include "command.h"
#include "loadscript.h"
#include "sysmsg.h"

cCmdScript::cCmdScript(){}
cCmdScript::cCmdScript(std::string name):m_name(name){}
cCommand* cCmdScript::GetCommandTable(){return NULL;}
cCmdLoader::cCmdLoader(){
	m_pointer[0]=clear_command::AddCmd();
	m_pointer[1]=print_command::AddCmd();
	m_pointer[2]=help_command::AddCmd();
}
int cCmdLoader::GetScriptNum(){return m_scriptNum;}

void cCmdLoader::_HandleMsgin(csysmsg msgIn){
	using namespace std;
	typedef void(*_Handle)(csysmsg,cshapeaccess&);
	static cshapeaccess shapes;
	static cCommand table[]=
	{
		*(this->m_pointer[0]->GetCommandTable()),*(this->m_pointer[1]->GetCommandTable()),*(this->m_pointer[2]->GetCommandTable())
	};
	cCommand* executeCmd=FindCmdinTable(msgIn,table);
	if(executeCmd==NULL) return;
	_Handle callback=executeCmd->_HandleCmd;
	callback(msgIn,shapes);
	return;
}

cCommand* FindCmdinTable(csysmsg msg,cCommand* table){
//table should always point to the first element of the table that is about to be searched.
	cCommand* returnCmd=NULL;
	int i=0;
	static int called=0; called++; //keeps track of the number of times the fx is called. Used to indicate which msg.m_token is being used.

	static cCommand* parenttable=table;
	int max;
	if(called==1){
		max=cCmdLoader::GetScriptNum();
	}
	else{
		max=(*parenttable).m_numchild;
	}

	for(;i<max;i++){
		if(msg.m_token[called-1]==table[i].m_name){
			if(table[i].m_haschild){
				parenttable=table+i;
				returnCmd=FindCmdinTable(msg,table[i].m_childcmd);
				called=0;
				return returnCmd;
			}
			else{
				returnCmd=table+i;
				called=0;
				return returnCmd;
			}
		}
		else continue;
	}
	cout << "Error. No such command '" << msg.m_token[0] << "'" << endl;
	return returnCmd;
}