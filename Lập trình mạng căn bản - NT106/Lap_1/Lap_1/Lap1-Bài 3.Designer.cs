namespace Lab1_23520580_TranThanhHung
{
    partial class Form3
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
            label1 = new Label();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            Read = new Button();
            Delete = new Button();
            Exit = new Button();
            label2 = new Label();
            label3 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom;
            label1.AutoSize = true;
            label1.Font = new Font("Calibri", 36F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point, 0);
            label1.Location = new Point(233, 47);
            label1.Name = "label1";
            label1.Size = new Size(197, 73);
            label1.TabIndex = 0;
            label1.Text = "Đọc số";
            // 
            // textBox1
            // 
            textBox1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            textBox1.Location = new Point(246, 187);
            textBox1.Margin = new Padding(3, 4, 3, 4);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(194, 27);
            textBox1.TabIndex = 1;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // textBox2
            // 
            textBox2.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            textBox2.Location = new Point(246, 240);
            textBox2.Margin = new Padding(3, 4, 3, 4);
            textBox2.Name = "textBox2";
            textBox2.ReadOnly = true;
            textBox2.Size = new Size(194, 27);
            textBox2.TabIndex = 2;
            // 
            // Read
            // 
            Read.Location = new Point(169, 299);
            Read.Margin = new Padding(3, 4, 3, 4);
            Read.Name = "Read";
            Read.Size = new Size(86, 31);
            Read.TabIndex = 3;
            Read.Text = "Đọc";
            Read.UseVisualStyleBackColor = true;
            Read.Click += Read_Click;
            // 
            // Delete
            // 
            Delete.Location = new Point(262, 299);
            Delete.Margin = new Padding(3, 4, 3, 4);
            Delete.Name = "Delete";
            Delete.Size = new Size(86, 31);
            Delete.TabIndex = 4;
            Delete.Text = "Xóa";
            Delete.UseVisualStyleBackColor = true;
            Delete.Click += Delete_Click;
            // 
            // Exit
            // 
            Exit.Location = new Point(354, 299);
            Exit.Margin = new Padding(3, 4, 3, 4);
            Exit.Name = "Exit";
            Exit.Size = new Size(86, 31);
            Exit.TabIndex = 5;
            Exit.Text = "Thoát";
            Exit.UseVisualStyleBackColor = true;
            Exit.Click += Exit_Click;
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            label2.AutoSize = true;
            label2.Location = new Point(169, 191);
            label2.Name = "label2";
            label2.Size = new Size(54, 20);
            label2.TabIndex = 6;
            label2.Text = "Số vào";
            label2.Click += label2_Click;
            // 
            // label3
            // 
            label3.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            label3.AutoSize = true;
            label3.Location = new Point(169, 251);
            label3.Name = "label3";
            label3.Size = new Size(52, 20);
            label3.TabIndex = 7;
            label3.Text = "Chữ ra";
            // 
            // button1
            // 
            button1.Location = new Point(446, 299);
            button1.Name = "button1";
            button1.Size = new Size(86, 29);
            button1.TabIndex = 8;
            button1.Text = "Quay lại";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button100_Click;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(627, 420);
            Controls.Add(button1);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(Exit);
            Controls.Add(Delete);
            Controls.Add(Read);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form3";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Bài 3";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox textBox1;
        private TextBox textBox2;
        private Button Read;
        private Button Delete;
        private Button Exit;
        private Label label2;
        private Label label3;
        private Button button1;
    }
}