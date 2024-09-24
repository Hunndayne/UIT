namespace Lab1_23520580_TranThanhHung
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Num1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Num2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        //tính tổng
        private void button1_Click(object sender, EventArgs e)
        {
            int N1, N2, result;

            bool ch1 = int.TryParse(Num1.Text, out N1);
            bool ch2 = int.TryParse(Num2.Text, out N2);
            if (ch1 && ch2)
            {
                N1 = Int32.Parse(Num1.Text.Trim());
                N2 = Int32.Parse(Num2.Text.Trim());
                result = N1 + N2;
                textBox1.Text = result.ToString();
            }
            else
            {
                MessageBox.Show("Nhập số nguyên");
                textBox1.Text = "Task failed successfully";
            }

        }
        //Tính hiệu
        private void Subtract_Click(object sender, EventArgs e)
        {
            int N1, N2, result;

            bool ch1 = int.TryParse(Num1.Text, out N1);
            bool ch2 = int.TryParse(Num2.Text, out N2);
            if (ch1 && ch2)
            {
                N1 = Int32.Parse(Num1.Text.Trim());
                N2 = Int32.Parse(Num2.Text.Trim());
                result = N1 - N2;
                textBox1.Text = result.ToString();
            }
            else
            {
                MessageBox.Show("Nhập số nguyên");
                textBox1.Text = "Task failed successfully";
            }

        }
        //Tính tích
        private void Time_Click(object sender, EventArgs e)
        {
            int N1, N2, result;

            bool ch1 = int.TryParse(Num1.Text, out N1);
            bool ch2 = int.TryParse(Num2.Text, out N2);
            if (ch1 && ch2)
            {
                N1 = Int32.Parse(Num1.Text.Trim());
                N2 = Int32.Parse(Num2.Text.Trim());
                result = N1 * N2;
                textBox1.Text = result.ToString();
            }
            else
            {
                MessageBox.Show("Nhập số nguyên");
                textBox1.Text = "Task failed successfully";
            }

        }
        //Tính thương
        private void Divide_Click(object sender, EventArgs e)
        {
            int N1, N2;
            double result;
            bool ch1 = int.TryParse(Num1.Text, out N1);
            bool ch2 = int.TryParse(Num2.Text, out N2);
            if (ch1 && ch2)
            {
                N1 = Int32.Parse(Num1.Text.Trim());
                N2 = Int32.Parse(Num2.Text.Trim());
                result = (double)N1 / N2;
                textBox1.Text = result.ToString();
            }
            else
            {
                MessageBox.Show("Nhập số nguyên");
                textBox1.Text = "Task failed successfully";
            }
        }
        //Nút xóa
        private void Delete_Click(object sender, EventArgs e)
        {
            Num1.Text = "";
            Num2.Text = "";
            textBox1.Text = "";
        }
        //Nút thoát

        private void button100_Click(object sender, EventArgs e)
        {
            this.Hide();
            new Lap_1.Lap_1().ShowDialog();
            this.Close();
        }


            private void Thoát_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
