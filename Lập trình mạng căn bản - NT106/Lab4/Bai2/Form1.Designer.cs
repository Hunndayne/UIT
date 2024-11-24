namespace Bai2
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
            URL = new TextBox();
            Search = new Button();
            comboBox1 = new ComboBox();
            label1 = new Label();
            comboBox2 = new ComboBox();
            label2 = new Label();
            richTextBox1 = new RichTextBox();
            Clear = new Button();
            label3 = new Label();
            label4 = new Label();
            SuspendLayout();
            // 
            // URL
            // 
            URL.Location = new Point(41, 23);
            URL.Name = "URL";
            URL.Size = new Size(617, 23);
            URL.TabIndex = 0;
            // 
            // Search
            // 
            Search.Location = new Point(675, 23);
            Search.Name = "Search";
            Search.Size = new Size(75, 23);
            Search.TabIndex = 1;
            Search.Text = "Search";
            Search.UseVisualStyleBackColor = true;
            Search.Click += Search_Click;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(278, 52);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(380, 23);
            comboBox1.TabIndex = 5;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(207, 60);
            label1.Name = "label1";
            label1.Size = new Size(65, 15);
            label1.TabIndex = 6;
            label1.Text = "User Agent";
            // 
            // comboBox2
            // 
            comboBox2.FormattingEnabled = true;
            comboBox2.Location = new Point(278, 81);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(380, 23);
            comboBox2.TabIndex = 7;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(207, 89);
            label2.Name = "label2";
            label2.Size = new Size(63, 15);
            label2.TabIndex = 8;
            label2.Text = "Resolution";
            // 
            // richTextBox1
            // 
            richTextBox1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            richTextBox1.Location = new Point(50, 124);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(738, 120);
            richTextBox1.TabIndex = 9;
            richTextBox1.Text = "";
            // 
            // Clear
            // 
            Clear.Location = new Point(675, 56);
            Clear.Name = "Clear";
            Clear.Size = new Size(75, 23);
            Clear.TabIndex = 10;
            Clear.Text = "Clear";
            Clear.UseVisualStyleBackColor = true;
            Clear.Click += Clear_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(50, 106);
            label3.Name = "label3";
            label3.Size = new Size(67, 15);
            label3.TabIndex = 11;
            label3.Text = "RAW HTML";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(50, 247);
            label4.Name = "label4";
            label4.Size = new Size(85, 15);
            label4.TabIndex = 12;
            label4.Text = "RENDER HTML";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 584);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(Clear);
            Controls.Add(richTextBox1);
            Controls.Add(label2);
            Controls.Add(comboBox2);
            Controls.Add(label1);
            Controls.Add(comboBox1);
            Controls.Add(Search);
            Controls.Add(URL);
            Name = "Form1";
            Text = " ";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox URL;
        private Button Search;
        private ComboBox comboBox1;
        private Label label1;
        private ComboBox comboBox2;
        private Label label2;
        private RichTextBox richTextBox1;
        private Button Clear;
        private Label label3;
        private Label label4;
    }
}
