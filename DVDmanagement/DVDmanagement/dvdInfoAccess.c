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
	pDVD->rentState = RETURNED;  

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

// 기	능 : 대여 가능 상태로 변경
// 반	환 : 성공 1, 실패 0
int SetDVDReturned(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	
	if (pDVD == 0)
		return 0;

	pDVD->rentState = RETURNED;
	return 1;
}

// 기	능 : 현재 대여 상태 반환
// 반	환 : RETURNED, RENTED, 존재하지 않는 ISBN의 경우 -1 반환
int GetDVDRentState(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return -1;

	return pDVD->rentState;
}

// 기	능 : DVD 정보 저장
// 반	환 : void
void DVDInfoSave(void)
{
	FILE * fp = fopen("DVDInfo.dat", "wb");
	int i;

	if (fp == NULL)
	{
		puts("파일 열람실패");
		return -1;
	}

	fwrite((int*)&numOfDVD, sizeof(int), 1, fp);
	for (i = 0; i < numOfDVD; i++)
		fwrite((dvdInfo*)dvdList[i], sizeof(dvdInfo), 1, fp);


	fclose(fp);
}

// 기	능 : DVD 정보 불러오기
// 반	환 : void
void DVDInfoLoad(void)
{
	FILE * fp = fopen("DVDInfo.dat", "rb");
	int i;

	if (fp == NULL)
	{
		puts("파일 열람실패");
		return -1;
	}

	fread((int*)&numOfDVD, sizeof(int), 1, fp);
	for (i = 0; i < numOfDVD; i++)
	{
		dvdList[i] = (dvdInfo*)malloc(sizeof(dvdInfo) * 1);
		fread((cusInfo*)dvdList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}

/* end of file */