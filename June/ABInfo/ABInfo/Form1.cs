using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;

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
                    
                    //for (int i = 0; i < len; i++)
                    //{
                    //    sbString.Append(data[i].ToString("X2") + " ");
                    //}
                     
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
                    string[] row = {strDateTime, ABinfoString.ToString()};
                    dgvData.Rows.Add(row);

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
            /*
            for (int i = 1; i < 80000; i++)
            {
                dgvData.Rows.Add("111", "222");
            }
             * */
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dgvData.ColumnCount = 2;
            dgvData.Columns[0].Name = "时间";
            dgvData.Columns[1].Name = "数据";

        }
        private void dgvData_RowStateChanged(object sender, DataGridViewRowStateChangedEventArgs e)
        {
            e.Row.HeaderCell.Value = string.Format("{0}", e.Row.Index + 1);
        }   
    }
}
