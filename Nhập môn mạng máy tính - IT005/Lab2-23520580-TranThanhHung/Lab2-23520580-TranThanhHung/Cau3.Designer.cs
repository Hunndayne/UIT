namespace Lab2_23520580_TranThanhHung
{
    partial class Cau3
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
            In = new Button();
            Cal = new Button();
            Ex = new Button();
            InText = new RichTextBox();
            OutText = new RichTextBox();
            SuspendLayout();
            // 
            // In
            // 
            In.Location = new Point(43, 70);
            In.Name = "In";
            In.Size = new Size(75, 23);
            In.TabIndex = 0;
            In.Text = "Đọc";
            In.UseVisualStyleBackColor = true;
            In.Click += In_Click;
            // 
            // Cal
            // 
            Cal.Location = new Point(354, 70);
            Cal.Name = "Cal";
            Cal.Size = new Size(75, 23);
            Cal.TabIndex = 1;
            Cal.Text = "Tính";
            Cal.UseVisualStyleBackColor = true;
            Cal.Click += Cal_Click;
            // 
            // Ex
            // 
            Ex.Location = new Point(664, 70);
            Ex.Name = "Ex";
            Ex.Size = new Size(75, 23);
            Ex.TabIndex = 2;
            Ex.Text = "Ghi";
            Ex.UseVisualStyleBackColor = true;
            Ex.Click += Ex_Click;
            // 
            // InText
            // 
            InText.Location = new Point(43, 114);
            InText.Name = "InText";
            InText.Size = new Size(316, 270);
            InText.TabIndex = 3;
            InText.Text = "";
            // 
            // OutText
            // 
            OutText.Location = new Point(423, 114);
            OutText.Name = "OutText";
            OutText.Size = new Size(316, 270);
            OutText.TabIndex = 4;
            OutText.Text = "";
            // 
            // Cau3
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(OutText);
            Controls.Add(InText);
            Controls.Add(Ex);
            Controls.Add(Cal);
            Controls.Add(In);
            Name = "Cau3";
            Text = "Cau3";
            ResumeLayout(false);
        }

        #endregion

        private Button In;
        private Button Cal;
        private Button Ex;
        private RichTextBox InText;
        private RichTextBox OutText;
    }
}