namespace Lab5
{
    public partial class LOGi : Form
    {
        public LOGi()
        {
            InitializeComponent();
        }

        private void Login_Click(object sender, EventArgs e)
        {
            
            var email = Email.Text;
            var pass= Pass.Text;
            if (email!=null && pass!=null) { 
            RecieveEmail RecieveEmail = new RecieveEmail(email, pass);
            this.Hide();
            RecieveEmail.ShowDialog();
            this.Show();}
            else
            {
                MessageBox.Show("Nhập Email và Password.");
            }
        }
    }
}
