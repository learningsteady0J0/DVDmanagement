// Name : RentInfoAccess.h
// Content : rent DVD ���� ���� �� ���� �Լ����� ����
// Implementation : learningsteady0j0
// Last modified 2019/02/06

#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__


void AddRentList(char * ISBN, char * cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBN);
void PrintOutCusAllRentInfo(char*ID, unsigned int start, unsigned int end);

#endif

/* end of file */