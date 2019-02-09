// Name : screenOut.h
// Content : 콘솔 출력을 우한 함수들의 선언
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowDVDInfo(dvdInfo*pDVD);
void ShowDVDRENTInfo(dvdRentInfo);

#endif

/* end of file */