namespace client
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
            button1 = new Button();
            button2 = new Button();
            IP = new TextBox();
            Port = new TextBox();
            Message = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            ServerRespond = new RichTextBox();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(9, 188);
            button1.Margin = new Padding(3, 4, 3, 4);
            button1.Name = "button1";
            button1.Size = new Size(75, 31);
            button1.TabIndex = 0;
            button1.Text = "Send";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(101, 188);
            button2.Margin = new Padding(3, 4, 3, 4);
            button2.Name = "button2";
            button2.Size = new Size(75, 31);
            button2.TabIndex = 1;
            button2.Text = "Clear";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // IP
            // 
            IP.Location = new Point(12, 33);
            IP.Margin = new Padding(3, 4, 3, 4);
            IP.Name = "IP";
            IP.Size = new Size(385, 27);
            IP.TabIndex = 2;
            // 
            // Port
            // 
            Port.Location = new Point(439, 33);
            Port.Margin = new Padding(3, 4, 3, 4);
            Port.Name = "Port";
            Port.Size = new Size(178, 27);
            Port.TabIndex = 3;
            // 
            // Message
            // 
            Message.Location = new Point(12, 118);
            Message.Margin = new Padding(3, 4, 3, 4);
            Message.Multiline = true;
            Message.Name = "Message";
            Message.Size = new Size(605, 62);
            Message.TabIndex = 4;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(9, 9);
            label1.Name = "label1";
            label1.Size = new Size(78, 20);
            label1.TabIndex = 5;
            label1.Text = "IP Address";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(439, 9);
            label2.Name = "label2";
            label2.Size = new Size(35, 20);
            label2.TabIndex = 6;
            label2.Text = "Port";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(12, 94);
            label3.Name = "label3";
            label3.Size = new Size(67, 20);
            label3.TabIndex = 7;
            label3.Text = "Message";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(12, 247);
            label4.Name = "label4";
            label4.Size = new Size(108, 20);
            label4.TabIndex = 8;
            label4.Text = "Server respond";
            // 
            // ServerRespond
            // 
            ServerRespond.Location = new Point(12, 271);
            ServerRespond.Margin = new Padding(3, 4, 3, 4);
            ServerRespond.Name = "ServerRespond";
            ServerRespond.Size = new Size(605, 193);
            ServerRespond.TabIndex = 9;
            ServerRespond.Text = "";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(662, 479);
            Controls.Add(ServerRespond);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(Message);
            Controls.Add(Port);
            Controls.Add(IP);
            Controls.Add(button2);
            Controls.Add(button1);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "UDP Client";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Button button2;
        private TextBox IP;
        private TextBox Port;
        private TextBox Message;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private RichTextBox ServerRespond;
    }
}
