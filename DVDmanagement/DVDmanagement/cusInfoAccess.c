// Name : cusInfoAccess.c
// Content : 고객 정보 저장 및 참조 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER	100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

// 기	능 : cusInfo 할당 및 저장
// 반	환 : 성공 시 '등록된 정보의 개수',  실패 시 0을 반환  // 실패시 0반환???
int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo * pcus;

	if (numOfCustomer >= MAX_CUSTOMER)
	{
		puts("최대 100명까지만 저장이 됩니다.");
		return 0;
	}

	pcus = (cusInfo*)malloc(sizeof(cusInfo) * 1);

	strcpy(pcus->ID, ID);
	strcpy(pcus->name, name);
	strcpy(pcus->phoneNum, num);

	cusList[numOfCustomer++] = pcus;

	return numOfCustomer;
}

// 기	능 : 해당 ID의 정보를 담고 있는 변수의 포인터 반환
// 반	환 : 등록 안된 ID의 경우 NULL 포인터 반환
cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (strcmp(cusList[i]->ID, ID) == 0)
		{
			return cusList[i];
		}
	}

	return (cusInfo*)0;  //널 포인터.
}

// 기	능 : 가입 된 ID인지 확인
// 반	환 : 가입 되었으면 1, 아니면 0 반환
int IsRegistID(char*ID)
{
	cusInfo * pCus = GetCusPtrByID(ID);

	if (pCus == NULL)
		return 0;
	else
		return 1;
	
	return 0;
}

/* end of file */