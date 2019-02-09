// Name : dvdInfo.h
// Content : 영화 DVD 관리 구조체
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"  //상수 ID_LEN의 사용을 위해

#define ISBN_LEN	30
#define TITLE_LEN	30

enum {ACTION=1, COMIC, SF, ROMANTIC};
enum {RENTED, RETURNED};

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;	//장르
	int rentState; // 대여 상태 정보
}dvdInfo;

#endif
/* end of file */