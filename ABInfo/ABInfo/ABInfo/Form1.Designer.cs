namespace ABInfo
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.btOpen = new System.Windows.Forms.Button();
            this.listBoxABData = new System.Windows.Forms.ListBox();
            this.tbText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "AB机数据：";
            // 
            // btOpen
            // 
            this.btOpen.Location = new System.Drawing.Point(439, 32);
            this.btOpen.Name = "btOpen";
            this.btOpen.Size = new System.Drawing.Size(56, 21);
            this.btOpen.TabIndex = 2;
            this.btOpen.Text = "打开(&O)";
            this.btOpen.UseVisualStyleBackColor = true;
            this.btOpen.Click += new System.EventHandler(this.btOpen_Click);
            // 
            // listBoxABData
            // 
            this.listBoxABData.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.listBoxABData.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed;
            this.listBoxABData.FormattingEnabled = true;
            this.listBoxABData.Location = new System.Drawing.Point(12, 32);
            this.listBoxABData.Name = "listBoxABData";
            this.listBoxABData.Size = new System.Drawing.Size(421, 641);
            this.listBoxABData.TabIndex = 3;
            this.listBoxABData.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.listBoxABData_DrawItem);
            this.listBoxABData.SelectedIndexChanged += new System.EventHandler(this.listBoxABData_SelectedIndexChanged);
            // 
            // tbText
            // 
            this.tbText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tbText.Location = new System.Drawing.Point(501, 33);
            this.tbText.Multiline = true;
            this.tbText.Name = "tbText";
            this.tbText.Size = new System.Drawing.Size(495, 640);
            this.tbText.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 674);
            this.Controls.Add(this.tbText);
            this.Controls.Add(this.listBoxABData);
            this.Controls.Add(this.btOpen);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "AB机信息数据解析";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btOpen;
        private System.Windows.Forms.ListBox listBoxABData;
        private System.Windows.Forms.TextBox tbText;
    }
}

