#include "stdafx.h"
#include <iostream>
#include "sysmsg.h"
#include <cstring>
using namespace std;
#define BUFFER 50

csysmsg::csysmsg(){
	cout << "Enter message..." << endl;
	char str[BUFFER];
	cin.getline(str,BUFFER,'\n');
	char * pch;
	pch = strtok (str," ");
	int i=0;
	while (pch != NULL){
		m_token[i]=pch;
		pch = strtok (NULL, " ");
		i++;
	}
}