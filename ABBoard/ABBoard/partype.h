#ifndef SGNOUTPUT_H
#define SGNOUTPUT_H

//解码允许枚举
typedef enum
{
	SGN_ZS_DISABLE = 0, //信号制式不允许解码
	SGN_ZS_ENABLE		//信号制式允许解码
}ESGNZSENABLE;

//硬件上下行枚举
typedef enum
{
	HWSXX_NONE = 0,	//没有硬件上下行条件
	HWSXX_SX,		//硬件上行
	HWSXX_XX		//硬件下行
}EHWSXX;

//并行输出
typedef enum
{
	SGN_LED_NONE = 0,
	SGN_LED_L,	//1
	SGN_LED_LU,	//2
	SGN_LED_U,	//3
	SGN_LED_U2,	//4
	SGN_LED_UU,	//5
	SGN_LED_HU,	//6
	SGN_LED_H,	//7
	SGN_LED_B,	//8
	SGN_LED_U2S = 0x14,//0x14
	SGN_LED_UUS,	//0x15
	SGN_LED_HUS		//0x16
}ESGNLED;

typedef enum
{
	SGN_SD_NONE	= 0,
	SGN_SD_1,	//1
	SGN_SD_2,	//2
	SGN_SD_1_2,	//3
	SGN_SD_3,	//4
	SGN_SD_1_3,	//5
	SGN_SD_2_3,	//6
	SGN_SD_1_2_3	//7
}ESGNSD;
#define SGN_SD_SHIFT	8

typedef enum
{
	SGN_JY_LEVEL_0 = 0,
	SGN_JY_LEVEL_1
}ESGNJY;
#define SGN_JY_SHIFT	16

typedef enum
{
	SGN_ZS_LEVEL_0 = 0,
	SGN_ZS_LEVEL_1
}ESGNZS;
#define SGN_ZS_SHIFT	24

#define LED_WMB_INFO	(SGN_LED_B | (SGN_SD_3<<SGN_SD_SHIFT))	//无码白灯	
#define LED_WMH_INFO	(SGN_LED_H | (SGN_SD_3<<SGN_SD_SHIFT))	//无码红灯

typedef union
{
	unsigned int Val;
	struct
	{
		unsigned int LedVal	:	8;
		unsigned int SdVal	:	8;
		unsigned int JyVal	:	8;
		unsigned int ZsVal	:	8;
	}InfoBits;
}TLedInfo;

#endif
