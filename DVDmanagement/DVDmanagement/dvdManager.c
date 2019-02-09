// Name : dvdManager.c
// Content : DVD ���� ���� ó�� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"
#include "rentInFoAccess.h"

// ��	�� : �ű� DVD ���
// ��	ȯ : void
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	while (1) {
		fputs("ISBN �Է�: ", stdout);
		gets(ISBN);

		if (IsRegistISBN(ISBN) == 0)
			break;

		puts("��� �Ǿ��ִ� ISBN�Դϴ�. �ٸ� ISBN�� �Է����ּ���.");
	}
	fputs("���� �Է�: ", stdout);
	gets(title);
	while (1)
	{
		fputs("�帣 �Է� <�׼� 1, �ڹ� 2, SF 3, �θǽ� 4>: ", stdout);
		scanf("%d", &genre);
		getchar();
		if (1 <= genre && genre <= 4)
			break;
	}

	if (AddDVDInfo(ISBN, title, genre) != 0)
	{
		puts("����� �Ϸ�Ǿ����ϴ�.");
	}
	else
	{
		puts("�����߻�");
		getchar();
		return;
	}
	getchar();

}

// ��	�� : ISBN�� ���� ȸ�� ���� �˻�
// ��	ȯ : void
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * ptr;
	fputs("ã�� ISBN�� �Է����ּ���.", stdout);
	gets(ISBN);
	ptr = GetDVDPtrByISBN(ISBN);

	if (ptr == NULL)
	{
		puts("ã���ô� ISBN�� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else
	{
		ShowDVDInfo(ptr);
	}

	getchar();
}

// ��	�� : ISBN�� ����  DVD �뿩
// ��	ȯ : void
void RentDVD(void)
{
	int registCus;
	int rentstete;
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	unsigned int rentDay;
	dvdInfo * ptr;
	fputs("�뿩 DVD ISBN �Է�: ", stdout);
	gets(ISBN);
	ptr = GetDVDPtrByISBN(ISBN);
	
	if (ptr == NULL)
	{
		puts("�ش� DVD�� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	
	// �뿩 ������ �������� Ȯ��
	rentstete = GetDVDRentState(ISBN);
	if (rentstete == RENTED)
	{
		puts("�뿩 ���̶� �뿩�� �Ұ����մϴ�.");
		getchar();
		return;
	}

	// �뿩 ���� ����
	puts("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.");
	fputs("�뿩 �� ID �Է�:", stdout);
	gets(ID);

	registCus = IsRegistID(ID);
	if (registCus == 0)
	{
		puts("���� ���� �ƴմϴ�.");
		getchar();
		return;
	}

	fputs("�뿩 ��¥ �Է� : ", stdout);
	scanf("%u", &rentDay);
	getchar();

	AddRentList(ISBN, ID, rentDay);
	ptr->rentState = RENTED;
	
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	
	getchar();
}

// ��	�� : ISBN�� ����  DVD �ݳ�
// ��	ȯ : void
void ReturnDVD(void)
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentStete;
	dvdInfo * ptr;

	fputs("�ݳ� DVD ISBN �Է�: ", stdout);
	gets(ISBN);
	registDVD = IsRegistISBN(ISBN);

	if (registDVD == 0)
	{
		puts("�ش� DVD�� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	
	rentStete = GetDVDRentState(ISBN);

	if (rentStete == RENTED)
	{
		SetDVDReturned(ISBN);
		puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	}
	else
		puts("�뿩���� ���� DVD �Դϴ�.");

	

	getchar();
}

// ��	�� : DVD �뿩�� ��ü ��ȸ
// ��	ȯ : void
void RentedIDShowAll(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dPtr;

	fputs("DVD ISBN �Է�: ", stdout);
	gets(ISBN);
	dPtr = GetDVDPtrByISBN(ISBN);

	if (dPtr == NULL)
	{
		puts("�ش� DVD�� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}

	PrintOutRentAllCusInfo(ISBN);
	puts("��ȸ�� �Ϸ��߽��ϴ�.\n");
	getchar();
}

// ��	�� : �� �뿩 DVD ��ü ��ȸ
// ��	ȯ : void
void RentedDVDShowAll(void)
{
	char ID[ID_LEN];
	int start, end;

	fputs("ID �Է�: ", stdout);
	gets(ID);

	if (IsRegistID(ID) == 0)
	{
		puts("�ش� ���̵� �����ϴ�.");
		getchar();
		return;
	}
	fputs("�뿩 �Ⱓ �Է�: ", stdout);
	scanf("%d %d", &start, &end);
	getchar();


	PrintOutCusAllRentInfo(ID, start, end);

	puts("��ȸ�� �Ϸ��߽��ϴ�.\n");
	getchar();
}
/* end of file */