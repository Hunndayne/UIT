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
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(368, 142);
            label1.Name = "label1";
            label1.Size = new Size(0, 15);
            label1.TabIndex = 0;
            // 
            // TitleCal
            // 
            TitleCal.Font = new Font("Calibri", 48F, FontStyle.Italic, GraphicsUnit.Point, 0);
            TitleCal.ForeColor = Color.Red;
            TitleCal.Location = new Point(12, 9);
            TitleCal.Name = "TitleCal";
            TitleCal.Size = new Size(328, 96);
            TitleCal.TabIndex = 1;
            TitleCal.Text = "Tính toán";
            // 
            // Num1
            // 
            Num1.Location = new Point(132, 108);
            Num1.Name = "Num1";
            Num1.Size = new Size(111, 23);
            Num1.TabIndex = 2;
            Num1.TextChanged += Num1_TextChanged;
            // 
            // Num2
            // 
            Num2.Location = new Point(132, 139);
            Num2.Name = "Num2";
            Num2.Size = new Size(111, 23);
            Num2.TabIndex = 3;
            Num2.TextChanged += Num2_TextChanged;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(132, 171);
            textBox1.Name = "textBox1";
            textBox1.ReadOnly = true;
            textBox1.Size = new Size(111, 23);
            textBox1.TabIndex = 4;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label2.Location = new Point(33, 105);
            label2.Name = "label2";
            label2.Size = new Size(76, 23);
            label2.TabIndex = 5;
            label2.Text = "Số thứ 1";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label3.Location = new Point(33, 139);
            label3.Name = "label3";
            label3.Size = new Size(76, 23);
            label3.TabIndex = 6;
            label3.Text = "Số thứ 2";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Calibri", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label4.Location = new Point(33, 165);
            label4.Name = "label4";
            label4.Size = new Size(70, 23);
            label4.TabIndex = 7;
            label4.Text = "Kết quả";
            // 
            // Plus
            // 
            Plus.BackColor = Color.Red;
            Plus.Location = new Point(33, 210);
            Plus.Name = "Plus";
            Plus.Size = new Size(34, 23);
            Plus.TabIndex = 8;
            Plus.Text = "+";
            Plus.UseVisualStyleBackColor = false;
            Plus.Click += button1_Click;
            // 
            // Subtract
            // 
            Subtract.BackColor = Color.Red;
            Subtract.Location = new Point(92, 210);
            Subtract.Name = "Subtract";
            Subtract.Size = new Size(34, 23);
            Subtract.TabIndex = 9;
            Subtract.Text = "-";
            Subtract.UseVisualStyleBackColor = false;
            Subtract.Click += Subtract_Click;
            // 
            // Time
            // 
            Time.BackColor = Color.Red;
            Time.Location = new Point(149, 210);
            Time.Name = "Time";
            Time.Size = new Size(34, 23);
            Time.TabIndex = 10;
            Time.Text = "x";
            Time.UseVisualStyleBackColor = false;
            Time.Click += Time_Click;
            // 
            // Divide
            // 
            Divide.BackColor = Color.Red;
            Divide.Location = new Point(209, 210);
            Divide.Name = "Divide";
            Divide.Size = new Size(34, 23);
            Divide.TabIndex = 11;
            Divide.Text = "/";
            Divide.UseVisualStyleBackColor = false;
            Divide.Click += Divide_Click;
            // 
            // Delete
            // 
            Delete.BackColor = SystemColors.Highlight;
            Delete.Location = new Point(33, 253);
            Delete.Name = "Delete";
            Delete.Size = new Size(75, 23);
            Delete.TabIndex = 12;
            Delete.Text = "Xóa";
            Delete.UseVisualStyleBackColor = false;
            Delete.Click += Delete_Click;
            // 
            // Thoát
            // 
            Thoát.BackColor = Color.Red;
            Thoát.Location = new Point(168, 253);
            Thoát.Name = "Thoát";
            Thoát.Size = new Size(75, 23);
            Thoát.TabIndex = 13;
            Thoát.Text = "Thoát";
            Thoát.UseVisualStyleBackColor = false;
            Thoát.Click += Thoát_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Green;
            ClientSize = new Size(303, 318);
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
            Controls.Add(TitleCal);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
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
    }
}
