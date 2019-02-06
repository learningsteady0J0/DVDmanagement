// Name : dvdManager.c
// Content : DVD ���� ���� ó�� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

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

/* end of file */