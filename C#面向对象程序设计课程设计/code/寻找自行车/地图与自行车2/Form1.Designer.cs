namespace 寻找自行车
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
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.comboBox1_stationID = new System.Windows.Forms.ComboBox();
            this.comboBox2_stationID = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox2_stationName = new System.Windows.Forms.TextBox();
            this.textBox1_stationName = new System.Windows.Forms.TextBox();
            this.textBox2_DockNum = new System.Windows.Forms.TextBox();
            this.textBox1_DockNum = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.textBox2_service = new System.Windows.Forms.TextBox();
            this.textBox1_service = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(1, 1);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(385, 776);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1147, 48);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(65, 31);
            this.button1.TabIndex = 1;
            this.button1.Text = "搜索";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(390, 205);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "在服务车位";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(399, 59);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "起始站点ID";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // comboBox1_stationID
            // 
            this.comboBox1_stationID.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.comboBox1_stationID.FormattingEnabled = true;
            this.comboBox1_stationID.Location = new System.Drawing.Point(510, 59);
            this.comboBox1_stationID.Margin = new System.Windows.Forms.Padding(2);
            this.comboBox1_stationID.Name = "comboBox1_stationID";
            this.comboBox1_stationID.Size = new System.Drawing.Size(153, 23);
            this.comboBox1_stationID.TabIndex = 4;
            this.comboBox1_stationID.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // comboBox2_stationID
            // 
            this.comboBox2_stationID.FormattingEnabled = true;
            this.comboBox2_stationID.Location = new System.Drawing.Point(955, 56);
            this.comboBox2_stationID.Margin = new System.Windows.Forms.Padding(2);
            this.comboBox2_stationID.Name = "comboBox2_stationID";
            this.comboBox2_stationID.Size = new System.Drawing.Size(149, 23);
            this.comboBox2_stationID.TabIndex = 5;
            this.comboBox2_stationID.SelectedIndexChanged += new System.EventHandler(this.comboBox2_stationID_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(820, 62);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(83, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "终点站点ID";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // textBox2_stationName
            // 
            this.textBox2_stationName.Location = new System.Drawing.Point(510, 105);
            this.textBox2_stationName.Margin = new System.Windows.Forms.Padding(2);
            this.textBox2_stationName.Name = "textBox2_stationName";
            this.textBox2_stationName.Size = new System.Drawing.Size(153, 25);
            this.textBox2_stationName.TabIndex = 7;
            this.textBox2_stationName.TextChanged += new System.EventHandler(this.textBox2_stationName_TextChanged);
            // 
            // textBox1_stationName
            // 
            this.textBox1_stationName.Location = new System.Drawing.Point(955, 108);
            this.textBox1_stationName.Margin = new System.Windows.Forms.Padding(2);
            this.textBox1_stationName.Name = "textBox1_stationName";
            this.textBox1_stationName.Size = new System.Drawing.Size(149, 25);
            this.textBox1_stationName.TabIndex = 7;
            this.textBox1_stationName.TextChanged += new System.EventHandler(this.textBox1_stationName_TextChanged);
            // 
            // textBox2_DockNum
            // 
            this.textBox2_DockNum.Location = new System.Drawing.Point(510, 154);
            this.textBox2_DockNum.Margin = new System.Windows.Forms.Padding(2);
            this.textBox2_DockNum.Name = "textBox2_DockNum";
            this.textBox2_DockNum.Size = new System.Drawing.Size(153, 25);
            this.textBox2_DockNum.TabIndex = 7;
            // 
            // textBox1_DockNum
            // 
            this.textBox1_DockNum.Location = new System.Drawing.Point(955, 158);
            this.textBox1_DockNum.Margin = new System.Windows.Forms.Padding(2);
            this.textBox1_DockNum.Name = "textBox1_DockNum";
            this.textBox1_DockNum.Size = new System.Drawing.Size(149, 25);
            this.textBox1_DockNum.TabIndex = 7;
            this.textBox1_DockNum.TextChanged += new System.EventHandler(this.textBox5_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(399, 111);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(82, 15);
            this.label5.TabIndex = 8;
            this.label5.Text = "起始站点名";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(821, 115);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(82, 15);
            this.label6.TabIndex = 8;
            this.label6.Text = "终点站点名";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(394, 158);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(112, 15);
            this.label7.TabIndex = 8;
            this.label7.Text = "起始站点总车位";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(821, 161);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(112, 15);
            this.label8.TabIndex = 8;
            this.label8.Text = "终点站点总车位";
            // 
            // textBox2_service
            // 
            this.textBox2_service.Location = new System.Drawing.Point(510, 198);
            this.textBox2_service.Margin = new System.Windows.Forms.Padding(2);
            this.textBox2_service.Name = "textBox2_service";
            this.textBox2_service.Size = new System.Drawing.Size(157, 25);
            this.textBox2_service.TabIndex = 7;
            // 
            // textBox1_service
            // 
            this.textBox1_service.Location = new System.Drawing.Point(955, 202);
            this.textBox1_service.Margin = new System.Windows.Forms.Padding(2);
            this.textBox1_service.Name = "textBox1_service";
            this.textBox1_service.Size = new System.Drawing.Size(149, 25);
            this.textBox1_service.TabIndex = 7;
            this.textBox1_service.TextChanged += new System.EventHandler(this.textBox5_TextChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(821, 202);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(82, 15);
            this.label9.TabIndex = 8;
            this.label9.Text = "在服务车位";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(680, 53);
            this.button2.Margin = new System.Windows.Forms.Padding(2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(72, 32);
            this.button2.TabIndex = 9;
            this.button2.Text = "搜索";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(680, 202);
            this.button3.Margin = new System.Windows.Forms.Padding(2);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(89, 28);
            this.button3.TabIndex = 10;
            this.button3.Text = "重置";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(1119, 202);
            this.button4.Margin = new System.Windows.Forms.Padding(2);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(93, 28);
            this.button4.TabIndex = 11;
            this.button4.Text = "重置";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(1119, 729);
            this.button6.Margin = new System.Windows.Forms.Padding(2);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(132, 48);
            this.button6.TabIndex = 13;
            this.button6.Text = "清空地图上所有站点";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(387, 736);
            this.button5.Margin = new System.Windows.Forms.Padding(2);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(131, 41);
            this.button5.TabIndex = 14;
            this.button5.Text = "显示地图上所有站点";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click_1);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(703, 732);
            this.button7.Margin = new System.Windows.Forms.Padding(2);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(139, 48);
            this.button7.TabIndex = 15;
            this.button7.Text = "规划路线";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(387, 228);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1050, 484);
            this.panel1.TabIndex = 17;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(1432, 780);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBox1_service);
            this.Controls.Add(this.textBox1_DockNum);
            this.Controls.Add(this.textBox2_service);
            this.Controls.Add(this.textBox2_DockNum);
            this.Controls.Add(this.textBox1_stationName);
            this.Controls.Add(this.textBox2_stationName);
            this.Controls.Add(this.comboBox2_stationID);
            this.Controls.Add(this.comboBox1_stationID);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBox1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Station";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBox1_stationID;
        private System.Windows.Forms.ComboBox comboBox2_stationID;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox2_stationName;
        private System.Windows.Forms.TextBox textBox1_stationName;
        private System.Windows.Forms.TextBox textBox2_DockNum;
        private System.Windows.Forms.TextBox textBox1_DockNum;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox textBox2_service;
        private System.Windows.Forms.TextBox textBox1_service;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Panel panel1;
    }
}

