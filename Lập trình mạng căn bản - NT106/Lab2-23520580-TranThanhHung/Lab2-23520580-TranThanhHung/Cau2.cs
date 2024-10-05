using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_23520580_TranThanhHung
{
    public partial class Cau2 : Form
    {
        public Cau2()
        {
            InitializeComponent();
        }

        private void OpenFile_Click(object sender, EventArgs e)
        {

            OpenFileDialog ofd = new OpenFileDialog {
                Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"
            };

            if (DialogResult.OK == ofd.ShowDialog())
            {
                


                var FilePath=ofd.FileName;
                var fi = new FileInfo(FilePath);

                string content;
                StreamReader str = new StreamReader(ofd.FileName);
                content = str.ReadToEnd();
                richTextBox1.Text = content;
                str.Close();

                FileName.Text=  fi.Name;

                Url.Text=ofd.FileName;

                Lines.Text = File.ReadLines(FilePath).Count().ToString();

                string richText = richTextBox1.Text;
                char[] delimiters = new char[] { ' ', '\r', '\n', ',', '.' };
                string[] words = richText.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
                Words.Text = words.Length.ToString();
                Char.Text = richTextBox1.Text.Length.ToString();

            }
            else
            {
                MessageBox.Show(ofd.FileName + "could not open file");
            }
        }
    }
}
