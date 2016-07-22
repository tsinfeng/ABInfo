using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//
using System.Runtime.InteropServices;

namespace ABInfo
{
    class ABinfoInterface
    {
        [DllImport("ABInterface.dll")]
        public static extern int mySum(int a, int b);
        [DllImport("ABInterface.dll")]
        public static extern int GetTLedInfo(byte[] pTkzInfo, out int led_val, out int sd_val, out int jy_val, out int zs_val);
        [DllImport("ABInterface.dll")]
        public static extern int GetTKzStatusBits(byte[] pTkzInfo, out int main_use_status, out int data_use_status, out int jm2x2s_status, out int kz2x2s_status,
					      out int jm1_status, out int jm2_status, out int can_status, out int cgq_status,
					      out int parled_checkLstatus, out int parled_bakstatus, out int parsd_jyzs_bakstatus, out int hwsxx_status,
					      out int sxxbs_backstatus,out int cga_status, out int je_status, out int vd50_status, 
					      out int abwk_status,out int rev, out int rl_status);
        [DllImport("ABInterface.dll")]
        public static extern int GetUseStateInfo(byte[] pTkzInfo, out char main_use_flag, out char hw_sxx, out char zpw_carrier_lock, out char use_jm_channel);
        [DllImport("ABInterface.dll")]
        public static extern int GetExtPortInfo(byte[] pTkzInfo, char[] ext_port);
        [DllImport("ABInterface.dll")]
        public static extern int GetTjmPartInfoJm1(byte[] pTkzInfo, out int led_val, out int sd_val, out int jy_val, out int zs_val,
				               out char  curr_sgn_zx, out char  hw_sxx, out char  zpw_carrier_lock, out char  cgq_tz_code_status,
					       out short  cgq_tz_code_amp, out short  zs_decode_en_status);
        [DllImport("ABInterface.dll")]
        public static extern int GetTjmPartInfoJm2(byte[] pTkzInfo, out int led_val, out int sd_val, out int jy_val, out int zs_val,
				               out char  curr_sgn_zx, out char  hw_sxx, out char  zpw_carrier_lock, out char cgq_tz_code_status,
					       out short  cgq_tz_code_amp, out short  zs_decode_en_status);
        [DllImport("ABInterface.dll")]
        public static extern int GetTZpwExtInfoJm1(byte[] pTkzInfo, out short sgn_amp, out char carrier_freq_index, out char modulate_fre_index, 
					      out short  carrier_freq, out short  modulate_freq, out short  led_delay_time,
					      out char  carrier_lock, out char  lock_delay_time);
        [DllImport("ABInterface.dll")]
        public static extern int GetTZpwExtInfoJm2(byte[] pTkzInfo, out short sgn_amp, out char carrier_freq_index, out char modulate_fre_index, 
					      out short  carrier_freq, out short  modulate_freq, out short  led_delay_time,
					      out char  carrier_lock, out char lock_delay_time);
        [DllImport("ABInterface.dll")]
        public static extern int GetTYpExtInfoJm1(byte[] pTkzInfo, out short sgn_amp, out char carrier_freq_index, out char modulate_fre_index, 
					     out short  carrier_freq, out short modulate_freq, out short  led_delay_time,
					     char []rev);
        [DllImport("ABInterface.dll")]
        public static extern int GetTYpExtInfoJm2(byte[] pTkzInfo, out short sgn_amp, out char carrier_freq_index, out char modulate_fre_index, 
					     out short  carrier_freq, out short modulate_freq, out short  led_delay_time,
					     char []rev);
        [DllImport("ABInterface.dll")]
        public static extern int GetTJljxExtInfo25Jm1(byte[] pTkzInfo, out short sgn_amp, out char fre_index, out char sgn_index, 
					          out short  freq, out short  led_delay_time);
        [DllImport("ABInterface.dll")]
        public static extern int GetTJljxExtInfo25Jm2(byte[] pTkzInfo, out short sgn_amp, out char fre_index, out char sgn_index, 
					          out short  freq, out short led_delay_time);
        [DllImport("ABInterface.dll")]
        public static extern int GetTJljxExtInfo50Jm1(byte[] pTkzInfo, out short sgn_amp, out char fre_index, out char sgn_index, 
					          out short  freq, out short led_delay_time);
        [DllImport("ABInterface.dll")]
        public static extern int GetTJljxExtInfo50Jm2(byte[] pTkzInfo, out short sgn_amp, out char fre_index, out char sgn_index, 
					                           out short freq, out short  led_delay_time);
    }
}
