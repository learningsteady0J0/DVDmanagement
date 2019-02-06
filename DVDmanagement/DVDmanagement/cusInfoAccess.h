// Name : cusInfoAccess.h
// Content : 고객 정보 저장 및 잠조 함수들의 선언
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsRegistID(char*ID);

#endif

/* end of file */