using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace DataOutput
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath = @"D:\CSharpWork\ABProg\20160301173617\40C31911.STS";

            //使用“打开”对话框中选择的文件名实例化FileStream对象
            FileStream myStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);

            byte[] data = new byte[256];

            int iCount = 0;
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


                //listBoxABData.Items.Add(strDateTime + " AB机数据: " + ABinfoString.ToString() + "\r\n");
                System.Console.WriteLine(strDateTime + " AB机数据: " + ABinfoString.ToString());

                Array.Clear(data, 0, data.Length);
                offset = offset + 256;

                iCount++;
                System.Console.WriteLine("Line: " + iCount.ToString());
                if (len <= 0)
                    break;
            }

            //textBox1.Text = txtText;
            //关闭当前二进制读取流
            //myReader.Close();
            //关闭当前文件流
            myStream.Close();
            System.Console.Read();
        }
    }
}
