using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
//
using System.Text.RegularExpressions;

namespace ABInfo
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void btOpen_Click(object sender, EventArgs e)
        {
            listBoxABData.Items.Clear();
            OpenFileDialog fileName = new OpenFileDialog();
            //fileName.InitialDirectory = Application.StartupPath;
            fileName.Filter = "All file(*.*)|*.*|txt file(*.txt)|*.txt";
            fileName.RestoreDirectory = true;
            if (fileName.ShowDialog() == DialogResult.OK)
            {
                string filePath = fileName.FileName.ToString();

                //使用“打开”对话框中选择的文件名实例化FileStream对象
                FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);

                byte[] data = new byte[256];

                int offset = 0;
                while (true)
                {
                    int len = myStream.Read(data, 0, 256);
                    myStream.Seek(offset, SeekOrigin.Begin);
                    StringBuilder sbString = new StringBuilder();
                    StringBuilder ABinfoString = new StringBuilder();
                    StringBuilder sbTime = new StringBuilder();
                    /*
                    for (int i = 0; i < len; i++)
                    {
                        sbString.Append(data[i].ToString("X2") + " ");
                    }
                     * */
                    byte[] btTime = new byte[4];
                    for (int i = 4,j =0; i < 8; i++,j++)
                    {
                        btTime[j] = data[i];
                    }
                    for (int i = 38; i < 110; i++)
                    {
                        ABinfoString.Append(data[i].ToString("X2") + " ");
                    }

                    //textBox1.AppendText(sbString.ToString() + "\r\n");
                    //textBox1.AppendText(ABinfoString.ToString() + "\r\n");
                    string strDateTime = ABProtcol.GetDateTime(btTime);


                    listBoxABData.Items.Add(strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                    Array.Clear(data, 0, data.Length);
                    offset = offset + 256;
                    if (len <= 0)
                        break;
                }

                //textBox1.Text = txtText;
                //关闭当前二进制读取流
                //myReader.Close();
                //关闭当前文件流
                myStream.Close();

            }

   
        }

        private void listBoxABData_DrawItem(object sender, System.Windows.Forms.DrawItemEventArgs e)
        {
            e.DrawBackground();
            Brush myBrush = Brushes.Black; //初始化字体颜色=黑色  
            this.listBoxABData.ItemHeight = 55; //设置项高，根据具体需要设置值  
            //为每个项设置字体颜色  
            //如果不需要可以不写此switch 
            
            switch (e.Index%4)
            {
                case 0:
                    myBrush = Brushes.Brown;
                    break;
                case 1:
                    myBrush = Brushes.Green;
                    break;
                case 2:
                    myBrush = Brushes.Purple;
                    break;
                case 3:
                    myBrush = Brushes.Blue;
                    break;
                default:
                    myBrush = Brushes.Black;
                    break;
            }
             
            e.Graphics.DrawString(listBoxABData.Items[e.Index].ToString(), e.Font, myBrush, e.Bounds, null);
            //  
            e.DrawFocusRectangle();
        } 

        private void Form1_Load(object sender, EventArgs e)
        {
           //listBoxABData.Items.Add("111111111\r\n2222222222");
        }
        private string ChangeToTwoHex(string value)
        {
            string strTemp = value.Trim();
            if (strTemp.Length > 2 || strTemp.Length <= 0)
                return "";
            if (strTemp.Length == 2)
                return value;
            else
                strTemp = '0' + strTemp;
            return strTemp;
        }

        private void listBoxABData_SelectedIndexChanged(object sender, EventArgs e)
        {
            string pattern = "AB机数据: (.+)";
            string st = listBoxABData.SelectedItem.ToString();
            string strHex = "";

            Match mt = Regex.Match(st, pattern);
            string strData = mt.ToString();
            string[] strNum = strData.Split(new char[] { ' ' });

            int i = 0;
            foreach (string strN in strNum)
            {
                //MessageBox.Show(strN);
                if (i >= 1)
                {
                    strHex += ChangeToTwoHex(strN) + " ";
                }
                i++;
            }
            strHex = strHex.Trim();
            //MessageBox.Show(strHex);
            strHex = strHex.Replace(" ", "");
            byte[] ABdata = new byte[72];
            int len = (strHex.Length)/2;
            for(int j=0;j<len;j++)
            {
                ABdata[j] = Convert.ToByte(strHex.Substring(j * 2, 2), 16);
            }
            //MessageBox.Show(ABinfoInterface.mySum(2, 3).ToString());
            /*
            string filePath = "d:\\byte1.data";
            FileStream myStream = new FileStream(filePath, FileMode.OpenOrCreate, FileAccess.ReadWrite);
            myStream.Write(ABdata, 0, len);
            myStream.Close();
            */
            //int xx, yy, zz, aa;

            int ledLedVal, ledSdVal, ledJyVal, ledZsVal;
            ABinfoInterface.GetTLedInfo(ABdata, out ledLedVal, out ledSdVal, out ledJyVal, out ledZsVal);
            string ledStr = "";
            ledStr = "LED灯信息：" + "\r\n" + "Led值：" + ledLedVal.ToString() +
                " " + "Sd值：" + ledSdVal.ToString() + " " + "Jy值：" + ledJyVal.ToString() + " " + "Zs值：" + ledZsVal.ToString();
            tbText.Text = "";
            tbText.AppendText(ledStr);

            int mainUseStatus, dataUseStatus, jm2x2sStatus, kz2x2sStatus,
		       jm1Status, jm2Status, canStatus, cgqStatus,
		       parledCheckLstatus, parledBakstatus, parsdJyzs_bakstatus, hwsxxStatus,
		       sxxbsBackstatus,cgaStatus, jeStatus, vd50Status, 
		       abwkStatus, rev, rlStatus;
            string statusBitsStr = "\r\n" + "主机检测状态：" + "\r\n";
            ABinfoInterface.GetTKzStatusBits(ABdata, out mainUseStatus, out dataUseStatus, out jm2x2sStatus, out kz2x2sStatus,
               out jm1Status, out jm2Status, out canStatus, out cgqStatus,
               out parledCheckLstatus, out parledBakstatus, out parsdJyzs_bakstatus, out hwsxxStatus,
               out sxxbsBackstatus, out cgaStatus, out jeStatus, out vd50Status,
               out abwkStatus, out rev, out rlStatus);
            statusBitsStr += "主控输出：" + mainUseStatus.ToString() + " " + "数据使用状态：" + dataUseStatus.ToString() + " " +
                            "2取2状态(1表示2取2错误)：" + jm2x2sStatus.ToString() + " " + "2乘2状态(1表示另一主机不可用)：" + kz2x2sStatus.ToString() + " " + "\r\n" +
                            "解码通道1状态(0表示OK)：" + jm1Status.ToString() + " " + "解码通道2状态(0表示OK)：" + jm2Status.ToString() + " " + 
                            "CAN总线状态(0表示OK)：" + canStatus.ToString() + " " + "CGQ状态(0表示OK)：" + cgqStatus.ToString() + " " + "\r\n" +
                            "并行检测状态(0表示OK)：" + parledCheckLstatus.ToString() + " " + "八灯回检状态(0表示OK)：" + parledBakstatus.ToString() + " " +
                            "其它并行输出回检状态(0表示OK)：" + parsdJyzs_bakstatus.ToString() + " " + "上下输入状态(0表示OK)：" + hwsxxStatus.ToString() + " " + "\r\n" +
                            "上下行表示输出回检状态(0表示OK)：" + sxxbsBackstatus + " " + "强制工作状态(1表示强制)：" + cgaStatus.ToString() + " " +
                            "八灯错误状态(1表示有错误输出)：" + jeStatus.ToString() + " " + "动态电源状态(1表示没检测到电源)：" + vd50Status.ToString() + " " + "\r\n" +
                            "AB机工作状态(1表示不在主控状态)：" + abwkStatus.ToString() + " " + "保留值：" + rev.ToString() + " " +
                            "八个继电器状态(对应位为1表示对应的控制位出现错误)：" + rlStatus.ToString();
            tbText.AppendText(statusBitsStr);

            char mainUseFlag, hwSxx, zpwCarrierLock, useJmChannel;
            string useStr = "\r\n" + "解码信息：" + "\r\n";
            ABinfoInterface.GetUseStateInfo(ABdata, out mainUseFlag, out hwSxx, out zpwCarrierLock, out useJmChannel);
            useStr += "主用标志(1表示主控制)：" + ((int)mainUseFlag).ToString() + " " + "上下行：" + ((int)hwSxx).ToString() + " " +
                      "ZPW载波锁定：" + ((int)zpwCarrierLock).ToString() + " " + "当前采用解码通道数据：" + ((int)useJmChannel).ToString();
            tbText.AppendText(useStr);

            char[] extPortInfo = new char[8];
            string extPortStr = "\r\n" + "外部控制口当前数据：";
            ABinfoInterface.GetExtPortInfo(ABdata, extPortInfo);
            for (int k = 0; k < extPortInfo.Length; k++)
            {
                if (k == 4)
                    extPortStr += " " + ((int)extPortInfo[k]).ToString("D2");
                else
                    extPortStr += ((int)extPortInfo[k]).ToString("D2");
            }
            tbText.AppendText(extPortStr);

            int jm1LedVal, jm1SdVal, jm1JyVal, jm1ZsVal;
            char CurrSgnZx, HwSxx, ZpwCarrierLock, CgqTzCodeStatus;
            short CgqTzCodeAmp, ZsDecodeEnStatus;
            string jm1PartInfoStr = "\r\n" + "JM1信息：" + "\r\n";
            ABinfoInterface.GetTjmPartInfoJm1(ABdata, out jm1LedVal, out jm1SdVal, out jm1JyVal, out jm1ZsVal,
                                              out CurrSgnZx, out HwSxx, out ZpwCarrierLock, out CgqTzCodeStatus,
                                              out CgqTzCodeAmp, out ZsDecodeEnStatus);
            jm1PartInfoStr += "LED值：" + jm1LedVal.ToString() + "SD值：" + jm1SdVal.ToString() + "JY值：" + jm1JyVal.ToString() + "ZS值：" + jm1ZsVal.ToString() + "\r\n" +
                              "CurSgnZs值" + ((int)CurrSgnZx).ToString() + "HwSxx上下行：" + ((int)HwSxx).ToString() + "当前载波锁定：" + ((int)ZpwCarrierLock).ToString() + "\r\n" +
                              "传感器特征代码状态" + ((int)CgqTzCodeStatus).ToString() + "传感器特征代码幅度(0.1MV)" + ((int)CgqTzCodeAmp).ToString() + "\r\n" +
                              "各种解码允许情况" + ((int)ZsDecodeEnStatus).ToString();
            tbText.AppendText(jm1PartInfoStr);

            short zpwSgnAmp;
            char zpwCarrierFreqIndex, zpwModulateFreIndex;
            short zpwCarrierFreq, zpwModulateFreq, zpwLedDelayTime;
            char zpwZxCarrierLock, zpwLockDelayTime;
            string zpwInfoJm1Str = "\r\n" + "ZPW2000信息：" + "\r\n";
            ABinfoInterface.GetTZpwExtInfoJm1(ABdata, out zpwSgnAmp, out zpwCarrierFreqIndex, out zpwModulateFreIndex,
                                              out zpwCarrierFreq, out zpwModulateFreq, out zpwLedDelayTime,
                                              out zpwZxCarrierLock, out zpwLockDelayTime);

            zpwInfoJm1Str += "信号幅度：" + ((int)zpwSgnAmp).ToString() + "载波频率索引" + ((int)zpwCarrierFreqIndex).ToString() + "\r\n" +
                              "调制频率索引：" + ((int)zpwModulateFreIndex).ToString() + "载波频率： " + ((int)zpwCarrierFreq).ToString() + "\r\n" +
                              "调制频率：" + ((int)zpwModulateFreq).ToString() + "无码时间：" + ((int)zpwLedDelayTime).ToString() + "\r\n" +
                              "载波锁定值：" + ((int)zpwZxCarrierLock).ToString() + "锁定无码时间：" + ((int)zpwLockDelayTime).ToString();
            tbText.AppendText(zpwInfoJm1Str);
                              
            short ypSgnAmp;
	        char ypCarrierFreqIndex, ypModulateFreIndex; 
	        short ypCarrierFreq, ypModulateFreq,ypLedDelayTime;
            char[] ypRev = new char[2];
            string ypInfoJm1Str = "\r\n" + "YP信息：" + "\r\n";
            ABinfoInterface.GetTYpExtInfoJm1(ABdata, out ypSgnAmp, out ypCarrierFreqIndex, out ypModulateFreIndex,
            out ypCarrierFreq, out ypModulateFreq, out ypLedDelayTime, ypRev);
            ypInfoJm1Str += "信号幅度：" + ((int)ypSgnAmp).ToString() + "载波频率索引" + ((int)ypCarrierFreqIndex).ToString() + "\r\n" +
                              "调制频率索引：" + ((int)ypModulateFreIndex).ToString() + "载波频率： " + ((int)ypCarrierFreq).ToString() + "\r\n" +
                              "调制频率：" + ((int)ypModulateFreq).ToString() + "无码时间：" + ((int)ypLedDelayTime).ToString() + "\r\n" +
                              "保留值：" + ((int)ypRev[0]).ToString("D2") + " " + ((int)ypRev[1]).ToString("D2");
            tbText.AppendText(ypInfoJm1Str);

            short jljs25SgnAmp;
            char jljs25FreIndex;
            char jljs25SgnIndex;
            short jljs25Freq;
            short jljs25LedDelayTime;
            string jljs25Jm1Str = "\r\n" + "交流计数信息(25Hz)：" + "\r\n";
            ABinfoInterface.GetTJljxExtInfo25Jm2(ABdata, out jljs25SgnAmp, out jljs25FreIndex,
                                out jljs25SgnIndex, out jljs25Freq, out jljs25LedDelayTime);
            jljs25Jm1Str += "信号幅度：" + ((int)jljs25SgnAmp).ToString() + "频率索引" + ((int)jljs25FreIndex).ToString() + "\r\n" +
                            "信号索引：" + ((int)jljs25SgnIndex).ToString() + "信号频率： " + ((int)jljs25Freq).ToString() + "\r\n" +
                            "无码时间：" + ((int)ypLedDelayTime).ToString();
            tbText.AppendText(jljs25Jm1Str);
            //int aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss;
            //ABinfoInterface.GetTKzStatusBits(ABdata, out aa, out bb, out c, out dd, out ee, out ff, out gg, out hh, out ii, out jj,
             //   out kk, out ll, out mm, out nn, out oo, out pp, out qq, out rr, out ss);

            //GetTLedInfo(ABdata, out xx, out yy, out zz, out aa);


        }




    }
}
