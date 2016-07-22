#ifndef JMINFOTYPE_H
#define JMINFOTYPE_H

//ZPW2000��Ϣ��
//�ز�����
typedef enum
{
	ZPW_CFINDEX_NONE = 0,
	ZPW_CFINDEX_1700,
	ZPW_CFINDEX_2000,
	ZPW_CFINDEX_2300,
	ZPW_CFINDEX_2600
}EZPWCARRIERFREQINDEX;
//��Ƶ����
typedef enum
{
	ZPW_MFINDEX_NONE = 0,
	ZPW_MFINDEX_10P3,
	ZPW_MFINDEX_11P4,
	ZPW_MFINDEX_12P5,
	ZPW_MFINDEX_13P6,
	ZPW_MFINDEX_14P7,
	ZPW_MFINDEX_15P8,
	ZPW_MFINDEX_16P9,
	ZPW_MFINDEX_18P0,
	ZPW_MFINDEX_19P1,
	ZPW_MFINDEX_20P2,
	ZPW_MFINDEX_21P3,
	ZPW_MFINDEX_22P4,
	ZPW_MFINDEX_23P5,
	ZPW_MFINDEX_24P6,
	ZPW_MFINDEX_25P7,
	ZPW_MFINDEX_26P8,
	ZPW_MFINDEX_27P9,
	ZPW_MFINDEX_29P0
}EZPWMODULATEFREQINDEX;
//�ز������������
#define ZPW_CL_NONE	0
#define ZPW_CL_1700	1
#define ZPW_CL_2000	(1<<1)
#define ZPW_CL_2300	(1<<2)
#define ZPW_CL_2600	(1<<3)
typedef struct
{
	unsigned short SgnAmp;	//�źŷ��ȣ���λ��0.1mv
	unsigned char CarrierFreqIndex;	//�ز�Ƶ��������0��1~4
	unsigned char ModulateFreqIndex;//����Ƶ��������0,1~18
	unsigned short CarrierFreq;		//�ز�Ƶ�ʣ���λ��0.1HZ
	unsigned short ModulateFreq;	//����Ƶ�ʣ���λ��0.01HZ
	unsigned short LedDelayTime;	//����ʱ�䣬��λ��MS

	unsigned char  CarrieLock;		//�ز�����ֵ
	unsigned char  LockDelayTime;	//��������ʱ�䣬��λ��100MS
}TZpwExtInfoOutput;

//YP��Ϣ
//�ز�����
typedef enum
{
	YP_CFINDEX_NONE = 0,
	YP_CFINDEX_550,
	YP_CFINDEX_650,
	YP_CFINDEX_750,
	YP_CFINDEX_850
}EYPCARRIERFREQINDEX;
//��Ƶ����
typedef enum
{
	YP_MFINDEX_NONE = 0,
	YP_MFINDEX_7P0,
	YP_MFINDEX_8P0,
	YP_MFINDEX_8P5,
	YP_MFINDEX_9P0,
	YP_MFINDEX_9P5,
	YP_MFINDEX_11P0,
	YP_MFINDEX_12P5,
	YP_MFINDEX_13P5,
	YP_MFINDEX_15P0,
	YP_MFINDEX_16P5,
	YP_MFINDEX_17P5,
	YP_MFINDEX_18P5,
	YP_MFINDEX_20P0,
	YP_MFINDEX_21P5,
	YP_MFINDEX_22P5,
	YP_MFINDEX_23P5,
	YP_MFINDEX_24P5,
	YP_MFINDEX_26P0
}EYPMODULATEFREQINDEX;
typedef struct
{
	unsigned short SgnAmp;	//�źŷ��ȣ���λ��0.1mv
	unsigned char CarrierFreqIndex;	//�ز�Ƶ��������0��1~4
	unsigned char ModulateFreqIndex;//����Ƶ��������0,1~18
	unsigned short CarrierFreq;		//�ز�Ƶ�ʣ���λ��0.1HZ
	unsigned short ModulateFreq;	//����Ƶ�ʣ���λ��0.01HZ
	unsigned short LedDelayTime;	//����ʱ�䣬��λ��MS
	unsigned char Rev[2];			//Ϊ�ṹ����=4*n������
}TYpExtInfoOutput;

