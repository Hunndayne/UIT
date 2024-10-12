namespace udp_server
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
            Port = new Button();
            textBox1 = new TextBox();
            richTextBox1 = new RichTextBox();
            label3 = new Label();
            Message = new TextBox();
            SendToClient = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(39, 33);
            label1.Name = "label1";
            label1.Size = new Size(35, 20);
            label1.TabIndex = 0;
            label1.Text = "Port";
            // 
            // Port
            // 
            Port.Location = new Point(536, 26);
            Port.Margin = new Padding(3, 4, 3, 4);
            Port.Name = "Port";
            Port.Size = new Size(85, 27);
            Port.TabIndex = 1;
            Port.Text = "Listen";
            Port.UseVisualStyleBackColor = true;
            Port.Click += Port_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(80, 26);
            textBox1.Margin = new Padding(3, 4, 3, 4);
            textBox1.Name = "textBox1";
            textBox1.RightToLeft = RightToLeft.Yes;
            textBox1.Size = new Size(81, 27);
            textBox1.TabIndex = 2;
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(39, 68);
            richTextBox1.Margin = new Padding(3, 4, 3, 4);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(582, 269);
            richTextBox1.TabIndex = 3;
            richTextBox1.Text = "";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(39, 351);
            label3.Name = "label3";
            label3.Size = new Size(72, 20);
            label3.TabIndex = 11;
            label3.Text = "Response";
            // 
            // Message
            // 
            Message.Location = new Point(39, 375);
            Message.Margin = new Padding(3, 4, 3, 4);
            Message.Multiline = true;
            Message.Name = "Message";
            Message.Size = new Size(582, 68);
            Message.TabIndex = 10;
            // 
            // SendToClient
            // 
            SendToClient.Location = new Point(39, 451);
            SendToClient.Margin = new Padding(3, 4, 3, 4);
            SendToClient.Name = "SendToClient";
            SendToClient.Size = new Size(86, 31);
            SendToClient.TabIndex = 8;
            SendToClient.Text = "Send";
            SendToClient.UseVisualStyleBackColor = true;
            SendToClient.Click += SendToClient_Click_1;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(648, 495);
            Controls.Add(label3);
            Controls.Add(Message);
            Controls.Add(SendToClient);
            Controls.Add(richTextBox1);
            Controls.Add(textBox1);
            Controls.Add(Port);
            Controls.Add(label1);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "Server";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button Port;
        private TextBox textBox1;
        private RichTextBox richTextBox1;
        private Label label3;
        private TextBox Message;
        private Button SendToClient;
    }
}
