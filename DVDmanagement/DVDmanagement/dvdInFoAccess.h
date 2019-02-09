// Name : DVDInfoAccess.h
// Content : DVD ���� ���� �� ���� �Լ����� ����
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