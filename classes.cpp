#include "stdafx.h"
#include <iostream>
#include "polygon.h"
#include "sysmsg.h"
#include "command.h"
#include "string.h"
using namespace std;

int main(){
	cCmdLoader accessor;
	while(true){
		csysmsg MSGin;
		accessor._HandleMsgin(MSGin);
	}
	return 0;
}