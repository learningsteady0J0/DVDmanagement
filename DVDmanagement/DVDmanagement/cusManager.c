// Name : cusManager.c
// Content : 고객 관련 업무 처리 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

// 기	능 : 신규 회원 가입
// 반	환 : void
void RegistCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];

	while (1) {
		fputs("ID 입력: ", stdout);
		gets(ID);

		if (IsRegistID(ID) == 0)
			break;

		puts("가입이 되어있는 ID입니다. 다른 ID를 선택해주세요.");
	}
	fputs("이름 입력: ", stdout);
	gets(name);
	fputs("전화번호 입력: ", stdout);
	gets(num);

	if (AddCusInfo(ID, name, num) != 0)
	{
		puts("가입이 완료되었습니다.");
	}
	else
	{
		puts("오류발생");
		getchar();
		return;
	}
	getchar();

}

// 기	능 : ID를 통한 회원 정보 검색
// 반	환 : void
void SearchCusInfo(void)
{
	char ID[ID_LEN];
	cusInfo * ptr;
	fputs("찾는 아이디를 입력해주세요.", stdout);
	gets(ID);
	ptr = GetCusPtrByID(ID);

	if (ptr == NULL)
	{
		puts("찾으시는 아이디는 존재하지 않습니다.");
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