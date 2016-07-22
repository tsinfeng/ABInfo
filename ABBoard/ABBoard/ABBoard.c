// ABBoard.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "partype.h"
#include "jminfotype.h"
#include "kzinfotype.h"
#include <memory.h>

typedef	union
	{
		TZpwExtInfoOutput		ZpwExtInfoOutput;
		TYpExtInfoOutput		YpExtInfoOutput;
		TJljsExtInfoOutput		Jljs25ExtInfoOutput;
		TJljsExtInfoOutput		Jljs50ExtInfoOutput;
		TDgtExtInfoOutput		DgtExtInfoOutput;
		TJpExtInfoOutput		JpExtInfoOutput;
		TTvm430ExtInfoOutput	Tvm430ExtInfoOutput;
		TBootExtInfoOutput		BootExtInfoOutput;
	}ZsExtInfoOutput1;

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
		unsigned short Rev[6];
	}StatusBits;
}TZsDecodeEnStatus1;


//LED灯信息
int GetTLedInfo(TKzInfoOutput *pTkzInfo, int *led_val, int* sd_val, int* jy_val, int* zs_val)
{
   if (pTkzInfo == NULL)
	   return 0;
   
   *led_val = pTkzInfo->LedInfo.InfoBits.LedVal;
   *sd_val = pTkzInfo->LedInfo.InfoBits.SdVal;
   *jy_val = pTkzInfo->LedInfo.InfoBits.JyVal;
   *zs_val = pTkzInfo->LedInfo.InfoBits.ZsVal;
   
   return 1;
}
//主要输出工作信息，主机检测状态
int GetTKzStatusBits(TKzInfoOutput *pTkzInfo, int *main_use_status, int *data_use_status, int *jm2x2s_status, int* kz2x2s_status,
					                          int *jm1_status, int *jm2_status, int *can_status, int *cgq_status,
											  int *parled_checkLstatus, int *parled_bakstatus, int *parsd_jyzs_bakstatus, int *hwsxx_status,
											  int *sxxbs_backstatus,int *cga_status, int *je_status, int *vd50_status, 
											  int *abwk_status,int *rev, int *rl_status)
{
   if (pTkzInfo == NULL)
	   return 0;

   *main_use_status = pTkzInfo->KzStatus.StatusBits.MainUseStatus;
   *data_use_status = pTkzInfo->KzStatus.StatusBits.DataUseStatus;
   *jm2x2s_status = pTkzInfo->KzStatus.StatusBits.Jm2x2Status;
   *kz2x2s_status = pTkzInfo->KzStatus.StatusBits.Kz2x2Status;
   *jm1_status = pTkzInfo->KzStatus.StatusBits.Jm1Status;
   *jm2_status = pTkzInfo->KzStatus.StatusBits.Jm2Status;
   *can_status = pTkzInfo->KzStatus.StatusBits.CanStatus;
   *cgq_status = pTkzInfo->KzStatus.StatusBits.CgqStatus;
   *parled_checkLstatus = pTkzInfo->KzStatus.StatusBits.ParLedChkStatus;
   *parled_bakstatus = pTkzInfo->KzStatus.StatusBits.ParLedBckStatus;
   *parsd_jyzs_bakstatus = pTkzInfo->KzStatus.StatusBits.ParSdJyZsBckStatus;
   *hwsxx_status = pTkzInfo->KzStatus.StatusBits.HwSxxStatus;
   *sxxbs_backstatus = pTkzInfo->KzStatus.StatusBits.SxxBsBckStatus;
   *cga_status = pTkzInfo->KzStatus.StatusBits.CgaStatus;
   *je_status = pTkzInfo->KzStatus.StatusBits.JeStatus;
   *vd50_status = pTkzInfo->KzStatus.StatusBits.Vd50Status;
   *abwk_status = pTkzInfo->KzStatus.StatusBits.ABWKStatus;
   *rev = pTkzInfo->KzStatus.StatusBits.rev;
   *rl_status = pTkzInfo->KzStatus.StatusBits.RLStatus;


   return 1;

}
//主用标志
//上下行
//载波锁定
//解码通道
int GetUseStateInfo(TKzInfoOutput *pTkzInfo, char *main_use_flag, char *hw_sxx, char *zpw_carrier_lock, char *use_jm_channel)
{
   if (pTkzInfo == NULL)
	   return 0;

   *main_use_flag = pTkzInfo->MainUseFlag;
   *hw_sxx = pTkzInfo->HwSxx;
   *zpw_carrier_lock = pTkzInfo->ZpwCarrierLock;
   *use_jm_channel = pTkzInfo->UseJmChannel;

   return 1;
}

