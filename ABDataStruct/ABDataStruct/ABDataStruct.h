// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ABDATASTRUCT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ABDATASTRUCT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ABDATASTRUCT_EXPORTS
#define ABDATASTRUCT_API __declspec(dllexport)
#else
#define ABDATASTRUCT_API __declspec(dllimport)
#endif

// �����Ǵ� ABDataStruct.dll ������
class ABDATASTRUCT_API CABDataStruct {
public:
	CABDataStruct(void);
	// TODO: �ڴ�������ķ�����
};

extern ABDATASTRUCT_API int nABDataStruct;

ABDATASTRUCT_API int fnABDataStruct(void);
