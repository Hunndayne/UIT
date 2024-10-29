namespace Client
{
    partial class Client
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
            ipAdr = new Label();
            txtIP = new TextBox();
            txtUsr = new TextBox();
            usr = new Label();
            txtRecv = new TextBox();
            Recv = new Label();
            txtPort = new TextBox();
            Port = new Label();
            btnSend = new Button();
            btnConnect = new Button();
            groupBox1 = new GroupBox();
            richTextBox1 = new RichTextBox();
            txtMessage = new TextBox();
            groupBox2 = new GroupBox();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // ipAdr
            // 
            ipAdr.AutoSize = true;
            ipAdr.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            ipAdr.Location = new Point(10, 17);
            ipAdr.Name = "ipAdr";
            ipAdr.Size = new Size(74, 17);
            ipAdr.TabIndex = 1;
            ipAdr.Text = "IP Address:";
            // 
            // txtIP
            // 
            txtIP.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtIP.Location = new Point(94, 14);
            txtIP.Name = "txtIP";
            txtIP.Size = new Size(112, 23);
            txtIP.TabIndex = 2;
            txtIP.Text = "127.0.0.1";
            // 
            // txtUsr
            // 
            txtUsr.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            txtUsr.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtUsr.Location = new Point(101, 360);
            txtUsr.Name = "txtUsr";
            txtUsr.Size = new Size(106, 23);
            txtUsr.TabIndex = 4;
            // 
            // usr
            // 
            usr.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            usr.AutoSize = true;
            usr.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            usr.Location = new Point(14, 360);
            usr.Name = "usr";
            usr.Size = new Size(74, 17);
            usr.TabIndex = 3;
            usr.Text = "Username: ";
            // 
            // txtRecv
            // 
            txtRecv.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            txtRecv.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtRecv.Location = new Point(101, 394);
            txtRecv.Name = "txtRecv";
            txtRecv.Size = new Size(106, 23);
            txtRecv.TabIndex = 6;
            // 
            // Recv
            // 
            Recv.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
            Recv.AutoSize = true;
            Recv.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            Recv.Location = new Point(21, 394);
            Recv.Name = "Recv";
            Recv.Size = new Size(64, 17);
            Recv.TabIndex = 5;
            Recv.Text = "Receiver: ";
            // 
            // txtPort
            // 
            txtPort.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtPort.Location = new Point(298, 14);
            txtPort.Name = "txtPort";
            txtPort.Size = new Size(88, 23);
            txtPort.TabIndex = 8;
            txtPort.Text = "8888";
            // 
            // Port
            // 
            Port.AutoSize = true;
            Port.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            Port.Location = new Point(258, 17);
            Port.Name = "Port";
            Port.Size = new Size(35, 17);
            Port.TabIndex = 7;
            Port.Text = "Port:";
            // 
            // btnSend
            // 
            btnSend.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            btnSend.Font = new Font("Segoe UI", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnSend.Location = new Point(540, 368);
            btnSend.Name = "btnSend";
            btnSend.Size = new Size(150, 37);
            btnSend.TabIndex = 9;
            btnSend.Text = "Send Message";
            btnSend.UseVisualStyleBackColor = true;
            btnSend.Click += btnSend_Click_1;
            // 
            // btnConnect
            // 
            btnConnect.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            btnConnect.Font = new Font("Segoe UI", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnConnect.Location = new Point(580, 11);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(109, 31);
            btnConnect.TabIndex = 10;
            btnConnect.Text = "Connect";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click_1;
            // 
            // groupBox1
            // 
            groupBox1.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            groupBox1.Controls.Add(richTextBox1);
            groupBox1.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox1.Location = new Point(13, 58);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(262, 278);
            groupBox1.TabIndex = 11;
            groupBox1.TabStop = false;
            groupBox1.Text = "Message Log:";
            // 
            // richTextBox1
            // 
            richTextBox1.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            richTextBox1.Location = new Point(6, 20);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.ReadOnly = true;
            richTextBox1.Size = new Size(250, 252);
            richTextBox1.TabIndex = 12;
            richTextBox1.Text = "";
            // 
            // txtMessage
            // 
            txtMessage.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            txtMessage.Font = new Font("Microsoft YaHei", 10.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            txtMessage.Location = new Point(285, 78);
            txtMessage.Multiline = true;
            txtMessage.Name = "txtMessage";
            txtMessage.Size = new Size(400, 258);
            txtMessage.TabIndex = 12;
            // 
            // groupBox2
            // 
            groupBox2.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            groupBox2.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox2.Location = new Point(280, 58);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(410, 286);
            groupBox2.TabIndex = 13;
            groupBox2.TabStop = false;
            groupBox2.Text = "Type your message here:";
            // 
            // Client
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(700, 422);
            Controls.Add(txtMessage);
            Controls.Add(groupBox1);
            Controls.Add(btnConnect);
            Controls.Add(btnSend);
            Controls.Add(txtPort);
            Controls.Add(Port);
            Controls.Add(txtRecv);
            Controls.Add(Recv);
            Controls.Add(txtUsr);
            Controls.Add(usr);
            Controls.Add(txtIP);
            Controls.Add(ipAdr);
            Controls.Add(groupBox2);
            Name = "Client";
            Text = "`";
            groupBox1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private System.Windows.Forms.Label ipAdr;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.TextBox txtUsr;
        private System.Windows.Forms.Label usr;
        private System.Windows.Forms.TextBox txtRecv;
        private System.Windows.Forms.Label Recv;
        private System.Windows.Forms.TextBox txtPort;
        private System.Windows.Forms.Label Port;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.TextBox txtMessage;
        private System.Windows.Forms.GroupBox groupBox2;
    }
}

