using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5
{
    public partial class SendEmail : Form
    {
        private string _email;
        private string _password;
        public SendEmail(string email, string pass)
        {
            InitializeComponent();
            _email = email;
            _password = pass;
            txtMail.Text = _email;
        }
        //private static string EncodePasswordToBase64(string password)
        //{
        //    byte[] passwordBytes = Encoding.UTF8.GetBytes(password);
        //    return Convert.ToBase64String(passwordBytes);
        //}
        private void SendEmail_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                // Thông tin email
                string to = To.Text;          // To address
                string cc = Cc.Text;          // CC address
                string bcc = Bcc.Text;        // BCC address
                string subject = Subject.Text;// Subject
                string body = Body.Text;      // Body
                string from = txtMail.Text;   // From
                string password = _password;  // Pass

                // Tạo đối tượng MailMessage
                MailMessage mail = new MailMessage();
                mail.From = new MailAddress(from);

                // Add To address
                mail.To.Add(to);

                // Add CC address(es) if provided
                if (!string.IsNullOrWhiteSpace(cc))
                {
                    foreach (string address in cc.Split(new[] { ";" }, StringSplitOptions.RemoveEmptyEntries))
                    {
                        mail.CC.Add(address.Trim());
                    }
                }

                // Add BCC address(es) if provided
                if (!string.IsNullOrWhiteSpace(bcc))
                {
                    foreach (string address in bcc.Split(new[] { ";" }, StringSplitOptions.RemoveEmptyEntries))
                    {
                        mail.Bcc.Add(address.Trim());
                    }
                }

                mail.Subject = subject;
                mail.Body = body;

                // Thiết lập SMTP client
                SmtpClient smtp = new SmtpClient("smtp.gmail.com", 587); // Sử dụng SMTP của Gmail
                smtp.Credentials = new NetworkCredential(from, password);
                smtp.EnableSsl = true;

                // Gửi email
                smtp.Send(mail);
                MessageBox.Show("Email đã được gửi thành công!", "Thành công", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Lỗi khi gửi email: " + ex.Message, "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


    }
}
