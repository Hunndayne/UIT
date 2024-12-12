namespace Lab5
{
    partial class RecieveEmail
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
            SendEmail = new Button();
            lblTotal = new Label();
            lblRecent = new Label();
            listView1 = new ListView();
            EmailDisplay = new Label();
            SuspendLayout();
            // 
            // SendEmail
            // 
            SendEmail.Location = new Point(713, 86);
            SendEmail.Name = "SendEmail";
            SendEmail.Size = new Size(75, 23);
            SendEmail.TabIndex = 0;
            SendEmail.Text = "Send Email";
            SendEmail.UseVisualStyleBackColor = true;
            SendEmail.Click += SendEmail_Click;
            // 
            // lblTotal
            // 
            lblTotal.AutoSize = true;
            lblTotal.Location = new Point(50, 80);
            lblTotal.Name = "lblTotal";
            lblTotal.Size = new Size(38, 15);
            lblTotal.TabIndex = 1;
            lblTotal.Text = "label1";
            // 
            // lblRecent
            // 
            lblRecent.AutoSize = true;
            lblRecent.Location = new Point(108, 80);
            lblRecent.Name = "lblRecent";
            lblRecent.Size = new Size(56, 15);
            lblRecent.TabIndex = 2;
            lblRecent.Text = "lblRecent";
            // 
            // listView1
            // 
            listView1.Location = new Point(12, 115);
            listView1.Name = "listView1";
            listView1.Size = new Size(776, 300);
            listView1.TabIndex = 5;
            listView1.UseCompatibleStateImageBehavior = false;
            // 
            // EmailDisplay
            // 
            EmailDisplay.AutoSize = true;
            EmailDisplay.Location = new Point(50, 29);
            EmailDisplay.Name = "EmailDisplay";
            EmailDisplay.Size = new Size(38, 15);
            EmailDisplay.TabIndex = 6;
            EmailDisplay.Text = "label1";
            // 
            // RecieveEmail
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(EmailDisplay);
            Controls.Add(listView1);
            Controls.Add(lblRecent);
            Controls.Add(lblTotal);
            Controls.Add(SendEmail);
            Name = "RecieveEmail";
            Text = "RecieveEmail";
            Load += RecieveEmail_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button SendEmail;
        private Label lblTotal;
        private Label lblRecent;
        private ListView listView1;
        private Label EmailDisplay;
    }
}