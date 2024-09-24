namespace Lap_1
{
    partial class Lap_1
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
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            button5 = new Button();
            button6 = new Button();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button1.Location = new Point(33, 91);
            button1.Name = "button1";
            button1.Size = new Size(335, 64);
            button1.TabIndex = 0;
            button1.Text = "Bài 1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button2.Location = new Point(442, 91);
            button2.Name = "button2";
            button2.Size = new Size(335, 64);
            button2.TabIndex = 0;
            button2.Text = "Bài 2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button3.Location = new Point(33, 199);
            button3.Name = "button3";
            button3.Size = new Size(335, 64);
            button3.TabIndex = 0;
            button3.Text = "Bài 3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button4.Location = new Point(442, 199);
            button4.Name = "button4";
            button4.Size = new Size(335, 64);
            button4.TabIndex = 0;
            button4.Text = "Bài 4";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button5
            // 
            button5.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button5.Location = new Point(442, 318);
            button5.Name = "button5";
            button5.Size = new Size(335, 64);
            button5.TabIndex = 0;
            button5.Text = "Bài 5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Font = new Font("Times New Roman", 12F, FontStyle.Bold, GraphicsUnit.Point, 163);
            button6.Location = new Point(33, 320);
            button6.Name = "button6";
            button6.Size = new Size(335, 62);
            button6.TabIndex = 1;
            button6.Text = "Thoát";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // Lap_1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(834, 482);
            Controls.Add(button6);
            Controls.Add(button5);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Name = "Lap_1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Lap 1";
            ResumeLayout(false);
        }

        #endregion

        private Button button1;
        private Button button2;
        private Button button3;
        private Button button4;
        private Button button5;
        private Button button6;
    }
}