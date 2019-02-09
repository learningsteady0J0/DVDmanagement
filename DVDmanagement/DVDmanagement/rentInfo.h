// Name : rentInfo.h
// Content : 영화 DVD 관리 구조체
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "cusInfo.h"  //상수 ID_LEN의 사용을 위해
#include "dvdInfo.h"


typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
} dvdRentInfo;

#endif
/* end of file */