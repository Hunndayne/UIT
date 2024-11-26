using System;
using System.Windows.Forms;
using MimeKit;

namespace Lab5
{
    public partial class EmailDetailsForm : Form
    {
        public EmailDetailsForm(MimeMessage message)
        {
            InitializeComponent();
            // Set form title as email subject
            this.Text = message.Subject;

            // Create a label to display From details
            Label fromLabel = new Label
            {
                Text = "From: " + string.Join(", ", message.From.Mailboxes),
                AutoSize = true,
                Location = new System.Drawing.Point(10, 10)
            };
            this.Controls.Add(fromLabel);

            // Create a label to display Date details
            Label dateLabel = new Label
            {
                Text = "Date: " + message.Date.DateTime.ToString("dd/MM/yyyy hh:mm:ss tt"),
                AutoSize = true,
                Location = new System.Drawing.Point(10, 40)
            };
            this.Controls.Add(dateLabel);

            // Create a TextBox to display the body of the email
            TextBox bodyTextBox = new TextBox
            {
                Text = message.TextBody ?? message.HtmlBody ?? "[No Content Available]",
                Multiline = true,
                ScrollBars = ScrollBars.Vertical,
                Location = new System.Drawing.Point(10, 70),
                Width = 480,
                Height = 300
            };
            this.Controls.Add(bodyTextBox);

            // Set form size
            this.ClientSize = new System.Drawing.Size(500, 400);
        }
        private void EmailDetailsForm_Load(object sender, EventArgs e)
        {

        }
    }

}
