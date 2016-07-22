#ifndef KZINFOTYPE_H
#define KZINFOTYPE_H

//主机输出工作信息
//主机检测状态
#define KZ_STATUS_OK	0
#define KZ_STATUS_ERR	1
typedef union
{
	unsigned int Val;
	struct
	{
		unsigned int MainUseStatus:1;	//允许到主用：可作为主控输出
		unsigned int DataUseStatus:1;	//数据使用状态：1表示当前采用另一主机数据
		unsigned int Jm2x2Status:1;		//2取2状态：1表示2取2错误
		unsigned int Kz2x2Status :1;	//2乘2状态：1表示另一主机不可用
		unsigned int Jm1Status :1;		//解码通道1状态：0表示OK
		unsigned int Jm2Status :1;		//解码通道2状态：0表示OK
		unsigned int CanStatus :1;		//CAN总线状态：0表示OK
		unsigned int CgqStatus:1;		//CGQ状态：0表示OK
		unsigned int ParLedChkStatus:1;	//并行检测状态：0表示OK
		unsigned int ParLedBckStatus:1;	//八灯回检状态：0表示OK
		unsigned int ParSdJyZsBckStatus:1;	//其他并行输出回检状态：0表示OK
		unsigned int HwSxxStatus:1;		//上下行输入状态：0表示OK
		unsigned int SxxBsBckStatus:1;	//上下行表示输出回检状态：0表示OK
		unsigned int CgaStatus:1;		//强制工作状态：1表示强制工作
		unsigned int JeStatus:1;		//八灯错误状态：1表示八灯有错误信息输出
		unsigned int Vd50Status:1;		//动态电源状态：1表示没有检测到动态电源
		unsigned int ABWKStatus:1;		//AB机工作状态：1表示均不再主控状态
		
		unsigned int rev:7;
		unsigned int RLStatus:8;		//八个继电器状态：对应位为1表示相应继电器曾经出现控制错误
	}StatusBits;
}TKzStatus;
//主机解码通道
#define JM1_CHANNEL_USED	0
#define JM2_CHANNEL_USED	1
typedef struct
{
	TLedInfo LedInfo;
	TKzStatus KzStatus;
	unsigned char MainUseFlag;	//主用标志：1表示主控制
	unsigned char HwSxx;		//上下行：定义看partype.h
	unsigned char ZpwCarrierLock;//zpw2000载波锁定：定义看jminfotype.h
	unsigned char UseJmChannel;	//当前采用解码通道数据
	unsigned char ExtPort[8];	//外部控制口当前数据
	TJmInfoOutput Jm1InfoOutPut;	//JM1数据：定义看jminfotype.h
	TJmInfoOutput Jm2InfoOutPut;	//JM2数据：定义看jminfotype.h	
}TKzInfoOutput;

//控制软件传输到解码软件工作信息
typedef struct
{
	unsigned char MainUseFlag;		//主用标志
	unsigned char HwSxx;			//硬件上下行
	unsigned char SetValidFlag;		//外部设置可用标志
	unsigned char ValidExtPort6;	//可用的外部口6
	unsigned char ValidExtPort7;	//可用的外部口7
	unsigned char ExtPort[8];		//单前外部口值
}TKzToJmWorkInfo;

#endif
