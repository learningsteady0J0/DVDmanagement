// Name : main.c
// Content : DVD �뿩 ���� ���α׷� main
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"
#include "dvdManager.h"

enum {CUS_REGIST=1, CUS_SEARCH, DVD_REGIST,DVD_SEARCH, QUIT};

int main(void)
{
	int inputMenu = 0;

	while (1)
	{
		ShowMenu();
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu)
		{
		case CUS_REGIST:
			RegistCustomer();
			break;


		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;


		case DVD_SEARCH:
			SearchDVDInfo();
			break;
		}

		if (inputMenu == QUIT)
		{
			puts("�̿��� �ּż� �����մϴ�~");
			break;
		}
	}
	return 0;
}

/* end of file */