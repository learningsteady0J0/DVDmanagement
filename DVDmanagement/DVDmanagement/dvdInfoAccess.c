// Name : DVDInfoAccess.c
// Content : DVD 정보 저장 및 참조 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVDTITLE	100

static dvdInfo * dvdList[MAX_DVDTITLE];
static int numOfDVD = 0;

// 기	능 : dvdInfo 할당 및 저장
// 반	환 : 성공 시 '등록된 정보의 개수',  실패 시 0을 반환  // 실패시 0반환???
int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDVD >= MAX_DVDTITLE)
	{
		puts("최대 100개까지만 저장이 됩니다.");
		return 0;
	}

	pDVD = (dvdInfo*)malloc(sizeof(dvdInfo) * 1);

	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;

	dvdList[numOfDVD++] = pDVD;

	return numOfDVD;
}

// 기	능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터 반환
// 반	환 : 등록 안된 ISBN의 경우 NULL 포인터 반환
dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{
		if (strcmp(dvdList[i]->ISBN, ISBN) == 0)
		{
			return dvdList[i];
		}
	}

	return (dvdInfo*)0;  //널 포인터.
}

// 기	능 : 등록 된 ISBN인지 확인
// 반	환 : 등록 되었으면 1, 아니면 0 반환
int IsRegistISBN(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == NULL)
		return 0;
	else
		return 1;

	return 0;
}

/* end of file */