// Name : screenOut.c
// Content : �ܼ� ����� ���� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
	system("cls");  //stdlib.h

	printf("���������������������� �� �� ������������������������������ \n");
	printf(" 1. �ű԰��� \n");
	printf(" 2. ���˻� \n");
	printf(" 3. ���� \n");
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

/* end of file */