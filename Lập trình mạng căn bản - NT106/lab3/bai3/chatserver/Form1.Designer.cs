namespace chatserver
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
            Listen = new Button();
            listView = new ListView();
            SuspendLayout();
            // 
            // IP
            // 
            IP.Location = new Point(92, 48);
            IP.Name = "IP";
            IP.Size = new Size(151, 23);
            IP.TabIndex = 0;
            // 
            // Port
            // 
            Port.Location = new Point(274, 48);
            Port.Name = "Port";
            Port.Size = new Size(54, 23);
            Port.TabIndex = 1;
            // 
            // Listen
            // 
            Listen.Location = new Point(357, 48);
            Listen.Name = "Listen";
            Listen.Size = new Size(75, 23);
            Listen.TabIndex = 3;
            Listen.Text = "Listen";
            Listen.UseVisualStyleBackColor = true;
            Listen.Click += Listen_Click;
            // 
            // listView
            // 
            listView.Location = new Point(92, 86);
            listView.Name = "listView";
            listView.Size = new Size(340, 309);
            listView.TabIndex = 4;
            listView.UseCompatibleStateImageBehavior = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(545, 450);
            Controls.Add(listView);
            Controls.Add(Listen);
            Controls.Add(Port);
            Controls.Add(IP);
            Name = "Form1";
            Text = "Chat Server";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox IP;
        private TextBox Port;
        private Button Listen;
        private ListView listView;
    }
}
