namespace Lap_1
{
    partial class Form4
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            pictureBox1 = new PictureBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            textNhap = new TextBox();
            comboBox1 = new ComboBox();
            comboBox2 = new ComboBox();
            label4 = new Label();
            button1 = new Button();
            label5 = new Label();
            textkq = new TextBox();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // pictureBox1
            // 
            pictureBox1.BorderStyle = BorderStyle.FixedSingle;
            pictureBox1.Location = new Point(72, 69);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(636, 213);
            pictureBox1.TabIndex = 0;
            pictureBox1.TabStop = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(84, 58);
            label1.Name = "label1";
            label1.Size = new Size(109, 20);
            label1.TabIndex = 1;
            label1.Text = "Nhập thông tin";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(142, 137);
            label2.Name = "label2";
            label2.Size = new Size(76, 20);
            label2.TabIndex = 2;
            label2.Text = "Nhập 1 số";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(175, 170);
            label3.Name = "label3";
            label3.Size = new Size(43, 20);
            label3.TabIndex = 2;
            label3.Text = "Chọn";
            // 
            // textNhap
            // 
            textNhap.Location = new Point(275, 134);
            textNhap.Name = "textNhap";
            textNhap.Size = new Size(344, 27);
            textNhap.TabIndex = 3;
            textNhap.TabStop = false;
            // 
            // comboBox1
            // 
            comboBox1.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBox1.FormattingEnabled = true;
            comboBox1.ImeMode = ImeMode.NoControl;
            comboBox1.Items.AddRange(new object[] { "Bin", "Dec", "Hex" });
            comboBox1.Location = new Point(275, 167);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(126, 28);
            comboBox1.TabIndex = 4;
            comboBox1.TabStop = false;
            // 
            // comboBox2
            // 
            comboBox2.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBox2.FormattingEnabled = true;
            comboBox2.Items.AddRange(new object[] { "Bin", "Dec", "Hex" });
            comboBox2.Location = new Point(493, 167);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(126, 28);
            comboBox2.TabIndex = 4;
            comboBox2.TabStop = false;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(419, 170);
            label4.Name = "label4";
            label4.Size = new Size(42, 20);
            label4.TabIndex = 2;
            label4.Text = "Sang";
            // 
            // button1
            // 
            button1.BackColor = Color.Black;
            button1.ForeColor = SystemColors.ButtonHighlight;
            button1.Location = new Point(275, 201);
            button1.Name = "button1";
            button1.Size = new Size(344, 45);
            button1.TabIndex = 5;
            button1.Text = "Phân tích";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(142, 310);
            label5.Name = "label5";
            label5.Size = new Size(63, 20);
            label5.TabIndex = 1;
            label5.Text = "Kết quả:";
            // 
            // textkq
            // 
            textkq.BorderStyle = BorderStyle.FixedSingle;
            textkq.Enabled = false;
            textkq.Location = new Point(275, 308);
            textkq.Name = "textkq";
            textkq.ReadOnly = true;
            textkq.Size = new Size(344, 27);
            textkq.TabIndex = 3;
            textkq.TabStop = false;
            // 
            // button2
            // 
            button2.Location = new Point(126, 201);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 6;
            button2.Text = "Xóa";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(126, 236);
            button3.Name = "button3";
            button3.Size = new Size(94, 29);
            button3.TabIndex = 6;
            button3.Text = "Thoát";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Location = new Point(625, 305);
            button4.Name = "button4";
            button4.Size = new Size(83, 30);
            button4.TabIndex = 7;
            button4.Text = "Quay lại";
            button4.UseVisualStyleBackColor = true;
            button4.Click += this.button4_Click;
            // 
            // Form4
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(comboBox2);
            Controls.Add(comboBox1);
            Controls.Add(textkq);
            Controls.Add(textNhap);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label5);
            Controls.Add(label1);
            Controls.Add(pictureBox1);
            Name = "Form4";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Bài 4";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox pictureBox1;
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox textNhap;
        private ComboBox comboBox1;
        private ComboBox comboBox2;
        private Label label4;
        private Button button1;
        private Label label5;
        private TextBox textkq;
        private Button button2;
        private Button button3;
        private Button button4;
    }
}