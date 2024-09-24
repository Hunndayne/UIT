using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lap_1
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Khởi tạo
            float dtb = 0;
            float diemthapnhat = 0;
            float diemcaonhat = 0;
            string[] str_diem = (textNhap.Text.Trim()).Split(' '); // Tách mỗi điểm vào từng phần tử_mảng
                                                                   // và xóa khoảng trắng đầu cũng như cuối
            float[] diem = new float[str_diem.Length]; // mảng điểm tương ứng n phần tử str_điểm
            //
            // Gán và kiểm tra xem có hợp lệ hay không 
            //
            bool Check_perfect_parse = true;
            for (int i = 0; i < diem.Length; i++)
            {
                try
                {
                    diem[i] = float.Parse(str_diem[i]);
                    if (diem[i] < 0 || diem[i] > 10)
                    {
                        MessageBox.Show("Điểm phải nằm trong khoảng từ 0 đến 10");
                        Check_perfect_parse = false;
                        break;
                    }
                    dtb += diem[i] / diem.Length;
                }
                catch
                {
                    MessageBox.Show("Nhập không đúng định dạng");
                    Check_perfect_parse = false;
                    break;
                }
            }

            //
            // Xuất
            //
            if (Check_perfect_parse)
            {
                for (int i = 0; i < diem.Length; i += 4)
                {
                    string str_temp = string.Empty; // Chuỗi tạm thời gom 4 đối tượng 

                    for (int j = 0; j < 4; j++)
                    {
                        if (i + j < diem.Length)
                        {
                            str_temp += $"Môn {(i + j + 1)}: {(diem[i + j]),-6} ";

                        }                                            //listBox.Items.Add($"Môn {i + 1}: {diem[i]}"); 
                                                                     //                                      // chỉ xuất thèo 1-1 ( 1 môn - 1 dòng )
                                                                     // 1 2 3 4 5.5 6.6 7.7 8.8

                    }
                    listBox.Items.Add(str_temp.Trim()); // listBox.Items.Add(string __ ) thêm đối tượng
                                                        // vào line [] của list box 
                }
            }
            int so_mon_dau = 0;
            foreach (var d in diem)
            {
                if (d >= 5.0)
                    so_mon_dau++;
            }
            if (Check_perfect_parse)
            {
                label4.Visible = true; texttb.Text = dtb.ToString("F2");
                label5.Visible = true; textxl.Text = Xeploai(dtb, diem);
                label6.Visible = true; textdiemthap.Text = diem.Min().ToString();
                label7.Visible = true; textdiemcao.Text = diem.Max().ToString();
                label8.Visible = true; textdau.Text = so_mon_dau.ToString();
                label9.Visible = true; textrot.Text = (diem.Length - so_mon_dau).ToString();
            }

        }
        private string Xeploai(float dtb, float[] str_diem)
        {
            if (dtb >= 9 && str_diem.All(str_diem => str_diem >= 6.5))
                return "Xuất sắc";
            else if (dtb >= 8 && str_diem.All(str_diem => str_diem >= 6.5))
                return "Giỏi";
            else if (dtb >= 6.5 && str_diem.All(str_diem => str_diem >= 5))
                return "Khá";
            else if (dtb >= 5 && str_diem.All(str_diem => str_diem >= 3.5))
                return "Trung bình";
            else if (dtb >= 3.5 && str_diem.All(str_diem => str_diem >= 2))
                return "Yếu";
            else
                return "Kém";
        }

        private void buttonxoa_Click(object sender, EventArgs e)
        {
            texttb.Text = string.Empty;
            textxl.Text = string.Empty;
            textdiemcao.Text = string.Empty;
            textdiemthap.Text = string.Empty;
            textdau.Text = string.Empty;
            textrot.Text = string.Empty;
            listBox.Items.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            textNhap.Text = string.Empty;
        }
        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            new Lap_1().ShowDialog();
        }
    }
}