//JLJS������Ϣ
//Ƶ������
typedef enum
{
	JLJS_FREQINDEX_NONE = 0,
	JLJS_FREQINDEX_25,
	JLJS_FREQINDEX_50
}EJLJSFREQINDEX;
//�ź�����
typedef enum
{
	JLJS_SGNINDEX_NONE = 0,
	JLJS_SGNINDEX_L16,
	JLJS_SGNINDEX_LU16,
	JLJS_SGNINDEX_U16,
	JLJS_SGNINDEX_UU16,
	JLJS_SGNINDEX_HU16,
	JLJS_SGNINDEX_L19,
	JLJS_SGNINDEX_LU19,
	JLJS_SGNINDEX_U19,
	JLJS_SGNINDEX_UU19,
	JLJS_SGNINDEX_HU19,
}EJLJSSGNINDEX;
typedef struct
{
	unsigned short SgnAmp;	//�źŷ��ȣ���λ��0.1mv
	unsigned char  FreqIndex;//Ƶ������
	unsigned char  SgnIndex;//�ź�������0,1~11
	unsigned short Freq;	//�ź�Ƶ�ʣ���λ��0.1HZ
	unsigned short LedDelayTime;	//����ʱ�䣬��λ��MS
}TJljsExtInfoOutput;

//��������Ϣ��
//�ز�����
#define DGT_CL_NONE	0
#define DGT_CL_550	1
#define DGT_CL_650	(1<<1)
#define DGT_CL_750	(1<<2)
#define DGT_CL_850	(1<<3)
#define DGT_CL_HU	(1<<4)	//����HU��
typedef struct
{
	unsigned short YpSgnAmp;			//YP���źŷ��ȣ���λ��0.1mv
	unsigned char  YpCarrierFreqIndex;	//YP���ز�Ƶ��������0��1~4
	unsigned char  YpModulateFreqIndex;//YP������Ƶ��������0,1~18
	unsigned short YpCarrierFreq;		//YP���ز�Ƶ�ʣ���λ��0.1HZ
	unsigned short YpModulateFreq;	//YP������Ƶ�ʣ���λ��0.01HZ
	unsigned short YpLedDelayTime;	//YP������ʱ�䣬��λ��MS

	unsigned char  DgtCarrieLock;		//DGT���ز�����ֵ
	unsigned char  LockDelayTime;	//��������ʱ�䣬��λ��100MS
}TDgtExtInfoOutput;

//��Ƶ��Ϣ
//��������
typedef enum
{
	JP_PRIODINDEX_NONE = 0,
	JP_PRIODINDEX_220_Z,	//220����������
	JP_PRIODINDEX_220_F,	//220���븺����
	JP_PRIODINDEX_440_Z,	//440����������
	JP_PRIODINDEX_440_F		//440���븺����	
}EJPPRIODINDEX;
//�ź�����
typedef enum
{
	JP_SGNINDEX_NONE = 0,
	JP_SGNINDEX_L,
	JP_SGNINDEX_U,
	JP_SGNINDEX_UU,	
	JP_SGNINDEX_HU	
}EJPSGNINDEX;
typedef struct
{
	unsigned short SgnAmp;	//�źŷ��ȣ���λ��0.1mv
	unsigned char  PriodIndex;//��������
	unsigned char  SgnIndex;//�ź�����
	unsigned short PriodTime;//����ʱ�䣬��λ��MS
	unsigned short LedDelayTime;	//����ʱ�䣬��λ��MS
}TJpExtInfoOutput;

//TVM430��Ϣ
//�ز�����
typedef enum
{
	TVM430_CFINDEX_NONE = 0,
	TVM430_CFINDEX_1700,
	TVM430_CFINDEX_2000,
	TVM430_CFINDEX_2300,
	TVM430_CFINDEX_2600
}ETVM430CARRIERFREQINDEX;
//�ź�����������
//�źŴ��룺����
typedef struct
{
	unsigned short SgnAmp;	//�źŷ��ȣ���λ��0.1mv
	unsigned char  CarrierFreqIndex;	//�ز�Ƶ��������0��1~4
	unsigned char  SgnIndex;	//�ź�������0��1~4
	unsigned short CarrierFreq;		//�ز�Ƶ�ʣ���λ��0.1HZ
	unsigned short LedDelayTime;	//����ʱ�䣬��λ��MS
	unsigned int SgnCode;//�źŴ���
}TTvm430ExtInfoOutput;

