namespace Lap_1
{
    partial class Form5
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form5));
            label1 = new Label();
            label2 = new Label();
            textNhap = new TextBox();
            button1 = new Button();
            listBox = new ListBox();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            texttb = new TextBox();
            textxl = new TextBox();
            textdiemcao = new TextBox();
            textdiemthap = new TextBox();
            textdau = new TextBox();
            textrot = new TextBox();
            buttonxoa = new Button();
            button2 = new Button();
            pictureBox1 = new PictureBox();
            button3 = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Times New Roman", 19.8000011F, FontStyle.Bold, GraphicsUnit.Point, 163);
            label1.Location = new Point(283, 29);
            label1.Name = "label1";
            label1.Size = new Size(285, 38);
            label1.TabIndex = 0;
            label1.Text = "Phần mềm quản lí";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Times New Roman", 12F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label2.Location = new Point(52, 110);
            label2.Name = "label2";
            label2.Size = new Size(135, 22);
            label2.TabIndex = 1;
            label2.Text = "Danh sách điểm";
            // 
            // textNhap
            // 
            textNhap.Location = new Point(193, 108);
            textNhap.Name = "textNhap";
            textNhap.Size = new Size(505, 27);
            textNhap.TabIndex = 2;
            // 
            // button1
            // 
            button1.Location = new Point(705, 198);
            button1.Name = "button1";
            button1.Size = new Size(83, 41);
            button1.TabIndex = 3;
            button1.Text = "Xuất";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // listBox
            // 
            listBox.BackColor = SystemColors.ButtonHighlight;
            listBox.FormattingEnabled = true;
            listBox.Location = new Point(52, 198);
            listBox.Name = "listBox";
            listBox.Size = new Size(360, 224);
            listBox.TabIndex = 4;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Times New Roman", 12F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label3.Location = new Point(52, 173);
            label3.Name = "label3";
            label3.Size = new Size(119, 22);
            label3.TabIndex = 1;
            label3.Text = "Môn và điểm ";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label4.Location = new Point(429, 198);
            label4.Name = "label4";
            label4.Size = new Size(127, 20);
            label4.TabIndex = 5;
            label4.Text = "Điểm trung bình";
            label4.Visible = false;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label5.Location = new Point(429, 238);
            label5.Name = "label5";
            label5.Size = new Size(127, 20);
            label5.TabIndex = 5;
            label5.Text = "Xếp loại học lực";
            label5.Visible = false;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label6.Location = new Point(429, 281);
            label6.Name = "label6";
            label6.Size = new Size(114, 20);
            label6.TabIndex = 5;
            label6.Text = "Điểm cao nhất";
            label6.Visible = false;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label7.Location = new Point(429, 323);
            label7.Name = "label7";
            label7.Size = new Size(120, 20);
            label7.TabIndex = 5;
            label7.Text = "Điểm thấp nhất";
            label7.Visible = false;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label8.Location = new Point(429, 362);
            label8.Name = "label8";
            label8.Size = new Size(96, 20);
            label8.TabIndex = 5;
            label8.Text = "Số môn đậu";
            label8.Visible = false;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            label9.Location = new Point(429, 402);
            label9.Name = "label9";
            label9.Size = new Size(91, 20);
            label9.TabIndex = 5;
            label9.Text = "Số môn rớt";
            label9.Visible = false;
            // 
            // texttb
            // 
            texttb.BackColor = SystemColors.ButtonHighlight;
            texttb.BorderStyle = BorderStyle.None;
            texttb.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            texttb.Location = new Point(562, 198);
            texttb.Name = "texttb";
            texttb.ReadOnly = true;
            texttb.Size = new Size(125, 21);
            texttb.TabIndex = 6;
            texttb.TabStop = false;
            // 
            // textxl
            // 
            textxl.BackColor = SystemColors.ButtonHighlight;
            textxl.BorderStyle = BorderStyle.None;
            textxl.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            textxl.Location = new Point(562, 238);
            textxl.Name = "textxl";
            textxl.ReadOnly = true;
            textxl.Size = new Size(125, 21);
            textxl.TabIndex = 6;
            textxl.TabStop = false;
            // 
            // textdiemcao
            // 
            textdiemcao.BackColor = SystemColors.ButtonHighlight;
            textdiemcao.BorderStyle = BorderStyle.None;
            textdiemcao.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            textdiemcao.Location = new Point(549, 281);
            textdiemcao.Name = "textdiemcao";
            textdiemcao.ReadOnly = true;
            textdiemcao.Size = new Size(125, 21);
            textdiemcao.TabIndex = 6;
            textdiemcao.TabStop = false;
            // 
            // textdiemthap
            // 
            textdiemthap.BackColor = SystemColors.ButtonHighlight;
            textdiemthap.BorderStyle = BorderStyle.None;
            textdiemthap.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            textdiemthap.Location = new Point(555, 323);
            textdiemthap.Name = "textdiemthap";
            textdiemthap.ReadOnly = true;
            textdiemthap.Size = new Size(125, 21);
            textdiemthap.TabIndex = 6;
            textdiemthap.TabStop = false;
            // 
            // textdau
            // 
            textdau.BackColor = SystemColors.ButtonHighlight;
            textdau.BorderStyle = BorderStyle.None;
            textdau.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            textdau.Location = new Point(531, 362);
            textdau.Name = "textdau";
            textdau.ReadOnly = true;
            textdau.Size = new Size(125, 21);
            textdau.TabIndex = 6;
            textdau.TabStop = false;
            // 
            // textrot
            // 
            textrot.BackColor = SystemColors.ButtonHighlight;
            textrot.BorderStyle = BorderStyle.None;
            textrot.Font = new Font("Times New Roman", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 163);
            textrot.Location = new Point(526, 402);
            textrot.Name = "textrot";
            textrot.ReadOnly = true;
            textrot.Size = new Size(125, 21);
            textrot.TabIndex = 6;
            textrot.TabStop = false;
            // 
            // buttonxoa
            // 
            buttonxoa.Location = new Point(705, 260);
            buttonxoa.Name = "buttonxoa";
            buttonxoa.Size = new Size(83, 41);
            buttonxoa.TabIndex = 7;
            buttonxoa.Text = "Xóa";
            buttonxoa.UseVisualStyleBackColor = true;
            buttonxoa.Click += buttonxoa_Click;
            // 
            // button2
            // 
            button2.Location = new Point(705, 381);
            button2.Name = "button2";
            button2.Size = new Size(83, 41);
            button2.TabIndex = 7;
            button2.Text = "Thoát";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.Cursor = Cursors.Hand;
            pictureBox1.Image = (Image)resources.GetObject("pictureBox1.Image");
            pictureBox1.Location = new Point(664, 107);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(34, 28);
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox1.TabIndex = 8;
            pictureBox1.TabStop = false;
            pictureBox1.Click += pictureBox1_Click;
            // 
            // button3
            // 
            button3.Location = new Point(705, 323);
            button3.Name = "button3";
            button3.Size = new Size(83, 41);
            button3.TabIndex = 7;
            button3.Text = "Quay lại";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // Form5
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ButtonHighlight;
            ClientSize = new Size(800, 450);
            Controls.Add(pictureBox1);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(buttonxoa);
            Controls.Add(textrot);
            Controls.Add(textdau);
            Controls.Add(textdiemthap);
            Controls.Add(textdiemcao);
            Controls.Add(textxl);
            Controls.Add(texttb);
            Controls.Add(label9);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(listBox);
            Controls.Add(button1);
            Controls.Add(textNhap);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form5";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Bài 5";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private TextBox textNhap;
        private Button button1;
        private ListBox listBox;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Label label7;
        private Label label8;
        private Label label9;
        private TextBox texttb;
        private TextBox textxl;
        private TextBox textdiemcao;
        private TextBox textdiemthap;
        private TextBox textdau;
        private TextBox textrot;
        private Button buttonxoa;
        private Button button2;
        private PictureBox pictureBox1;
        private Button button3;
    }
}