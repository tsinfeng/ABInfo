#include "partype.h"
#include "jminfotype.h"
#include "kzinfotype.h"

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ABINTERFACE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ABINTERFACE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ABINTERFACE_EXPORTS
#define ABINTERFACE_API __declspec(dllexport)
#else
#define ABINTERFACE_API __declspec(dllimport)
#endif

// �����Ǵ� ABInterface.dll ������
class ABINTERFACE_API CABInterface {
public:
	CABInterface(void);
	// TODO: �ڴ�������ķ�����
};

extern ABINTERFACE_API int nABInterface;

ABINTERFACE_API int fnABInterface(void);

#ifdef __cplusplus
extern "C" {
#endif

// In DLL project, Visual Studio will define macro ${PROJECT_NAME}_EXPORTS
// we can use this marco to EXPORT variables/functions in DLL project,
// and to IMPORT variables/functions in other projects which using this dll.

ABINTERFACE_API int mySum(int a, int b); 

ABINTERFACE_API int GetTLedInfo(TKzInfoOutput *pTkzInfo, int *led_val, int* sd_val, int* jy_val, int* zs_val);
ABINTERFACE_API int GetTKzStatusBits(TKzInfoOutput *pTkzInfo, int *main_use_status, int *data_use_status, int *jm2x2s_status, int* kz2x2s_status,
					      int *jm1_status, int *jm2_status, int *can_status, int *cgq_status,
					      int *parled_checkLstatus, int *parled_bakstatus, int *parsd_jyzs_bakstatus, int *hwsxx_status,
					      int *sxxbs_backstatus,int *cga_status, int *je_status, int *vd50_status, 
					      int *abwk_status,int *rev, int *rl_status);
ABINTERFACE_API int GetUseStateInfo(TKzInfoOutput *pTkzInfo, char *main_use_flag, char *hw_sxx, char *zpw_carrier_lock, char *use_jm_channel);
ABINTERFACE_API int GetExtPortInfo(TKzInfoOutput *pTkzInfo, char (*ext_port)[]);
ABINTERFACE_API int GetTjmPartInfoJm1(TKzInfoOutput *pTkzInfo, int *led_val, int *sd_val, int *jy_val, int *zs_val,
				               char *curr_sgn_zx, char *hw_sxx, char *zpw_carrier_lock, char *cgq_tz_code_status,
					       short *cgq_tz_code_amp, short *zs_decode_en_status);
ABINTERFACE_API int GetTjmPartInfoJm2(TKzInfoOutput *pTkzInfo, int *led_val, int *sd_val, int *jy_val, int *zs_val,
				               char *curr_sgn_zx, char *hw_sxx, char *zpw_carrier_lock, char *cgq_tz_code_status,
					       short *cgq_tz_code_amp, short *zs_decode_en_status);
ABINTERFACE_API int GetTZpwExtInfoJm1(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					      short *carrier_freq, short *modulate_freq, short *led_delay_time,
					      char *carrier_lock, char *lock_delay_time);
ABINTERFACE_API int GetTZpwExtInfoJm2(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					      short *carrier_freq, short *modulate_freq, short *led_delay_time,
					      char *carrier_lock, char *lock_delay_time);
ABINTERFACE_API int GetTYpExtInfoJm1(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					     short *carrier_freq, short *modulate_freq, short *led_delay_time,
					     char (*rev)[]);
ABINTERFACE_API int GetTYpExtInfoJm2(TKzInfoOutput *pTkzInfo,short *sgn_amp, char *carrier_freq_index, char *modulate_fre_index, 
					     short *carrier_freq, short *modulate_freq, short *led_delay_time,
					     char (*rev)[]);
ABINTERFACE_API int GetTJljxExtInfo25Jm1(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					          short *freq, short *led_delay_time);
ABINTERFACE_API int GetTJljxExtInfo25Jm2(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					          short *freq, short *led_delay_time);
ABINTERFACE_API int GetTJljxExtInfo50Jm1(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					          short *freq, short *led_delay_time);
ABINTERFACE_API int GetTJljxExtInfo50Jm2(TKzInfoOutput *pTkzInfo, short *sgn_amp, char *fre_index, char *sgn_index, 
					                           short *freq, short *led_delay_time);

#ifdef __cplusplus
}
#endif
