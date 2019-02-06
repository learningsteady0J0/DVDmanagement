// Name : screenOut.c
// Content : 콘솔 출력을 우한 함수들의 정의
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

#define GENRE_SIZE	10

/* 프로그램 사용을 위한 메뉴 */
void ShowMenu(void)
{
	system("cls");  //stdlib.h

	printf("━━━━━━━━━━━ 메 뉴 ━━━━━━━━━━━━━━━ \n");
	printf(" 1. 신규가입 \n");
	printf(" 2. 고객검색 \n");
	printf("───────────────────────────────── \n");
	printf(" 3. 신규DVD등록 \n");
	printf(" 4. DVD검색 \n");
	printf("───────────────────────────────── \n");
	printf(" 5. 종료 \n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
	printf("선택>> ");
}

/* 고객 개인의 기본 정보 출력 */
void ShowCustomerInfo(cusInfo * pCus)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
	printf("┃ ● ID : %s \n", pCus->ID);
	printf("┃ ● 이름 : %s \n", pCus->name);
	printf("┃ ● 전화번호 : %s \n", pCus->phoneNum);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n\n");
}

/* DVD의 기본 정보 출력 */
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

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
	printf("┃ ● ISBN : %s \n", pDVD->ISBN);
	printf("┃ ● Title : %s \n", pDVD->title);
	printf("┃ ● GENRE : %s \n", genre);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n\n");
}

/* end of file */