//外部控制口当前数据
int GetExtPortInfo(TKzInfoOutput *pTkzInfo, char (*ext_port)[])
{
   if (pTkzInfo == NULL)
	   return 0;

   memcpy(ext_port, pTkzInfo->ExtPort, sizeof(pTkzInfo->ExtPort));
   //ext_port = pTkzInfo->ExtPort[8];
   return 1;
}

//通道1
//LED    上下行
//载波锁定 传感器特征代码状态
//传感器特征代码幅度 各种制式允许解码情况
int GetTjmPartInfoJm1(TKzInfoOutput *pTkzInfo, int *led_val, int *sd_val, int *jy_val, int *zs_val,
				                            char *curr_sgn_zx, char *hw_sxx, char *zpw_carrier_lock, char *cgq_tz_code_status,
											short *cgq_tz_code_amp, short *zs_decode_en_status)
{
   if (pTkzInfo == NULL)
	   return 0;

   *led_val = pTkzInfo->Jm1InfoOutPut.LedInfo.InfoBits.LedVal;
   *sd_val = pTkzInfo->Jm1InfoOutPut.LedInfo.InfoBits.SdVal;
   *jy_val = pTkzInfo->Jm1InfoOutPut.LedInfo.InfoBits.ZsVal;
   *zs_val = pTkzInfo->Jm1InfoOutPut.LedInfo.InfoBits.ZsVal;
   *curr_sgn_zx = pTkzInfo->Jm1InfoOutPut.CurSgnZs;
   *hw_sxx = pTkzInfo->Jm1InfoOutPut.HwSxx;
   *zpw_carrier_lock = pTkzInfo->Jm1InfoOutPut.ZpwCarrierLock;
   *cgq_tz_code_status = pTkzInfo->Jm1InfoOutPut.CgqTzCodeStatus;
   *cgq_tz_code_amp = pTkzInfo->Jm1InfoOutPut.CgqTzCodeAmp;
   *zs_decode_en_status = pTkzInfo->Jm1InfoOutPut.ZsDecodeEnStatus.Val;

   return 1;
}
//Jm2
//LED    上下行
//载波锁定 传感器特征代码状态
//传感器特征代码幅度 各种制式允许解码情况
int GetTjmPartInfoJm2(TKzInfoOutput *pTkzInfo, int *led_val, int *sd_val, int *jy_val, int *zs_val,
				                            char *curr_sgn_zx, char *hw_sxx, char *zpw_carrier_lock, char *cgq_tz_code_status,
											short *cgq_tz_code_amp, short *zs_decode_en_status)
{
   if (pTkzInfo == NULL)
	   return 0;

   *led_val = pTkzInfo->Jm2InfoOutPut.LedInfo.InfoBits.LedVal;
   *sd_val = pTkzInfo->Jm2InfoOutPut.LedInfo.InfoBits.SdVal;
   *jy_val = pTkzInfo->Jm2InfoOutPut.LedInfo.InfoBits.ZsVal;
   *zs_val = pTkzInfo->Jm2InfoOutPut.LedInfo.InfoBits.ZsVal;
   *curr_sgn_zx = pTkzInfo->Jm2InfoOutPut.CurSgnZs;
   *hw_sxx = pTkzInfo->Jm2InfoOutPut.HwSxx;
   *zpw_carrier_lock = pTkzInfo->Jm2InfoOutPut.ZpwCarrierLock;
   *cgq_tz_code_status = pTkzInfo->Jm2InfoOutPut.CgqTzCodeStatus;
   *cgq_tz_code_amp = pTkzInfo->Jm2InfoOutPut.CgqTzCodeAmp;
   *zs_decode_en_status = pTkzInfo->Jm2InfoOutPut.ZsDecodeEnStatus.Val;

   return 1;
}

int GetTZpwExtInfoJm1(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					                          short *carrier_freq, short *modulate_freq, short *led_delay_time,
											  char *carrier_lock, char *lock_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.SgnAmp;
   *carrier_freq_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrierFreqIndex;
   *modulate_fre_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.ModulateFreqIndex;
   *carrier_freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrierFreq;
   *modulate_freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.ModulateFreq;
   *led_delay_time = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.LedDelayTime;
   *carrier_lock = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrieLock;
   *lock_delay_time = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.LockDelayTime;
   return 1; 
}
int GetTZpwExtInfoJm2(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					                          short *carrier_freq, short *modulate_freq, short *led_delay_time,
											  char *carrier_lock, char *lock_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.SgnAmp;
   *carrier_freq_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrierFreqIndex;
   *modulate_fre_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.ModulateFreqIndex;
   *carrier_freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrierFreq;
   *modulate_freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.ModulateFreq;
   *led_delay_time = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.LedDelayTime;
   *carrier_lock = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.CarrieLock;
   *lock_delay_time = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.ZpwExtInfoOutput.LockDelayTime;
   return 1; 
}

