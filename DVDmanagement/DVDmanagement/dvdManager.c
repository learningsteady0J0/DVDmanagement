// Name : dvdManager.c
// Content : DVD 관련 업무 처리 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"
#include "rentInFoAccess.h"

// 기	능 : 신규 DVD 등록
// 반	환 : void
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	while (1) {
		fputs("ISBN 입력: ", stdout);
		gets(ISBN);

		if (IsRegistISBN(ISBN) == 0)
			break;

		puts("등록 되어있는 ISBN입니다. 다른 ISBN를 입력해주세요.");
	}
	fputs("제목 입력: ", stdout);
	gets(title);
	while (1)
	{
		fputs("장르 입력 <액션 1, 코믹 2, SF 3, 로맨스 4>: ", stdout);
		scanf("%d", &genre);
		getchar();
		if (1 <= genre && genre <= 4)
			break;
	}

	if (AddDVDInfo(ISBN, title, genre) != 0)
	{
		puts("등록이 완료되었습니다.");
	}
	else
	{
		puts("오류발생");
		getchar();
		return;
	}
	getchar();

}

// 기	능 : ISBN를 통한 회원 정보 검색
// 반	환 : void
void SearchDVDInfo(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * ptr;
	fputs("찾는 ISBN을 입력해주세요.", stdout);
	gets(ISBN);
	ptr = GetDVDPtrByISBN(ISBN);

	if (ptr == NULL)
	{
		puts("찾으시는 ISBN은 존재하지 않습니다.");
		getchar();
		return;
	}
	else
	{
		ShowDVDInfo(ptr);
	}

	getchar();
}

// 기	능 : ISBN를 통한  DVD 대여
// 반	환 : void
void RentDVD(void)
{
	int registCus;
	int rentstete;
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	unsigned int rentDay;
	dvdInfo * ptr;
	fputs("대여 DVD ISBN 입력: ", stdout);
	gets(ISBN);
	ptr = GetDVDPtrByISBN(ISBN);
	
	if (ptr == NULL)
	{
		puts("해당 DVD가 존재하지 않습니다.");
		getchar();
		return;
	}
	
	// 대여 가능한 상태인지 확인
	rentstete = GetDVDRentState(ISBN);
	if (rentstete == RENTED)
	{
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return;
	}

	// 대여 절차 진행
	puts("대여가 가능합니다. 대여 과정을 진행합니다.");
	fputs("대여 고객 ID 입력:", stdout);
	gets(ID);

	registCus = IsRegistID(ID);
	if (registCus == 0)
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}

	fputs("대여 날짜 입력 : ", stdout);
	scanf("%u", &rentDay);
	getchar();

	AddRentList(ISBN, ID, rentDay);
	ptr->rentState = RENTED;
	
	puts("대여가 완료되었습니다.");
	
	getchar();
}

// 기	능 : ISBN를 통한  DVD 반납
// 반	환 : void
void ReturnDVD(void)
{
	char ISBN[ISBN_LEN];
	int registDVD;
	int rentStete;
	dvdInfo * ptr;

	fputs("반납 DVD ISBN 입력: ", stdout);
	gets(ISBN);
	registDVD = IsRegistISBN(ISBN);

	if (registDVD == 0)
	{
		puts("해당 DVD가 존재하지 않습니다.");
		getchar();
		return;
	}
	
	rentStete = GetDVDRentState(ISBN);

	if (rentStete == RENTED)
	{
		SetDVDReturned(ISBN);
		puts("반납이 완료되었습니다.");
	}
	else
		puts("대여되지 않은 DVD 입니다.");

	

	getchar();
}

// 기	능 : DVD 대여고객 전체 조회
// 반	환 : void
void RentedIDShowAll(void)
{
	char ISBN[ISBN_LEN];
	dvdInfo * dPtr;

	fputs("DVD ISBN 입력: ", stdout);
	gets(ISBN);
	dPtr = GetDVDPtrByISBN(ISBN);

	if (dPtr == NULL)
	{
		puts("해당 DVD가 존재하지 않습니다.");
		getchar();
		return;
	}

	PrintOutRentAllCusInfo(ISBN);
	puts("조회를 완료했습니다.\n");
	getchar();
}

// 기	능 : 고객 대여 DVD 전체 조회
// 반	환 : void
void RentedDVDShowAll(void)
{
	char ID[ID_LEN];
	int start, end;

	fputs("ID 입력: ", stdout);
	gets(ID);

	if (IsRegistID(ID) == 0)
	{
		puts("해당 아이디가 없습니다.");
		getchar();
		return;
	}
	fputs("대여 기간 입력: ", stdout);
	scanf("%d %d", &start, &end);
	getchar();


	PrintOutCusAllRentInfo(ID, start, end);

	puts("조회를 완료했습니다.\n");
	getchar();
}
/* end of file */