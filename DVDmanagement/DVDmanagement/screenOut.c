// Name : screenOut.c
// Content : �ܼ� ����� ���� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

#define GENRE_SIZE	10

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
	system("cls");  //stdlib.h

	printf("���������������������� �� �� ������������������������������ \n");
	printf(" 1. �ű԰��� \n");
	printf(" 2. ���˻� \n");
	printf("������������������������������������������������������������������ \n");
	printf(" 3. �ű�DVD��� \n");
	printf(" 4. DVD�˻� \n");
	printf("������������������������������������������������������������������ \n");
	printf(" 5. ���� \n");
	printf("������������������������������������������������������������������ \n");
	printf("����>> ");
}

/* �� ������ �⺻ ���� ��� */
void ShowCustomerInfo(cusInfo * pCus)
{
	printf("������������������������������������������������������������������ \n");
	printf("�� �� ID : %s \n", pCus->ID);
	printf("�� �� �̸� : %s \n", pCus->name);
	printf("�� �� ��ȭ��ȣ : %s \n", pCus->phoneNum);
	printf("������������������������������������������������������������������ \n\n");
}

/* DVD�� �⺻ ���� ��� */
void ShowDVDInfo(dvdInfo * pDVD)
{
	char * genre[GENRE_SIZE];
	if (pDVD->genre == ACTION)
		strcpy(genre, "Action");
	else if (pDVD->genre == COMIC)
		strcpy(genre, "Comic");
	else if (pDVD->genre == SF)
		strcpy(genre, "SF");
	else if (pDVD->genre == ROMANTIC)
		strcpy(genre, "Romantic");

	printf("������������������������������������������������������������������ \n");
	printf("�� �� ISBN : %s \n", pDVD->ISBN);
	printf("�� �� Title : %s \n", pDVD->title);
	printf("�� �� GENRE : %s \n", genre);
	printf("������������������������������������������������������������������ \n\n");
}

/* end of file */