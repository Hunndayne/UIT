using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.WebSockets;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.LinkLabel;

namespace Lab2_23520580_TranThanhHung
{
    public partial class Cau3 : Form
    {
        public Cau3()
        {
            InitializeComponent();
        }

        private void In_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog
            {
                Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"
            };

            if (DialogResult.OK == ofd.ShowDialog())
            {
                string content;
                StreamReader str = new StreamReader(ofd.FileName);
                content = str.ReadToEnd();
                InText.Text = content;
                str.Close();
            }
        }

        private void Cal_Click(object sender, EventArgs e)
        {
            string input = InText.Text;
            string[] lines = input.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.None);
            DataTable dt = new DataTable();
            StringBuilder output = new StringBuilder();

            foreach (string line in lines)
            {
                if (!string.IsNullOrWhiteSpace(line))
                {
                    string expression = line.Replace("=", "").Trim();
                    expression = expression.Replace("x", "*");
                    try
                    {
                        var result = dt.Compute(expression, null);
                        output.AppendLine($"{line.Trim()} {result}");
                    }
                    catch (Exception)
                    {
                        output.AppendLine($"{line.Trim()} không thực hiện được phép tính này.");
                    }
                }
            }

            OutText.Text = output.ToString();
        }


        private void Ex_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog
            {
                Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*",
                FileName = "output.txt"
            };

            if (sfd.ShowDialog() == DialogResult.OK)
            {

                File.WriteAllText(sfd.FileName, OutText.Text);
            }
        }
    }
}
