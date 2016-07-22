// ABInterface.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ABInterface.h"
//add head file
#include <memory.h>

// 这是导出变量的一个示例
ABINTERFACE_API int nABInterface=0;

// 这是导出函数的一个示例。
ABINTERFACE_API int fnABInterface(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 ABInterface.h
CABInterface::CABInterface()
{
	return;
}

int mySum(int a, int b) {
    return a + b;
}

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

//Jm1 ZPW2000信息
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
//Jm2 ZPW2000信息
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