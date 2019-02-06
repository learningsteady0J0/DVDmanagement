// Name : dvdManager.c
// Content : DVD 관련 업무 처리 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

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

/* end of file */