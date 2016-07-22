#ifndef JMINFOTYPE_H
#define JMINFOTYPE_H

//ZPW2000信息：
//载波索引
typedef enum
{
	ZPW_CFINDEX_NONE = 0,
	ZPW_CFINDEX_1700,
	ZPW_CFINDEX_2000,
	ZPW_CFINDEX_2300,
	ZPW_CFINDEX_2600
}EZPWCARRIERFREQINDEX;
//低频索引
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
//载波锁定：可组合
#define ZPW_CL_NONE	0
#define ZPW_CL_1700	1
#define ZPW_CL_2000	(1<<1)
#define ZPW_CL_2300	(1<<2)
#define ZPW_CL_2600	(1<<3)
typedef struct
{
	unsigned short SgnAmp;	//信号幅度，单位：0.1mv
	unsigned char CarrierFreqIndex;	//载波频率索引：0，1~4
	unsigned char ModulateFreqIndex;//调制频率索引：0,1~18
	unsigned short CarrierFreq;		//载波频率，单位：0.1HZ
	unsigned short ModulateFreq;	//调制频率，单位：0.01HZ
	unsigned short LedDelayTime;	//无码时间，单位：MS

	unsigned char  CarrieLock;		//载波锁定值
	unsigned char  LockDelayTime;	//锁定无码时间，单位：100MS
}TZpwExtInfoOutput;

//YP信息
//载波索引
typedef enum
{
	YP_CFINDEX_NONE = 0,
	YP_CFINDEX_550,
	YP_CFINDEX_650,
	YP_CFINDEX_750,
	YP_CFINDEX_850
}EYPCARRIERFREQINDEX;
//低频索引
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
	unsigned short SgnAmp;	//信号幅度，单位：0.1mv
	unsigned char CarrierFreqIndex;	//载波频率索引：0，1~4
	unsigned char ModulateFreqIndex;//调制频率索引：0,1~18
	unsigned short CarrierFreq;		//载波频率，单位：0.1HZ
	unsigned short ModulateFreq;	//调制频率，单位：0.01HZ
	unsigned short LedDelayTime;	//无码时间，单位：MS
	unsigned char Rev[2];			//为结构长度=4*n，保留
}TYpExtInfoOutput;

//JLJS技术信息
//频率索引
typedef enum
{
	JLJS_FREQINDEX_NONE = 0,
	JLJS_FREQINDEX_25,
	JLJS_FREQINDEX_50
}EJLJSFREQINDEX;
//信号索引
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
	unsigned short SgnAmp;	//信号幅度，单位：0.1mv
	unsigned char  FreqIndex;//频率索引
	unsigned char  SgnIndex;//信号索引：0,1~11
	unsigned short Freq;	//信号频率，单位：0.1HZ
	unsigned short LedDelayTime;	//无码时间，单位：MS
}TJljsExtInfoOutput;

//单轨条信息：
//载波锁断
#define DGT_CL_NONE	0
#define DGT_CL_550	1
#define DGT_CL_650	(1<<1)
#define DGT_CL_750	(1<<2)
#define DGT_CL_850	(1<<3)
#define DGT_CL_HU	(1<<4)	//锁定HU灯
typedef struct
{
	unsigned short YpSgnAmp;			//YP：信号幅度，单位：0.1mv
	unsigned char  YpCarrierFreqIndex;	//YP：载波频率索引：0，1~4
	unsigned char  YpModulateFreqIndex;//YP：调制频率索引：0,1~18
	unsigned short YpCarrierFreq;		//YP：载波频率，单位：0.1HZ
	unsigned short YpModulateFreq;	//YP：调制频率，单位：0.01HZ
	unsigned short YpLedDelayTime;	//YP：无码时间，单位：MS

	unsigned char  DgtCarrieLock;		//DGT：载波锁定值
	unsigned char  LockDelayTime;	//锁定无码时间，单位：100MS
}TDgtExtInfoOutput;

