namespace Lab2_23520580_TranThanhHung
{
    partial class Cau2
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
            OpenFile = new Button();
            richTextBox1 = new RichTextBox();
            label1 = new Label();
            FileName = new TextBox();
            Url = new TextBox();
            label2 = new Label();
            Words = new TextBox();
            label3 = new Label();
            Lines = new TextBox();
            label4 = new Label();
            Char = new TextBox();
            label5 = new Label();
            SuspendLayout();
            // 
            // OpenFile
            // 
            OpenFile.Location = new Point(29, 21);
            OpenFile.Name = "OpenFile";
            OpenFile.Size = new Size(150, 47);
            OpenFile.TabIndex = 0;
            OpenFile.Text = "Chọn file";
            OpenFile.UseVisualStyleBackColor = true;
            OpenFile.Click += OpenFile_Click;
            // 
            // richTextBox1
            // 
            richTextBox1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            richTextBox1.Location = new Point(214, 21);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(560, 402);
            richTextBox1.TabIndex = 1;
            richTextBox1.Text = "";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(29, 86);
            label1.Name = "label1";
            label1.Size = new Size(44, 15);
            label1.TabIndex = 2;
            label1.Text = "Tên file";
            // 
            // FileName
            // 
            FileName.Location = new Point(79, 83);
            FileName.Name = "FileName";
            FileName.Size = new Size(100, 23);
            FileName.TabIndex = 3;
            // 
            // Url
            // 
            Url.Location = new Point(79, 124);
            Url.Name = "Url";
            Url.Size = new Size(100, 23);
            Url.TabIndex = 5;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(29, 127);
            label2.Name = "label2";
            label2.Size = new Size(22, 15);
            label2.TabIndex = 4;
            label2.Text = "Url";
            // 
            // Words
            // 
            Words.Location = new Point(79, 204);
            Words.Name = "Words";
            Words.Size = new Size(100, 23);
            Words.TabIndex = 9;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(29, 207);
            label3.Name = "label3";
            label3.Size = new Size(34, 15);
            label3.TabIndex = 8;
            label3.Text = "Số từ";
            // 
            // Lines
            // 
            Lines.Location = new Point(79, 163);
            Lines.Name = "Lines";
            Lines.Size = new Size(100, 23);
            Lines.TabIndex = 7;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(29, 166);
            label4.Name = "label4";
            label4.Size = new Size(51, 15);
            label4.TabIndex = 6;
            label4.Text = "Số dòng";
            // 
            // Char
            // 
            Char.Location = new Point(79, 251);
            Char.Name = "Char";
            Char.Size = new Size(100, 23);
            Char.TabIndex = 11;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(29, 254);
            label5.Name = "label5";
            label5.Size = new Size(49, 15);
            label5.TabIndex = 10;
            label5.Text = "Số ký tự";
            // 
            // Cau2
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(Char);
            Controls.Add(label5);
            Controls.Add(Words);
            Controls.Add(label3);
            Controls.Add(Lines);
            Controls.Add(label4);
            Controls.Add(Url);
            Controls.Add(label2);
            Controls.Add(FileName);
            Controls.Add(label1);
            Controls.Add(richTextBox1);
            Controls.Add(OpenFile);
            Name = "Cau2";
            Text = "Cau2";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button OpenFile;
        private RichTextBox richTextBox1;
        private Label label1;
        private TextBox FileName;
        private TextBox Url;
        private Label label2;
        private TextBox Words;
        private Label label3;
        private TextBox Lines;
        private Label label4;
        private TextBox Char;
        private Label label5;
    }
}