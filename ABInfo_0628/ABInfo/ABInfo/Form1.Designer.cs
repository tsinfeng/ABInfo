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
            this.buttonFirst = new System.Windows.Forms.Button();
            this.buttonFront = new System.Windows.Forms.Button();
            this.buttonNext = new System.Windows.Forms.Button();
            this.buttonTail = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxPage = new System.Windows.Forms.TextBox();
            this.buttonGo = new System.Windows.Forms.Button();
            this.buttonSave = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(69, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "AB机数据：";
            // 
            // btOpen
            // 
            this.btOpen.Location = new System.Drawing.Point(87, 4);
            this.btOpen.Name = "btOpen";
            this.btOpen.Size = new System.Drawing.Size(56, 23);
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
            this.listBoxABData.Location = new System.Drawing.Point(12, 35);
            this.listBoxABData.Name = "listBoxABData";
            this.listBoxABData.Size = new System.Drawing.Size(421, 693);
            this.listBoxABData.TabIndex = 3;
            this.listBoxABData.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.listBoxABData_DrawItem);
            this.listBoxABData.SelectedIndexChanged += new System.EventHandler(this.listBoxABData_SelectedIndexChanged);
            // 
            // tbText
            // 
            this.tbText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tbText.Location = new System.Drawing.Point(501, 36);
            this.tbText.Multiline = true;
            this.tbText.Name = "tbText";
            this.tbText.Size = new System.Drawing.Size(495, 693);
            this.tbText.TabIndex = 4;
            this.tbText.TextChanged += new System.EventHandler(this.tbText_TextChanged);
            // 
            // buttonFirst
            // 
            this.buttonFirst.Location = new System.Drawing.Point(435, 50);
            this.buttonFirst.Name = "buttonFirst";
            this.buttonFirst.Size = new System.Drawing.Size(65, 23);
            this.buttonFirst.TabIndex = 5;
            this.buttonFirst.Text = "首页";
            this.buttonFirst.UseVisualStyleBackColor = true;
            this.buttonFirst.Click += new System.EventHandler(this.buttonFirst_Click);
            // 
            // buttonFront
            // 
            this.buttonFront.Location = new System.Drawing.Point(435, 114);
            this.buttonFront.Name = "buttonFront";
            this.buttonFront.Size = new System.Drawing.Size(65, 23);
            this.buttonFront.TabIndex = 6;
            this.buttonFront.Text = "上一页";
            this.buttonFront.UseVisualStyleBackColor = true;
            this.buttonFront.Click += new System.EventHandler(this.buttonFront_Click);
            // 
            // buttonNext
            // 
            this.buttonNext.Location = new System.Drawing.Point(435, 178);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(65, 23);
            this.buttonNext.TabIndex = 7;
            this.buttonNext.Text = "下一页";
            this.buttonNext.UseVisualStyleBackColor = true;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // buttonTail
            // 
            this.buttonTail.Location = new System.Drawing.Point(435, 242);
            this.buttonTail.Name = "buttonTail";
            this.buttonTail.Size = new System.Drawing.Size(65, 23);
            this.buttonTail.TabIndex = 8;
            this.buttonTail.Text = "尾页";
            this.buttonTail.UseVisualStyleBackColor = true;
            this.buttonTail.Click += new System.EventHandler(this.buttonTail_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(177, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "共0页   第0页";
            // 
            // textBoxPage
            // 
            this.textBoxPage.Location = new System.Drawing.Point(275, 6);
            this.textBoxPage.Name = "textBoxPage";
            this.textBoxPage.Size = new System.Drawing.Size(35, 20);
            this.textBoxPage.TabIndex = 10;
            // 
            // buttonGo
            // 
            this.buttonGo.Location = new System.Drawing.Point(316, 4);
            this.buttonGo.Name = "buttonGo";
            this.buttonGo.Size = new System.Drawing.Size(33, 23);
            this.buttonGo.TabIndex = 11;
            this.buttonGo.Text = "Go";
            this.buttonGo.UseVisualStyleBackColor = true;
            this.buttonGo.Click += new System.EventHandler(this.buttonGo_Click);
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(435, 306);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(65, 23);
            this.buttonSave.TabIndex = 12;
            this.buttonSave.Text = "保存分析";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 730);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.buttonGo);
            this.Controls.Add(this.textBoxPage);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.buttonTail);
            this.Controls.Add(this.buttonNext);
            this.Controls.Add(this.buttonFront);
            this.Controls.Add(this.buttonFirst);
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
        private System.Windows.Forms.Button buttonFirst;
        private System.Windows.Forms.Button buttonFront;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Button buttonTail;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxPage;
        private System.Windows.Forms.Button buttonGo;
        private System.Windows.Forms.Button buttonSave;
    }
}