int GetTYpExtInfoJm1(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					                          short *carrier_freq, short *modulate_freq, short *led_delay_time,
											  char (*rev)[])
{
   if (pTkzInfo == NULL)
	   return 0;
   
   *sgn_amp = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.SgnAmp;
   *carrier_freq_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.CarrierFreqIndex;
   *modulate_fre_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.ModulateFreqIndex;
   *carrier_freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.CarrierFreq;
   *modulate_freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.ModulateFreq;
   *led_delay_time = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.LedDelayTime;

   memcpy(rev, pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.Rev, sizeof(pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.Rev));

   return 1;
}
int GetTYpExtInfoJm2(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					                          short *carrier_freq, short *modulate_freq, short *led_delay_time,
											  char (*rev)[])
{
   if (pTkzInfo == NULL)
	   return 0;
   
   *sgn_amp = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.SgnAmp;
   *carrier_freq_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.CarrierFreqIndex;
   *modulate_fre_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.ModulateFreqIndex;
   *carrier_freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.CarrierFreq;
   *modulate_freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.ModulateFreq;
   *led_delay_time = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.LedDelayTime;

   memcpy(rev, pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.Rev, sizeof(pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.YpExtInfoOutput.Rev));

   return 1;
}

int GetTJljxExtInfo25Jm1(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					                           short *freq, short *led_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.SgnAmp;
   *fre_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.FreqIndex;
   *sgn_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.SgnIndex;
   *freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.Freq;
   *led_delay_time = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.LedDelayTime;

   return 1;
}
int GetTJljxExtInfo25Jm2(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					                           short *freq, short *led_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.SgnAmp;
   *fre_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.FreqIndex;
   *sgn_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.SgnIndex;
   *freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.Freq;
   *led_delay_time = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs25ExtInfoOutput.LedDelayTime;

   return 1;
}
int GetTJljxExtInfo50Jm1(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					                           short *freq, short *led_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.SgnAmp;
   *fre_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.FreqIndex;
   *sgn_index = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.SgnIndex;
   *freq = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.Freq;
   *led_delay_time = pTkzInfo->Jm1InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.LedDelayTime;

   return 1;
}
int GetTJljxExtInfo50Jm2(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					                           short *freq, short *led_delay_time)
{
   if (pTkzInfo == NULL)
	   return 0;

   *sgn_amp = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.SgnAmp;
   *fre_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.FreqIndex;
   *sgn_index = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.SgnIndex;
   *freq = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.Freq;
   *led_delay_time = pTkzInfo->Jm2InfoOutPut.ZsExtInfoOutput.Jljs50ExtInfoOutput.LedDelayTime;

   return 1;
}
int GetTDgtExtInfo()
{
   //if (pTkzInfo == NULL)
	   return 0;

   return 1;
}
int GetJpExtInfo()
{
   //if (pTkzInfo == NULL)
	   return 0;

   return 1;
}
int GetTvm430ExtInfo()
{
   //if (pTkzInfo == NULL)
	   return 0;

   return 1;
}
int GetTBootExtInfo()
{
   //if (pTkzInfo == NULL)
	   return 0;

   return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TKzInfoOutput TkzInfo;
	int i,j,k,l,m;
	FILE *outfile, *infile;
	int size;


    int ledVal,sdVal,jyVal,zsVal;
	int mainUseStatus, dataUseStatus, jm2x2sStatus, kz2x2sStatus,
		jm1Status, jm2Status, canStatus, cgqStatus,
		parledCheckLstatus, parledBakstatus, parsdJyzs_bakstatus, hwsxxStatus,
		sxxbsBackstatus,cgaStatus, jeStatus, vd50Status, 
		abwkStatus, rev, rlStatus;
	char mainUseFlag, hwSxx, zpwCarrierLock, useJmChannel;
	char extPort[8];

	int jm1LedVal, jm1SdVal, jm1JyVal, jm1ZsVal;
		char CurrSgnZx, HwSxx, ZpwCarrierLock, CgqTzCodeStatus;
		short CgqTzCodeAmp, ZsDecodeEnStatus;

	short zpwSgnAmp;
	   char zpwCarrierFreqIndex, zpwModulateFreIndex;
	   short zpwCarrierFreq, zpwModulateFreq, zpwLedDelayTime;
	   char zpwZxCarrierLock, zpwLockDelayTime;

    short ypSgnAmp;
	char ypCarrierFreqIndex, ypModulateFreIndex; 
	   short ypCarrierFreq, ypModulateFreq,ypLedDelayTime;
	   char ypRev[2];

   short jljs25SgnAmp;
   char jljs25FreIndex;
   char jljs25SgnIndex;
   short jljs25Freq;
   short jljs25LedDelayTime;

   short jljs50SgnAmp;
   char jljs50FreIndex;
   char jljs50SgnIndex;
   short jljs50Freq;
   short jljs50LedDelayTime;

    
	memset(&TkzInfo, 0x0, sizeof(TKzInfoOutput));
	size = sizeof(TkzInfo);
	printf("Struct size is %d\n", size);
	i = sizeof(TLedInfo);
	printf("TLedInfo size:%d\n", i);
	j = sizeof(TKzStatus);
	printf("TkzStatus size:%d\n", j);
	k = sizeof(TJmInfoOutput);
	printf("TJmInfoOutput size:%d\n", k);
	l = sizeof(TZsDecodeEnStatus1);
	printf("TZsDecodeEnStatus1 size:%d\n", l);
	m = sizeof(ZsExtInfoOutput1);
	printf("ZsExtInfoOutput1 size:%d\n", m);


	/*
	outfile = fopen("d:\\test1.data", "wb+");
	if (NULL == outfile)
		return -1;
    
	
	TkzInfo.LedInfo.InfoBits.JyVal = 1;
	TkzInfo.LedInfo.InfoBits.ZsVal = 1;
	printf("start to write...\n");

	
    if (fwrite(&TkzInfo, sizeof(TkzInfo),1,outfile)<=0)
		printf("write data error!\n");
    fclose(outfile);
	*/
	printf("start to read...\n");

	infile = fopen("d:\\byte1.data", "rb+");
	if (NULL == infile)
		return -1;
    if (fread(&TkzInfo, sizeof(TkzInfo),1,infile)<=0)
		printf("read data error!\n");
	fclose(infile);


	/*
	**
	*/
	/*
	ledVal = TkzInfo.LedInfo.InfoBits.LedVal;
	sdVal = TkzInfo.LedInfo.InfoBits.SdVal;
	jyVal = TkzInfo.LedInfo.InfoBits.JyVal;
	zsVal = TkzInfo.LedInfo.InfoBits.ZsVal;
	*/
    
    GetTLedInfo(&TkzInfo, &ledVal,&sdVal,&jyVal, &zsVal);
	GetTKzStatusBits(&TkzInfo, &mainUseStatus, &dataUseStatus, &jm2x2sStatus, &kz2x2sStatus,
		&jm1Status, &jm2Status, &canStatus, &cgqStatus,
		&parledCheckLstatus, &parledBakstatus, &parsdJyzs_bakstatus, &hwsxxStatus,
		&sxxbsBackstatus,&cgaStatus, &jeStatus, &vd50Status, 
		&abwkStatus, &rev, &rlStatus);
	GetUseStateInfo(&TkzInfo, &mainUseFlag, &hwSxx, &zpwCarrierLock, &useJmChannel);
    GetExtPortInfo(&TkzInfo,&extPort);
	GetTjmPartInfoJm2(&TkzInfo, &jm1LedVal, &jm1SdVal, &jm1JyVal, &jm1ZsVal,
		&CurrSgnZx, &HwSxx, &ZpwCarrierLock, &CgqTzCodeStatus,
		&CgqTzCodeAmp, &ZsDecodeEnStatus);


	GetTZpwExtInfoJm2(&TkzInfo, &zpwSgnAmp, &zpwCarrierFreqIndex, &zpwModulateFreIndex, 
	   &zpwCarrierFreq, &zpwModulateFreq, &zpwLedDelayTime,
	   &zpwZxCarrierLock, &zpwLockDelayTime);
	GetTYpExtInfoJm2(&TkzInfo, &ypSgnAmp, &ypCarrierFreqIndex, &ypModulateFreIndex, 
	   &ypCarrierFreq, &ypModulateFreq, &ypLedDelayTime, &ypRev);
	 
	GetTJljxExtInfo25Jm2(&TkzInfo, &jljs25SgnAmp,&jljs25FreIndex,
                                &jljs25SgnIndex, &jljs25Freq, &jljs25LedDelayTime);

	GetTJljxExtInfo50Jm2(&TkzInfo, &jljs50SgnAmp,&jljs50FreIndex,
                                &jljs50SgnIndex, &jljs50Freq, &jljs50LedDelayTime);
    
	/*
	outfile = fopen("d:\\test1.data", "wb+");
	if (NULL == outfile)
		return -1;
	printf("start to write...\n");
    if (fwrite(&TkzInfo, sizeof(TkzInfo),1,outfile)<=0)
		printf("write data error!\n");
    fclose(outfile);
	*/



	getchar();
	return 0;
}

