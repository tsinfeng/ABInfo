// ABDataStruct.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ABDataStruct.h"


// ���ǵ���������һ��ʾ��
ABDATASTRUCT_API int nABDataStruct=0;

// ���ǵ���������һ��ʾ����
ABDATASTRUCT_API int fnABDataStruct(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ABDataStruct.h
CABDataStruct::CABDataStruct()
{
	return;
}
