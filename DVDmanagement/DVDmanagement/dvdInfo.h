// Name : dvdInfo.h
// Content : ��ȭ DVD ���� ����ü
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN	30
#define TITLE_LEN	30

enum {ACTION=1, COMIC, SF, ROMANTIC};

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;	//�帣
}dvdInfo;

#endif
/* end of file */