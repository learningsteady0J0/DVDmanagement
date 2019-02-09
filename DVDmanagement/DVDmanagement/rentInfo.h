// Name : rentInfo.h
// Content : ��ȭ DVD ���� ����ü
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "cusInfo.h"  //��� ID_LEN�� ����� ����
#include "dvdInfo.h"


typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
} dvdRentInfo;

#endif
/* end of file */