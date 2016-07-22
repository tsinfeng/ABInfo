using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataOutput
{
    class ABProtcol
    {
        private static string HexToBin(string strEncode)
        {
            int status_num = int.Parse(strEncode, System.Globalization.NumberStyles.AllowHexSpecifier);
            string binary_str = "";//  存储转换后的编码
            binary_str = Convert.ToString(status_num, 2);

            return binary_str;
        }
        public static bool get_bits_string(string strHex, int high_bit, int low_bit, ref string str_value) //D7-D1
        {
            //int iTotalValue = int.Parse(strHex, System.Globalization.NumberStyles.AllowHexSpecifier);
            char[] chBin = HexToBin(strHex).ToCharArray();
            char[] chArr = new char[32];
            string strPart = "";
            int i;
            for (i = 0; i < 32; i++)
            {
                chArr[i] = '0';
            }
            i = 0;
            foreach (char chr in chBin)
            {
                i++;
                //MessageBox.Show(chr.ToString());
            }
            int j;
            int k = 0;
            for (j = 32 - i; j < 32; j++)
            {
                chArr[j] = chBin[k];
                k++;
            }
            string strBin = new string(chArr);
            //MessageBox.Show(strBin);
            for (i = System.Math.Abs(high_bit - 31); i <= System.Math.Abs(low_bit - 31); i++)
            {
                strPart += chArr[i];
            }
            str_value = strPart;

            return true;
        }

        public static  byte[] byte_invert(byte[] byte_value)
        {
            int count = byte_value.Length;
            byte[] btTemp = new byte[count];
            
            for (int i = count - 1, j=0; i >=0; i--, j++)
            {
                btTemp[j] = byte_value[i];
            }
            return btTemp;
        }

        //Byte Change to Hex String
        public static string byte_to_string(byte[] byte_value)
        {
            StringBuilder sbStr = new StringBuilder();
            int i;
            for (i = 0; i < byte_value.Length; i++)
            {
                sbStr.Append(byte_value[i].ToString("X2"));
            }
            return sbStr.ToString();
        }
        //

        public static string GetDateTime(byte[] byte_time)
        {
            int year;
            int month;
            int day;
            int hour;
            int minute;
            int second;
            //int milisecond;

            byte[] btTime = new byte[4];
            btTime = byte_invert(byte_time);
            string strHex = byte_to_string(btTime);

            string strYear = "";
            get_bits_string(strHex, 31, 26, ref strYear);
            year = Convert.ToInt32(strYear, 2);
            string strMonth = "";
            get_bits_string(strHex, 25, 22, ref strMonth);
            month = Convert.ToInt32(strMonth, 2);

            string strDay = "";
            get_bits_string(strHex, 21, 17, ref strDay);
            day = Convert.ToInt32(strDay, 2);
            string strHour = "";
            get_bits_string(strHex, 16, 12, ref strHour);
            hour = Convert.ToInt32(strHour, 2);
            string strMinute = "";
            get_bits_string(strHex, 11, 6, ref strMinute);
            minute = Convert.ToInt32(strMinute, 2);
            string strSecond = "";
            get_bits_string(strHex, 5, 0, ref strSecond);
            second = Convert.ToInt32(strSecond, 2);

            return year.ToString("D2") + month.ToString("D2") + day.ToString("D2") + "_" + hour.ToString("D2") + minute.ToString("D2") + second.ToString("D2");
        }



    }
}
