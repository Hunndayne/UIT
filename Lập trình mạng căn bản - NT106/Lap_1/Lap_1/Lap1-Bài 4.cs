using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace Lap_1
{

    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }



        private void button2_Click(object sender, EventArgs e)
        {
            textNhap.Text = string.Empty;
            textkq.Text = string.Empty;
            comboBox1.SelectedIndex = -1;
            comboBox2.SelectedIndex = -1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (isBinary(textNhap.Text) && comboBox1.SelectedIndex==0 ) //Bin
            {
                switch (comboBox2.SelectedIndex)
                {
                    case 0:
                        MessageBox.Show("Khờ à");
                        textkq.Text = textNhap.Text;
                        break;
                    case 1:
                        textkq.Text = bin_to_dec(textNhap.Text);
                        break;
                    case 2:
                        textkq.Text = dec_to_hex(bin_to_dec(textNhap.Text) );
                        break;
                }
            }
            else if (isDecimal(textNhap.Text) && comboBox1.SelectedIndex==1 )  // Dec
            {
                switch (comboBox2.SelectedIndex)
                {
                    case 0:
                        textkq.Text = dec_to_bin(textNhap.Text);
                        break;
                    case 1:
                        MessageBox.Show("Khờ à");
                        textkq.Text = textNhap.Text;
                        break;
                    case 2:
                        textkq.Text = dec_to_hex(textNhap.Text);
                        break;
                }
            }
            else if ( isHexadecimal(textNhap.Text) && comboBox1.SelectedIndex == 2)  //Hex
            {
                switch (comboBox2.SelectedIndex)
                {
                    case 0:
                        textkq.Text = dec_to_bin(hex_to_dec(textNhap.Text));
                        break;
                    case 1:
                        textkq.Text = hex_to_dec(textNhap.Text);
                        break;
                    case 2:
                        MessageBox.Show("Khờ à");
                        textkq.Text = textNhap.Text;
                        break;
                }
            }
            else error_form();
        }
        // Điều kiện 
        private bool isDecimal(string str)
        {
            return Int32.TryParse(str, out _ ); // out _ là gán vô danh
        }
        private bool isBinary(string str)
        {
            foreach ( char c in str)
            {
               if (c != '0' && c != '1') 
                    return false;
            }
            return true;
        }
        private bool isHexadecimal(string str)
        {
            foreach (char c in str)
            {
                if ( !( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') ) )

                     return false; 
            }
            return true; 
        }

        // Hàm đổi
        private string bin_to_dec(string str)
        {
            return (Convert.ToInt32(str, 2)).ToString();
        }
        private string dec_to_hex(string str)
        {
            return Convert.ToString(Int32.Parse(str), 16).ToUpper();
        }
        private string hex_to_dec(string str)
        {
            return (Convert.ToInt32(str, 16)).ToString();
           
        }
        private string dec_to_bin(string str)
        {
            return Convert.ToString(Int32.Parse(str), 2);
        }
        // Bắt error-> Chọn hoặc nhập lại
        private void error_form()
        {
            MessageBox.Show("Vui lòng nhập đúng định dạng");
            comboBox1.SelectedIndex = -1;
        }
        private void button4_Click(object sender, EventArgs e)
        {
            this.Hide();
            new Lap_1().ShowDialog();
        }

    }
}