//极频信息
//周期索引
typedef enum
{
	JP_PRIODINDEX_NONE = 0,
	JP_PRIODINDEX_220_Z,	//220毫秒正极性
	JP_PRIODINDEX_220_F,	//220毫秒负极性
	JP_PRIODINDEX_440_Z,	//440毫秒正极性
	JP_PRIODINDEX_440_F		//440毫秒负极性	
}EJPPRIODINDEX;
//信号索引
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
	unsigned short SgnAmp;	//信号幅度，单位：0.1mv
	unsigned char  PriodIndex;//周期索引
	unsigned char  SgnIndex;//信号索引
	unsigned short PriodTime;//周期时间，单位：MS
	unsigned short LedDelayTime;	//无码时间，单位：MS
}TJpExtInfoOutput;

//TVM430信息
//载波索引
typedef enum
{
	TVM430_CFINDEX_NONE = 0,
	TVM430_CFINDEX_1700,
	TVM430_CFINDEX_2000,
	TVM430_CFINDEX_2300,
	TVM430_CFINDEX_2600
}ETVM430CARRIERFREQINDEX;
//信号索引：待定
//信号代码：待定
typedef struct
{
	unsigned short SgnAmp;	//信号幅度，单位：0.1mv
	unsigned char  CarrierFreqIndex;	//载波频率索引：0，1~4
	unsigned char  SgnIndex;	//信号索引：0，1~4
	unsigned short CarrierFreq;		//载波频率，单位：0.1HZ
	unsigned short LedDelayTime;	//无码时间，单位：MS
	unsigned int SgnCode;//信号代码
}TTvm430ExtInfoOutput;

//DSP BIOS信息：当CurSgnZs=SGN_ZS_BOOPROG时
typedef enum
{
	BOOT_PROG_STATUS_NONE = 0,	//等待加载应用程序
	BOOT_PROG_STATUS_WAIT,		//等待更新代码
	BOOT_PROG_STATUS_PARA,		//下载参数
	BOOT_PROG_STATUS_BOOT,		//下载BOOT代码
	BOOT_PROG_STATUS_APP,		//下载APP代码
	BOOT_PROG_STATUS_RESET,		//下载代码后，等待复位	
	BOOT_PROG_STATUS_ERR		//下载过程出错
}EBOOTPROGSTATUS;
typedef struct
{
	unsigned char BootProgStatus;
	unsigned char ParaStatus;	//1:表示NOR FLASH存在参数
	unsigned char BootStatus;	//1:表示NOR FLASH存在BOOT代码
	unsigned char AppStatus;	//1:表示NOR FLASH存在APP代码
}TBootExtInfoOutput;

//解码信息输出
//点灯输出：看partype
//当前制式
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
	SGN_ZS_BOOPROG	//boot代码
}ESGNZSINFO;
//上下行信息：看partype.h
//ZPW载波锁定：看ZPW信息
//传感器特征代码状态
#define CGQ_TZCODE_STATUS_OK	0
#define CGQ_TZCODE_STATUS_ERR	1
//各制式解码允许状态：组合
#define ZS_DECODE_ENABLE	1
#define ZS_DECODE_DISABLE	0
#define YP_RAILWAY_DH	0	//电化YP
#define YP_RAILWAY_FDH	1	//非电化YP
#define YP_PAROUTPUT_3060	0	//3060方式
#define YP_PAROUTPUT_19	1	//1.9方式
#define JLJS_PAROUTPUT_STD	0	//标准方式
#define JLJS_PAROUTPUT_HJ	1	//哈局方式
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
	unsigned char  CgqTzCodeStatus;//传感器特征代码状态
	unsigned short CgqTzCodeAmp;   //传感器特征代码幅度：0.1MV
	TZsDecodeEnStatus ZsDecodeEnStatus;//各制式解码允许情况   14Bytes
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
