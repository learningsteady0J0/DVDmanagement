// Name : DVDInfoAccess.c
// Content : DVD ���� ���� �� ���� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVDTITLE	100

static dvdInfo * dvdList[MAX_DVDTITLE];
static int numOfDVD = 0;

// ��	�� : dvdInfo �Ҵ� �� ����
// ��	ȯ : ���� �� '��ϵ� ������ ����',  ���� �� 0�� ��ȯ  // ���н� 0��ȯ???
int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDVD >= MAX_DVDTITLE)
	{
		puts("�ִ� 100�������� ������ �˴ϴ�.");
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

// ��	�� : �ش� ISBN�� ������ ��� �ִ� ������ ������ ��ȯ
// ��	ȯ : ��� �ȵ� ISBN�� ��� NULL ������ ��ȯ
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

	return (dvdInfo*)0;  //�� ������.
}

// ��	�� : ��� �� ISBN���� Ȯ��
// ��	ȯ : ��� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
int IsRegistISBN(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == NULL)
		return 0;
	else
		return 1;

	return 0;
}

// ��	�� : �뿩 ���� ���·� ����
// ��	ȯ : ���� 1, ���� 0
int SetDVDReturned(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	
	if (pDVD == 0)
		return 0;

	pDVD->rentState = RETURNED;
	return 1;
}

// ��	�� : ���� �뿩 ���� ��ȯ
// ��	ȯ : RETURNED, RENTED, �������� �ʴ� ISBN�� ��� -1 ��ȯ
int GetDVDRentState(char*ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return -1;

	return pDVD->rentState;
}

// ��	�� : DVD ���� ����
// ��	ȯ : void
void DVDInfoSave(void)
{
	FILE * fp = fopen("DVDInfo.dat", "wb");
	int i;

	if (fp == NULL)
	{
		puts("���� ��������");
		return -1;
	}

	fwrite((int*)&numOfDVD, sizeof(int), 1, fp);
	for (i = 0; i < numOfDVD; i++)
		fwrite((dvdInfo*)dvdList[i], sizeof(dvdInfo), 1, fp);


	fclose(fp);
}

// ��	�� : DVD ���� �ҷ�����
// ��	ȯ : void
void DVDInfoLoad(void)
{
	FILE * fp = fopen("DVDInfo.dat", "rb");
	int i;

	if (fp == NULL)
	{
		puts("���� ��������");
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