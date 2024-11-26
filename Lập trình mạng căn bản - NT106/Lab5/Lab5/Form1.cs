namespace Lab5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Login_Click(object sender, EventArgs e)
        {
            var email = Email.Text;
            var pass= Pass.Text;
            RecieveEmail RecieveEmail = new RecieveEmail(email, pass);
            this.Hide();
            RecieveEmail.ShowDialog();
            this.Show();
        }
    }
}
