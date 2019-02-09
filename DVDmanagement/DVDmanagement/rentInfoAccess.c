// Name : rentInfoAccess.c
// Content : DVD 대여 정보 저장 및 참조 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN	100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

// 기	능 : 대여 정보를 저장
// 반	환 : void
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;
}

// 기	능 : 특정 ISBN의 DVD 대여 정보 전체 출력
// 반	환 : void
void PrintOutRentAllCusInfo(char * ISBN)
{
	int i;
	for (i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ISBN, rentList[i].ISBN) == 0)
		{
			printf("대여일: %d\n", rentList[i].rentDay);
			ShowCustomerInfo(GetCusPtrByID(rentList[i].cusID));
		}
	}
}

// 기	능 : 일정 기간 안에 이뤄진 특정 고객의 DVD 대여 정보 출력
// 반	환 : void
void PrintOutCusAllRentInfo(char*ID, unsigned int start, unsigned int end)
{
	int i;
	int idx[RENT_LEN];
	int count=0;
	for (i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ID, rentList[i].cusID) == 0)
		{
			idx[count++] = i;
		}
	}

	if (count == 0)
	{
		puts("해당 아이디가 존재하지 않습니다.");
		return;
	}

	for (i = 0; i < count; i++)
	{
		if (start <= rentList[idx[i]].rentDay && rentList[idx[i]].rentDay <= end)
		{
			ShowDVDRENTInfo(rentList[idx[i]]);
		}
	}


}

// 기	능 : 대여 정보 저장
// 반	환 : void
void rentInfoSave(void)
{
	FILE * fp = fopen("rentInfo.dat", "wb");
	int i;

	if (fp == NULL)
	{
		puts("파일 열람실패");
		return -1;
	}

	fwrite((int*)&numOfRentCus, sizeof(int), 1, fp);
	fwrite((dvdRentInfo*)&rentList[i], sizeof(dvdRentInfo), numOfRentCus, fp);


	fclose(fp);
}

// 기	능 : 반납 정보 불러오기
// 반	환 : void
void rentInfoLoad(void)
{
	FILE * fp = fopen("rentInfo.dat", "rb");
	int i;

	if (fp == NULL)
	{
		puts("파일 열람실패");
		return -1;
	}

	fread((int*)&numOfRentCus, sizeof(int), 1, fp);
	fread((cusInfo*)&rentList[i], sizeof(cusInfo), numOfRentCus, fp);


	fclose(fp);
}
/* end of file */