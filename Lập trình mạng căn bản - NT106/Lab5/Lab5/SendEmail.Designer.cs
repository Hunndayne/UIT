namespace Lab5
{
    partial class SendEmail
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
            txtMail = new TextBox();
            To = new TextBox();
            button1 = new Button();
            label1 = new Label();
            label2 = new Label();
            Subject = new TextBox();
            label3 = new Label();
            Body = new RichTextBox();
            Cc = new TextBox();
            Bcc = new TextBox();
            label4 = new Label();
            label5 = new Label();
            SuspendLayout();
            // 
            // txtMail
            // 
            txtMail.Location = new Point(86, 35);
            txtMail.Name = "txtMail";
            txtMail.Size = new Size(357, 23);
            txtMail.TabIndex = 0;
            // 
            // To
            // 
            To.Location = new Point(86, 59);
            To.Name = "To";
            To.Size = new Size(357, 23);
            To.TabIndex = 1;
            // 
            // button1
            // 
            button1.Location = new Point(235, 413);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 2;
            button1.Text = "Send";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(41, 38);
            label1.Name = "label1";
            label1.Size = new Size(35, 15);
            label1.TabIndex = 3;
            label1.Text = "From";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(41, 62);
            label2.Name = "label2";
            label2.Size = new Size(19, 15);
            label2.TabIndex = 4;
            label2.Text = "To";
            // 
            // Subject
            // 
            Subject.Location = new Point(86, 143);
            Subject.Name = "Subject";
            Subject.Size = new Size(357, 23);
            Subject.TabIndex = 5;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(34, 146);
            label3.Name = "label3";
            label3.Size = new Size(46, 15);
            label3.TabIndex = 6;
            label3.Text = "Subject";
            // 
            // Body
            // 
            Body.Location = new Point(86, 197);
            Body.Name = "Body";
            Body.Size = new Size(357, 190);
            Body.TabIndex = 7;
            Body.Text = "";
            // 
            // Cc
            // 
            Cc.Location = new Point(86, 79);
            Cc.Name = "Cc";
            Cc.Size = new Size(357, 23);
            Cc.TabIndex = 8;
            // 
            // Bcc
            // 
            Bcc.Location = new Point(86, 96);
            Bcc.Name = "Bcc";
            Bcc.Size = new Size(357, 23);
            Bcc.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(41, 82);
            label4.Name = "label4";
            label4.Size = new Size(21, 15);
            label4.TabIndex = 10;
            label4.Text = "Cc";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(41, 104);
            label5.Name = "label5";
            label5.Size = new Size(26, 15);
            label5.TabIndex = 11;
            label5.Text = "Bcc";
            // 
            // SendEmail
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(496, 450);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(Bcc);
            Controls.Add(Cc);
            Controls.Add(Body);
            Controls.Add(label3);
            Controls.Add(Subject);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(To);
            Controls.Add(txtMail);
            Name = "SendEmail";
            Text = "SendEmail";
            Load += SendEmail_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox txtMail;
        private TextBox To;
        private Button button1;
        private Label label1;
        private Label label2;
        private TextBox Subject;
        private Label label3;
        private RichTextBox Body;
        private TextBox Cc;
        private TextBox Bcc;
        private Label label4;
        private Label label5;
    }
}