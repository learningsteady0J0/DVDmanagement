// Name : cusInfoAccess.c
// Content : �� ���� ���� �� ���� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER	100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

// ��	�� : cusInfo �Ҵ� �� ����
// ��	ȯ : ���� �� '��ϵ� ������ ����',  ���� �� 0�� ��ȯ  // ���н� 0��ȯ???
int AddCusInfo(char * ID, char * name, char * num)
{
	cusInfo * pcus;

	if (numOfCustomer >= MAX_CUSTOMER)
	{
		puts("�ִ� 100������� ������ �˴ϴ�.");
		return 0;
	}

	pcus = (cusInfo*)malloc(sizeof(cusInfo) * 1);

	strcpy(pcus->ID, ID);
	strcpy(pcus->name, name);
	strcpy(pcus->phoneNum, num);

	cusList[numOfCustomer++] = pcus;

	return numOfCustomer;
}

// ��	�� : �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ
// ��	ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ
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

	return (cusInfo*)0;  //�� ������.
}

// ��	�� : ���� �� ID���� Ȯ��
// ��	ȯ : ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
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