//DSP BIOS��Ϣ����CurSgnZs=SGN_ZS_BOOPROGʱ
typedef enum
{
	BOOT_PROG_STATUS_NONE = 0,	//�ȴ�����Ӧ�ó���
	BOOT_PROG_STATUS_WAIT,		//�ȴ����´���
	BOOT_PROG_STATUS_PARA,		//���ز���
	BOOT_PROG_STATUS_BOOT,		//����BOOT����
	BOOT_PROG_STATUS_APP,		//����APP����
	BOOT_PROG_STATUS_RESET,		//���ش���󣬵ȴ���λ	
	BOOT_PROG_STATUS_ERR		//���ع��̳���
}EBOOTPROGSTATUS;
typedef struct
{
	unsigned char BootProgStatus;
	unsigned char ParaStatus;	//1:��ʾNOR FLASH���ڲ���
	unsigned char BootStatus;	//1:��ʾNOR FLASH����BOOT����
	unsigned char AppStatus;	//1:��ʾNOR FLASH����APP����
}TBootExtInfoOutput;

//������Ϣ���
//����������partype
//��ǰ��ʽ
typedef enum
{
	SGN_ZS_NONE = 0,
	SGN_ZS_ZPW2000,
	SGN_ZS_YP,
	SGN_ZS_JLJS_25,
	SGN_ZS_JLJS_50,
	SGN_ZS_DGT,
	SGN_ZS_JP,
	SGN_ZS_TVM430,
	SGN_ZS_BOOPROG	//boot����
}ESGNZSINFO;
//��������Ϣ����partype.h
//ZPW�ز���������ZPW��Ϣ
//��������������״̬
#define CGQ_TZCODE_STATUS_OK	0
#define CGQ_TZCODE_STATUS_ERR	1
//����ʽ��������״̬�����
#define ZS_DECODE_ENABLE	1
#define ZS_DECODE_DISABLE	0
#define YP_RAILWAY_DH	0	//�绯YP
#define YP_RAILWAY_FDH	1	//�ǵ绯YP
#define YP_PAROUTPUT_3060	0	//3060��ʽ
#define YP_PAROUTPUT_19	1	//1.9��ʽ
#define JLJS_PAROUTPUT_STD	0	//��׼��ʽ
#define JLJS_PAROUTPUT_HJ	1	//���ַ�ʽ
typedef union
{
	unsigned short Val;
	struct
	{
		unsigned short ZpwDecode :1;
		unsigned short YpDecode:1;
		unsigned short YpRailway:1;
		unsigned short YpParOutput:1;
		unsigned short Jljs25Decode:1;
		unsigned short Jljs50Decode:1;
		unsigned short JljsParOutput:1;
		unsigned short DgtDecode:1;
		unsigned short JpDecode:1;
		unsigned short Tvm430Decode:1;
		unsigned short Rev:6;
	}StatusBits;
}TZsDecodeEnStatus;

typedef struct
{
	TLedInfo LedInfo;
	unsigned char  CurSgnZs;
	unsigned char  HwSxx;
	unsigned char  ZpwCarrierLock;
	unsigned char  CgqTzCodeStatus;//��������������״̬
	unsigned short CgqTzCodeAmp;   //����������������ȣ�0.1MV
	TZsDecodeEnStatus ZsDecodeEnStatus;//����ʽ�����������   14Bytes
	union
	{
		TZpwExtInfoOutput		ZpwExtInfoOutput;
		TYpExtInfoOutput		YpExtInfoOutput;
		TJljsExtInfoOutput		Jljs25ExtInfoOutput;
		TJljsExtInfoOutput		Jljs50ExtInfoOutput;
		TDgtExtInfoOutput		DgtExtInfoOutput;
		TJpExtInfoOutput		JpExtInfoOutput;
		TTvm430ExtInfoOutput	Tvm430ExtInfoOutput;
		TBootExtInfoOutput		BootExtInfoOutput;
	}ZsExtInfoOutput;
}TJmInfoOutput;

#endif
