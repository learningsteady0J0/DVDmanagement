// Name : cusManager.c
// Content : �� ���� ���� ó�� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

// ��	�� : �ű� ȸ�� ����
// ��	ȯ : void
void RegistCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];

	while (1) {
		fputs("ID �Է�: ", stdout);
		gets(ID);

		if (IsRegistID(ID) == 0)
			break;

		puts("������ �Ǿ��ִ� ID�Դϴ�. �ٸ� ID�� �������ּ���.");
	}
	fputs("�̸� �Է�: ", stdout);
	gets(name);
	fputs("��ȭ��ȣ �Է�: ", stdout);
	gets(num);

	if (AddCusInfo(ID, name, num) != 0)
	{
		puts("������ �Ϸ�Ǿ����ϴ�.");
	}
	else
	{
		puts("�����߻�");
		getchar();
		return;
	}
	getchar();

}

// ��	�� : ID�� ���� ȸ�� ���� �˻�
// ��	ȯ : void
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * ptr;
	fputs("ã�� ���̵� �Է����ּ���.", stdout);
	gets(ID);
	ptr = GetCusPtrByID(ID);

	if (ptr == NULL)
	{
		puts("ã���ô� ���̵�� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else
	{
		ShowCustomerInfo(ptr);
	}

	getchar();
}

/* end of file */