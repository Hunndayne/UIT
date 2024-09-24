namespace Lab1_23520580_TranThanhHung
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            TitleCal = new Label();
            Num1 = new TextBox();
            Num2 = new TextBox();
            textBox1 = new TextBox();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            Plus = new Button();
            Subtract = new Button();
            Time = new Button();
            Divide = new Button();
            Delete = new Button();
            Thoát = new Button();
            button100 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(421, 189);
            label1.Name = "label1";
            label1.Size = new Size(0, 20);
            label1.TabIndex = 0;
            // 
            // TitleCal
            // 
            TitleCal.Font = new Font("Calibri", 48F, FontStyle.Italic, GraphicsUnit.Point, 0);
            TitleCal.ForeColor = Color.Red;
            TitleCal.Location = new Point(14, 12);
            TitleCal.Name = "TitleCal";
            TitleCal.Size = new Size(375, 128);
            TitleCal.TabIndex = 1;
            TitleCal.Text = "Tính toán";
            // 
            // Num1
            // 
            Num1.Location = new Point(151, 144);
            Num1.Margin = new Padding(3, 4, 3, 4);
            Num1.Name = "Num1";
            Num1.Size = new Size(126, 27);
            Num1.TabIndex = 2;
            Num1.TextChanged += Num1_TextChanged;
            // 
            // Num2
            // 
            Num2.Location = new Point(151, 185);
            Num2.Margin = new Padding(3, 4, 3, 4);
            Num2.Name = "Num2";
            Num2.Size = new Size(126, 27);
            Num2.TabIndex = 3;
            Num2.TextChanged += Num2_TextChanged;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(151, 228);
            textBox1.Margin = new Padding(3, 4, 3, 4);
            textBox1.Name = "textBox1";
            textBox1.ReadOnly = true;
            textBox1.Size = new Size(126, 27);
            textBox1.TabIndex = 4;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label2.Location = new Point(38, 140);
            label2.Name = "label2";
            label2.Size = new Size(96, 29);
            label2.TabIndex = 5;
            label2.Text = "Số thứ 1";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label3.Location = new Point(38, 185);
            label3.Name = "label3";
            label3.Size = new Size(96, 29);
            label3.TabIndex = 6;
            label3.Text = "Số thứ 2";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label4.Location = new Point(38, 220);
            label4.Name = "label4";
            label4.Size = new Size(89, 29);
            label4.TabIndex = 7;
            label4.Text = "Kết quả";
            // 
            // Plus
            // 
            Plus.BackColor = Color.Red;
            Plus.Location = new Point(38, 280);
            Plus.Margin = new Padding(3, 4, 3, 4);
            Plus.Name = "Plus";
            Plus.Size = new Size(39, 31);
            Plus.TabIndex = 8;
            Plus.Text = "+";
            Plus.UseVisualStyleBackColor = false;
            Plus.Click += button1_Click;
            // 
            // Subtract
            // 
            Subtract.BackColor = Color.Red;
            Subtract.Location = new Point(105, 280);
            Subtract.Margin = new Padding(3, 4, 3, 4);
            Subtract.Name = "Subtract";
            Subtract.Size = new Size(39, 31);
            Subtract.TabIndex = 9;
            Subtract.Text = "-";
            Subtract.UseVisualStyleBackColor = false;
            Subtract.Click += Subtract_Click;
            // 
            // Time
            // 
            Time.BackColor = Color.Red;
            Time.Location = new Point(170, 280);
            Time.Margin = new Padding(3, 4, 3, 4);
            Time.Name = "Time";
            Time.Size = new Size(39, 31);
            Time.TabIndex = 10;
            Time.Text = "x";
            Time.UseVisualStyleBackColor = false;
            Time.Click += Time_Click;
            // 
            // Divide
            // 
            Divide.BackColor = Color.Red;
            Divide.Location = new Point(239, 280);
            Divide.Margin = new Padding(3, 4, 3, 4);
            Divide.Name = "Divide";
            Divide.Size = new Size(39, 31);
            Divide.TabIndex = 11;
            Divide.Text = "/";
            Divide.UseVisualStyleBackColor = false;
            Divide.Click += Divide_Click;
            // 
            // Delete
            // 
            Delete.BackColor = SystemColors.Highlight;
            Delete.Location = new Point(26, 337);
            Delete.Margin = new Padding(3, 4, 3, 4);
            Delete.Name = "Delete";
            Delete.Size = new Size(86, 31);
            Delete.TabIndex = 12;
            Delete.Text = "Xóa";
            Delete.UseVisualStyleBackColor = false;
            Delete.Click += Delete_Click;
            // 
            // Thoát
            // 
            Thoát.BackColor = Color.Red;
            Thoát.Location = new Point(132, 337);
            Thoát.Margin = new Padding(3, 4, 3, 4);
            Thoát.Name = "Thoát";
            Thoát.Size = new Size(86, 31);
            Thoát.TabIndex = 13;
            Thoát.Text = "Thoát";
            Thoát.UseVisualStyleBackColor = false;
            Thoát.Click += Thoát_Click;
            // 
            // button100
            // 
            button100.Location = new Point(239, 339);
            button100.Name = "button100";
            button100.Size = new Size(86, 29);
            button100.TabIndex = 14;
            button100.Text = "Quay lại";
            button100.UseVisualStyleBackColor = true;
            button100.Click += button100_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Green;
            ClientSize = new Size(346, 424);
            Controls.Add(button100);
            Controls.Add(Thoát);
            Controls.Add(Delete);
            Controls.Add(Divide);
            Controls.Add(Time);
            Controls.Add(Subtract);
            Controls.Add(Plus);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(textBox1);
            Controls.Add(Num2);
            Controls.Add(Num1);
            Controls.Add(label1);
            Controls.Add(TitleCal);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Bài 1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label TitleCal;
        private TextBox Num1;
        private TextBox Num2;
        private TextBox textBox1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button Plus;
        private Button Subtract;
        private Button Time;
        private Button Divide;
        private Button Delete;
        private Button Thoát;
        private Button button100;
    }
}
