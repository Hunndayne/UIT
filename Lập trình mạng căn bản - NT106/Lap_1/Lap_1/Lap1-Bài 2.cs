namespace Lap_1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            textBox2.Text = string.Empty;
            textBox3.Text = string.Empty;
            textBox4.Text = string.Empty; // so be
            textBox5.Text = string.Empty; // so lon
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a, b, c;// a,b,c la so Nguyen
            bool dka = int.TryParse(textBox1.Text, out a);
            bool dkb = int.TryParse(textBox2.Text, out b);
            bool dkc = int.TryParse(textBox3.Text, out c);
            if (!dka || !dkb || !dkc)
            {
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
                MessageBox.Show("Chỉ nhập số nguyên");
            }
            else
            {
                textBox4.Text = Math.Min(a, (Math.Min(b, c))).ToString();
                textBox5.Text = Math.Max(a, (Math.Max(b, c))).ToString();
            }
        }
        private void button100_Click(object sender, EventArgs e)
        {
            this.Hide();
            new Lap_1().ShowDialog();
        }
    }
}
