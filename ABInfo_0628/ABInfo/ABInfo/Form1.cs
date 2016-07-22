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
        string filePath;
        int iCount = 0;
        int iPart = 10000;
        int iPos = 1;
        int iNum = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void btOpen_Click(object sender, EventArgs e)
        {
            iCount = 0;
            listBoxABData.Items.Clear();
            tbText.Text = "";
            OpenFileDialog fileName = new OpenFileDialog();
            //fileName.InitialDirectory = Application.StartupPath;
            fileName.Filter = "Status file(*.sts)|*.sts|All file(*.*)|*.*";
            fileName.RestoreDirectory = true;
            if (fileName.ShowDialog() == DialogResult.OK)
            {
                filePath = fileName.FileName.ToString();
                string extension = System.IO.Path.GetExtension(filePath);
                if (".sts" != extension.ToLower())
                {
                    MessageBox.Show("文件选择错误！");
                    return;
                }

                //使用“打开”对话框中选择的文件名实例化FileStream对象
                FileInfo dataFileInfo = new FileInfo(filePath);
                int iBytesSize = (int)dataFileInfo.Length;
                iNum = iBytesSize / 256;
                if (iNum <= 10000)
                {
                    buttonFirst.Enabled = false;
                    buttonFront.Enabled = false;
                    buttonNext.Enabled = false;
                    buttonTail.Enabled = false;
                }
                else
                {
                    buttonFirst.Enabled = true;
                    buttonFront.Enabled = true;
                    buttonNext.Enabled = true;
                    buttonTail.Enabled = true;
                }
                

                FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);

                byte[] data = new byte[256];

                int offset = 0;
                while (true)
                {
                    myStream.Seek(offset, SeekOrigin.Begin);
                    int len = myStream.Read(data, 0, 256);
                    if (len <= 0)
                        break;
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

                    iCount++;
                    listBoxABData.Items.Add("No:" + iCount.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                    Array.Clear(data, 0, data.Length);
                    offset = offset + 256;

                    if (iCount >= 10000)
                        break;
                    
                }

                //textBox1.Text = txtText;
                //关闭当前二进制读取流
                //myReader.Close();
                //关闭当前文件流
                //iPos = iPart + 1;
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
            
            /*
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
            */
             
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
            tbText.Text = "";
            tbText.AppendText(st + "\r\n");

            /********************************************************/
            /*
             * LED灯信息
             */
            /********************************************************/
            int ledLedVal, ledSdVal, ledJyVal, ledZsVal;
            ABinfoInterface.GetTLedInfo(ABdata, out ledLedVal, out ledSdVal, out ledJyVal, out ledZsVal);
            string ledStr = "";
            ledStr = "LED灯信息：" + "\r\n" + "Led值：" + ledLedVal.ToString("D2") +
                " " + " Sd值：" + ledSdVal.ToString("D2") + " " + " Jy值：" + ledJyVal.ToString("D2") + " " + " Zs值：" + ledZsVal.ToString("D2");
            //tbText.Text = "";
            tbText.AppendText(ledStr + "\r\n");

            /********************************************************/
            /*
             * 主机检测状态信息
             */
            /********************************************************/
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
            statusBitsStr += "主控输出：" + mainUseStatus.ToString() + "    " + "数据使用状态：" + dataUseStatus.ToString() + "\r\n" +
                            "2取2状态(1表示2取2错误)：" + jm2x2sStatus.ToString() + "\r\n" + "2乘2状态(1表示另一主机不可用)：" + kz2x2sStatus.ToString() + "\r\n" +
                            "解码通道1状态(0表示OK)：" + jm1Status.ToString() + "\r\n" + "解码通道2状态(0表示OK)：" + jm2Status.ToString() + "\r\n" +
                            "CAN总线状态(0表示OK)：" + canStatus.ToString() + "\r\n" + "CGQ状态(0表示OK)：" + cgqStatus.ToString() + " " + "\r\n" +
                            "并行检测状态(0表示OK)：" + parledCheckLstatus.ToString() + "\r\n" + "八灯回检状态(0表示OK)：" + parledBakstatus.ToString() + "\r\n" +
                            "其它并行输出回检状态(0表示OK)：" + parsdJyzs_bakstatus.ToString() + "\r\n" + "上下输入状态(0表示OK)：" + hwsxxStatus.ToString() + "\r\n" +
                            "上下行表示输出回检状态(0表示OK)：" + sxxbsBackstatus + "\r\n" + "强制工作状态(1表示强制)：" + cgaStatus.ToString() + "\r\n" +
                            "八灯错误状态(1表示有错误输出)：" + jeStatus.ToString() + "\r\n" + "动态电源状态(1表示没检测到电源)：" + vd50Status.ToString() + "\r\n" +
                            "AB机工作状态(1表示不在主控状态)：" + abwkStatus.ToString() + "    " + "保留值：" + rev.ToString() + "\r\n" +
                            "八个继电器状态(对应位为1表示对应的控制位出现错误)：" + rlStatus.ToString();
            tbText.AppendText(statusBitsStr + "\r\n");

            /********************************************************/
            /*
             * 解码信息
             */
            /********************************************************/
            char mainUseFlag, hwSxx, zpwCarrierLock, useJmChannel;
            string useStr = "\r\n" + "解码信息：" + "\r\n";
            ABinfoInterface.GetUseStateInfo(ABdata, out mainUseFlag, out hwSxx, out zpwCarrierLock, out useJmChannel);
            useStr += "主用标志(1表示主控制)：" + ((int)mainUseFlag).ToString() + "    " + "上下行：" + ((int)hwSxx).ToString() + "\r\n" +
                      "ZPW载波锁定：" + ((int)zpwCarrierLock).ToString() + "    " + "当前采用解码通道数据：" + ((int)useJmChannel).ToString();
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
            tbText.AppendText(extPortStr+"\r\n");

            int jm1LedVal, jm1SdVal, jm1JyVal, jm1ZsVal;
            char CurrSgnZx, HwSxx, ZpwCarrierLock, CgqTzCodeStatus;
            short CgqTzCodeAmp, ZsDecodeEnStatus;
            string jm1PartInfoStr = "\r\n" + "解码通道JM1信息：" + "\r\n";
            ABinfoInterface.GetTjmPartInfoJm1(ABdata, out jm1LedVal, out jm1SdVal, out jm1JyVal, out jm1ZsVal,
                                              out CurrSgnZx, out HwSxx, out ZpwCarrierLock, out CgqTzCodeStatus,
                                              out CgqTzCodeAmp, out ZsDecodeEnStatus);
            jm1PartInfoStr += "LED值：" + jm1LedVal.ToString() + "  SD值：" + jm1SdVal.ToString() + "  JY值：" + jm1JyVal.ToString() + "  ZS值：" + jm1ZsVal.ToString() + "\r\n" +
                              "CurSgnZs值: " + ((int)CurrSgnZx).ToString() + "  HwSxx上下行：" + ((int)HwSxx).ToString() + "  当前载波锁定：" + ((int)ZpwCarrierLock).ToString() + "\r\n" +
                              "传感器特征代码状态: " + ((int)CgqTzCodeStatus).ToString() + " 传感器特征代码幅度(0.1MV): " + ((int)CgqTzCodeAmp).ToString() + "\r\n" +
                              "各种解码允许情况: " + ((int)ZsDecodeEnStatus).ToString();
            tbText.AppendText(jm1PartInfoStr+"\r\n");

            switch ((int)CurrSgnZx)
            {
                case 0:
                    break;
                case 1:
                    /********************************************************/
                    /*
                     * ZPW2K解码信息
                     */
                    /********************************************************/
                    short zpwSgnAmp;
                    char zpwCarrierFreqIndex, zpwModulateFreIndex;
                    short zpwCarrierFreq, zpwModulateFreq, zpwLedDelayTime;
                    char zpwZxCarrierLock, zpwLockDelayTime;
                    string zpwInfoJm1Str = "\r\n" + "ZPW2000信息：" + "\r\n";
                    ABinfoInterface.GetTZpwExtInfoJm1(ABdata, out zpwSgnAmp, out zpwCarrierFreqIndex, out zpwModulateFreIndex,
                                                      out zpwCarrierFreq, out zpwModulateFreq, out zpwLedDelayTime,
                                                      out zpwZxCarrierLock, out zpwLockDelayTime);

                    zpwInfoJm1Str += "信号幅度：" + ((float)zpwSgnAmp/10).ToString() + "\t" + "载波频率索引：" + ((int)zpwCarrierFreqIndex).ToString() + "\r\n" +
                                      "调制频率索引：" + ((int)zpwModulateFreIndex).ToString() + "\t" + "载波频率： " + ((float)zpwCarrierFreq/10).ToString() + "\r\n" +
                                      "调制频率：" + ((float)zpwModulateFreq/100).ToString() + "\t" + "无码时间：" + ((int)zpwLedDelayTime).ToString() + "\r\n" +
                                      "载波锁定值：" + ((int)zpwZxCarrierLock).ToString() + "\t" + "锁定无码时间：" + ((int)zpwLockDelayTime).ToString();
                    tbText.AppendText(zpwInfoJm1Str + "\r\n");
                    break;
                case 2:
                    //MessageBox.Show("Yiping");
                    /********************************************************/
                    /*
                     * 移频信息
                     */
                    /********************************************************/
                    short ypSgnAmp;
                    char ypCarrierFreqIndex, ypModulateFreIndex;
                    short ypCarrierFreq, ypModulateFreq, ypLedDelayTime;
                    char[] ypRev = new char[2];
                    string ypInfoJm1Str = "\r\n" + "YP信息：" + "\r\n";
                    ABinfoInterface.GetTYpExtInfoJm1(ABdata, out ypSgnAmp, out ypCarrierFreqIndex, out ypModulateFreIndex,
                    out ypCarrierFreq, out ypModulateFreq, out ypLedDelayTime, ypRev);
                    ypInfoJm1Str += "信号幅度：" + ((float)ypSgnAmp/10).ToString() + "\t" + "载波频率索引" + ((int)ypCarrierFreqIndex).ToString() + "\r\n" +
                                      "调制频率索引：" + ((int)ypModulateFreIndex).ToString() + "\t" + "载波频率： " + ((float)ypCarrierFreq/10).ToString() + "\r\n" +
                                      "调制频率：" + ((float)ypModulateFreq / 100).ToString() + "\t" + "无码时间：" + ((int)ypLedDelayTime).ToString() + "\r\n" +
                                      "保留值：" + ((int)ypRev[0]).ToString("D2") + "\t" + ((int)ypRev[1]).ToString("D2");
                    tbText.AppendText(ypInfoJm1Str + "\r\n");
                    break;
                case 3:
                    //MessageBox.Show("JLJS25");
                    /********************************************************/
                    /*
                     * 交流计数
                     */
                    /********************************************************/
                    short jljs25SgnAmp;
                    char jljs25FreIndex;
                    char jljs25SgnIndex;
                    short jljs25Freq;
                    short jljs25LedDelayTime;
                    string jljs25Jm1Str = "\r\n" + "交流计数信息(25Hz)：" + "\r\n";
                    ABinfoInterface.GetTJljxExtInfo25Jm1(ABdata, out jljs25SgnAmp, out jljs25FreIndex,
                                        out jljs25SgnIndex, out jljs25Freq, out jljs25LedDelayTime);
                    jljs25Jm1Str += "信号幅度：" + ((float)jljs25SgnAmp/10).ToString() + "\t" + "频率索引" + ((int)jljs25FreIndex).ToString() + "\r\n" +
                                    "信号索引：" + ((int)jljs25SgnIndex).ToString() + "\t" + "信号频率： " + ((float)jljs25Freq/10).ToString() + "\r\n" +
                                    "无码时间：" + ((int)jljs25LedDelayTime).ToString();
                    tbText.AppendText(jljs25Jm1Str + "\r\n");
                    break;
                case 4:
                    //MessageBox.Show("JLJS50");
                    short jljs50SgnAmp;
                    char jljs50FreIndex;
                    char jljs50SgnIndex;
                    short jljs50Freq;
                    short jljs50LedDelayTime;
                    string jljs50Jm1Str = "\r\n" + "交流计数信息(50Hz)：" + "\r\n";
                    ABinfoInterface.GetTJljxExtInfo50Jm1(ABdata, out jljs50SgnAmp, out jljs50FreIndex,
                                        out jljs50SgnIndex, out jljs50Freq, out jljs50LedDelayTime);
                    jljs50Jm1Str += "信号幅度：" + ((float)jljs50SgnAmp/10).ToString() + "\t" + "频率索引" + ((int)jljs50FreIndex).ToString() + "\r\n" +
                                    "信号索引：" + ((int)jljs50SgnIndex).ToString() + "\t" + "信号频率： " + ((float)jljs50Freq/10).ToString() + "\r\n" +
                                    "无码时间：" + ((int)jljs50LedDelayTime).ToString();
                    tbText.AppendText(jljs50Jm1Str + "\r\n");
                    //ABinfoInterface.GetTJljxExtInfo50Jm1();
                    break;
                case 5:
                    string dgtStr = "";
                    tbText.AppendText("\r\n" + "单轨道信息：暂不支持" + "\r\n");
                    break;
                case 6:
                    string jpStr = "";
                    tbText.AppendText("\r\n" + "极频信息：暂不支持" + "\r\n");
                    break;
                case 7:
                    string tvm430Str = "";
                    tbText.AppendText("\r\n" + "TVM430：暂不支持" + "\r\n");
                    break;
                case 8:
                    string bootStr = "";
                    tbText.AppendText("\r\n" + "BOOPROG：暂不支持" + "\r\n");
                    break;
                default:
                    string otherStr = "";
                    tbText.AppendText("\r\n" + "其它：暂不支持" + "\r\n");
                    break;

            }


            //int aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss;
            //ABinfoInterface.GetTKzStatusBits(ABdata, out aa, out bb, out c, out dd, out ee, out ff, out gg, out hh, out ii, out jj,
             //   out kk, out ll, out mm, out nn, out oo, out pp, out qq, out rr, out ss);

            //GetTLedInfo(ABdata, out xx, out yy, out zz, out aa);


        }

        private void buttonFirst_Click(object sender, EventArgs e)
        {
            if (iNum <= 0)
                return;

            FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[256];
            int offset = 0;
            iCount = 0;

            listBoxABData.Items.Clear();
            while (true)
            {
                myStream.Seek(offset, SeekOrigin.Begin);
                int len = myStream.Read(data, 0, 256);
                if (len <= 0)
                    break;
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
                for (int i = 4, j = 0; i < 8; i++, j++)
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

                iCount++;
                listBoxABData.Items.Add("No:" + iCount.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                Array.Clear(data, 0, data.Length);
                offset = offset + 256;

                if (iCount >= 10000)
                    break;

            }

            //textBox1.Text = txtText;
            //关闭当前二进制读取流
            //myReader.Close();
            //关闭当前文件流
            iPos = iPart + 1;
            myStream.Close();



        }

        private void buttonFront_Click(object sender, EventArgs e)
        {
            iCount = iPos - iPart;
            if (iCount < 1)
                return;

            FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[256];
            int offset = (iCount-1)*256;
            //iCount = 0;

            listBoxABData.Items.Clear();
            int k;
            for (k = iCount; k < iPos; k++ )
            {
                myStream.Seek(offset, SeekOrigin.Begin);
                int len = myStream.Read(data, 0, 256);
                if (len <= 0)
                    break;
                StringBuilder sbString = new StringBuilder();
                StringBuilder ABinfoString = new StringBuilder();
                StringBuilder sbTime = new StringBuilder();
                byte[] btTime = new byte[4];
                for (int i = 4, j = 0; i < 8; i++, j++)
                {
                    btTime[j] = data[i];
                }
                for (int i = 38; i < 110; i++)
                {
                    ABinfoString.Append(data[i].ToString("X2") + " ");
                }
                string strDateTime = ABProtcol.GetDateTime(btTime);

                //k++;
                listBoxABData.Items.Add("No:" + k.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                Array.Clear(data, 0, data.Length);
                offset = offset + 256;

            }
            iPos = iCount;

        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
            iCount = iPos + iPart;
            FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[256];
            int offset;

            if (iCount <= iNum)
            {
                listBoxABData.Items.Clear();
                offset = (iCount - 1) * 256;
                int k;
                for (k = iCount; k < iCount + iPart; k++)
                {
                    myStream.Seek(offset, SeekOrigin.Begin);
                    int len = myStream.Read(data, 0, 256);
                    if (len <= 0)
                        break;
                    StringBuilder sbString = new StringBuilder();
                    StringBuilder ABinfoString = new StringBuilder();
                    StringBuilder sbTime = new StringBuilder();
                    byte[] btTime = new byte[4];
                    for (int i = 4, j = 0; i < 8; i++, j++)
                    {
                        btTime[j] = data[i];
                    }
                    for (int i = 38; i < 110; i++)
                    {
                        ABinfoString.Append(data[i].ToString("X2") + " ");
                    }
                    string strDateTime = ABProtcol.GetDateTime(btTime);

                    //iCount++;
                    listBoxABData.Items.Add("No:" + k.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                    Array.Clear(data, 0, data.Length);
                    offset = offset + 256;

                }
                iPos = iCount;

            }
            else if (iCount - iNum < iPart)
            {
                iCount = iPos + iPart;
                //FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
                listBoxABData.Items.Clear();
                offset = (iPos - 1) * 256;
                int k;
                for (k = iPos; k <= iNum; k++)
                {
                    myStream.Seek(offset, SeekOrigin.Begin);
                    int len = myStream.Read(data, 0, 256);
                    if (len <= 0)
                        break;
                    StringBuilder sbString = new StringBuilder();
                    StringBuilder ABinfoString = new StringBuilder();
                    StringBuilder sbTime = new StringBuilder();
                    byte[] btTime = new byte[4];
                    for (int i = 4, j = 0; i < 8; i++, j++)
                    {
                        btTime[j] = data[i];
                    }
                    for (int i = 38; i < 110; i++)
                    {
                        ABinfoString.Append(data[i].ToString("X2") + " ");
                    }
                    string strDateTime = ABProtcol.GetDateTime(btTime);

                    //iCount++;
                    listBoxABData.Items.Add("No:" + k.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                    Array.Clear(data, 0, data.Length);
                    offset = offset + 256;

                }
                //iPos = iCount;
            }
            else
                return;

        }

        private void buttonTail_Click(object sender, EventArgs e)
        {
            int iTailStartNum = iNum % iPart;
            if (iTailStartNum == 0)
            {
                iPos = iNum - iPart + 1;
            }
            else
                iPos = iNum - iTailStartNum + 1;

            FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[256];
            int offset = (iPos - 1) * 256;
            //iCount = 0;

            listBoxABData.Items.Clear();
            int k;
            for (k = iPos; k <= iNum; k++)
            {
                myStream.Seek(offset, SeekOrigin.Begin);
                int len = myStream.Read(data, 0, 256);
                if (len <= 0)
                    break;
                StringBuilder sbString = new StringBuilder();
                StringBuilder ABinfoString = new StringBuilder();
                StringBuilder sbTime = new StringBuilder();
                byte[] btTime = new byte[4];
                for (int i = 4, j = 0; i < 8; i++, j++)
                {
                    btTime[j] = data[i];
                }
                for (int i = 38; i < 110; i++)
                {
                    ABinfoString.Append(data[i].ToString("X2") + " ");
                }
                string strDateTime = ABProtcol.GetDateTime(btTime);

                //k++;
                listBoxABData.Items.Add("No:" + k.ToString() + ". " + strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");

                Array.Clear(data, 0, data.Length);
                offset = offset + 256;

            }
        }

        private void tbText_TextChanged(object sender, EventArgs e)
        {

        }




    }
}
