#ifndef KZINFOTYPE_H
#define KZINFOTYPE_H

//�������������Ϣ
//�������״̬
#define KZ_STATUS_OK	0
#define KZ_STATUS_ERR	1
typedef union
{
	unsigned int Val;
	struct
	{
		unsigned int MainUseStatus:1;	//�������ã�����Ϊ�������
		unsigned int DataUseStatus:1;	//����ʹ��״̬��1��ʾ��ǰ������һ��������
		unsigned int Jm2x2Status:1;		//2ȡ2״̬��1��ʾ2ȡ2����
		unsigned int Kz2x2Status :1;	//2��2״̬��1��ʾ��һ����������
		unsigned int Jm1Status :1;		//����ͨ��1״̬��0��ʾOK
		unsigned int Jm2Status :1;		//����ͨ��2״̬��0��ʾOK
		unsigned int CanStatus :1;		//CAN����״̬��0��ʾOK
		unsigned int CgqStatus:1;		//CGQ״̬��0��ʾOK
		unsigned int ParLedChkStatus:1;	//���м��״̬��0��ʾOK
		unsigned int ParLedBckStatus:1;	//�˵ƻؼ�״̬��0��ʾOK
		unsigned int ParSdJyZsBckStatus:1;	//������������ؼ�״̬��0��ʾOK
		unsigned int HwSxxStatus:1;		//����������״̬��0��ʾOK
		unsigned int SxxBsBckStatus:1;	//�����б�ʾ����ؼ�״̬��0��ʾOK
		unsigned int CgaStatus:1;		//ǿ�ƹ���״̬��1��ʾǿ�ƹ���
		unsigned int JeStatus:1;		//�˵ƴ���״̬��1��ʾ�˵��д�����Ϣ���
		unsigned int Vd50Status:1;		//��̬��Դ״̬��1��ʾû�м�⵽��̬��Դ
		unsigned int ABWKStatus:1;		//AB������״̬��1��ʾ����������״̬
		
		unsigned int rev:7;
		unsigned int RLStatus:8;		//�˸��̵���״̬����ӦλΪ1��ʾ��Ӧ�̵����������ֿ��ƴ���
	}StatusBits;
}TKzStatus;
//��������ͨ��
#define JM1_CHANNEL_USED	0
#define JM2_CHANNEL_USED	1
typedef struct
{
	TLedInfo LedInfo;
	TKzStatus KzStatus;
	unsigned char MainUseFlag;	//���ñ�־��1��ʾ������
	unsigned char HwSxx;		//�����У����忴partype.h
	unsigned char ZpwCarrierLock;//zpw2000�ز����������忴jminfotype.h
	unsigned char UseJmChannel;	//��ǰ���ý���ͨ������
	unsigned char ExtPort[8];	//�ⲿ���ƿڵ�ǰ����
	TJmInfoOutput Jm1InfoOutPut;	//JM1���ݣ����忴jminfotype.h
	TJmInfoOutput Jm2InfoOutPut;	//JM2���ݣ����忴jminfotype.h	
}TKzInfoOutput;

//����������䵽�������������Ϣ
typedef struct
{
	unsigned char MainUseFlag;		//���ñ�־
	unsigned char HwSxx;			//Ӳ��������
	unsigned char SetValidFlag;		//�ⲿ���ÿ��ñ�־
	unsigned char ValidExtPort6;	//���õ��ⲿ��6
	unsigned char ValidExtPort7;	//���õ��ⲿ��7
	unsigned char ExtPort[8];		//��ǰ�ⲿ��ֵ
}TKzToJmWorkInfo;

#endif
