// Name : rentInfoAccess.c
// Content : DVD �뿩 ���� ���� �� ���� �Լ����� ����
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

// ��	�� : �뿩 ������ ����
// ��	ȯ : void
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;
}

// ��	�� : Ư�� ISBN�� DVD �뿩 ���� ��ü ���
// ��	ȯ : void
void PrintOutRentAllCusInfo(char * ISBN)
{
	int i;
	for (i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ISBN, rentList[i].ISBN) == 0)
		{
			printf("�뿩��: %d\n", rentList[i].rentDay);
			ShowCustomerInfo(GetCusPtrByID(rentList[i].cusID));
		}
	}
}

// ��	�� : ���� �Ⱓ �ȿ� �̷��� Ư�� ���� DVD �뿩 ���� ���
// ��	ȯ : void
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
		puts("�ش� ���̵� �������� �ʽ��ϴ�.");
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

// ��	�� : �뿩 ���� ����
// ��	ȯ : void
void rentInfoSave(void)
{
	FILE * fp = fopen("rentInfo.dat", "wb");
	int i;

	if (fp == NULL)
	{
		puts("���� ��������");
		return -1;
	}

	fwrite((int*)&numOfRentCus, sizeof(int), 1, fp);
	fwrite((dvdRentInfo*)&rentList[i], sizeof(dvdRentInfo), numOfRentCus, fp);


	fclose(fp);
}

// ��	�� : �ݳ� ���� �ҷ�����
// ��	ȯ : void
void rentInfoLoad(void)
{
	FILE * fp = fopen("rentInfo.dat", "rb");
	int i;

	if (fp == NULL)
	{
		puts("���� ��������");
		return -1;
	}

	fread((int*)&numOfRentCus, sizeof(int), 1, fp);
	fread((cusInfo*)&rentList[i], sizeof(cusInfo), numOfRentCus, fp);


	fclose(fp);
}
/* end of file */