// Name : DVDInfoAccess.h
// Content : DVD 정보 저장 및 잠조 함수들의 선언
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDVDPtrByISBN(char * ISBN);
int IsRegistISBN(char*ISBN);
int SetDVDReturned(char*ISBN);
int GetDVDRentState(char*ISBN);
void DVDInfoSave(void);
void DVDInfoLoad(void);
#endif

/* end of file */