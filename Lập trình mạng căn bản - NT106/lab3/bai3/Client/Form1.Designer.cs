namespace Client
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
            IP = new TextBox();
            Port = new TextBox();
            Log = new RichTextBox();
            Message = new RichTextBox();
            Connect = new Button();
            Send_Message = new Button();
            SuspendLayout();
            // 
            // IP
            // 
            IP.Location = new Point(31, 50);
            IP.Name = "IP";
            IP.Size = new Size(100, 23);
            IP.TabIndex = 0;
            // 
            // Port
            // 
            Port.Location = new Point(267, 50);
            Port.Name = "Port";
            Port.Size = new Size(100, 23);
            Port.TabIndex = 1;
            // 
            // Log
            // 
            Log.Location = new Point(31, 107);
            Log.Name = "Log";
            Log.Size = new Size(336, 243);
            Log.TabIndex = 2;
            Log.Text = "";
            // 
            // Message
            // 
            Message.Location = new Point(31, 365);
            Message.Name = "Message";
            Message.Size = new Size(336, 47);
            Message.TabIndex = 3;
            Message.Text = "";
            // 
            // Connect
            // 
            Connect.Location = new Point(292, 79);
            Connect.Name = "Connect";
            Connect.Size = new Size(75, 23);
            Connect.TabIndex = 4;
            Connect.Text = "button1";
            Connect.UseVisualStyleBackColor = true;
            Connect.Click += Connect_Click;
            // 
            // Send_Message
            // 
            Send_Message.Location = new Point(292, 418);
            Send_Message.Name = "Send_Message";
            Send_Message.Size = new Size(75, 23);
            Send_Message.TabIndex = 5;
            Send_Message.Text = "Gửi";
            Send_Message.UseVisualStyleBackColor = true;
            Send_Message.Click += Send_Message_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(423, 470);
            Controls.Add(Send_Message);
            Controls.Add(Connect);
            Controls.Add(Message);
            Controls.Add(Log);
            Controls.Add(Port);
            Controls.Add(IP);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox IP;
        private TextBox Port;
        private RichTextBox Log;
        private RichTextBox Message;
        private Button Connect;
        private Button Send_Message;
    }
}
