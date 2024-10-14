namespace bt2
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
            StartListen = new Button();
            listView = new ListView();
            SuspendLayout();
            // 
            // StartListen
            // 
            StartListen.Location = new Point(410, 40);
            StartListen.Name = "StartListen";
            StartListen.Size = new Size(75, 23);
            StartListen.TabIndex = 1;
            StartListen.Text = "Listen";
            StartListen.UseVisualStyleBackColor = true;
            StartListen.Click += StartListen_Click;
            // 
            // listView
            // 
            listView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            listView.Location = new Point(22, 66);
            listView.Name = "listView";
            listView.Size = new Size(463, 363);
            listView.TabIndex = 2;
            listView.UseCompatibleStateImageBehavior = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(527, 450);
            Controls.Add(listView);
            Controls.Add(StartListen);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
        }

        #endregion
        private Button StartListen;
        private ListView listView;
    }
}
