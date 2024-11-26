using MailKit;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;
using MailKit.Net.Imap;
using MailKit.Search;
using MimeKit;

namespace Lab5
{
    public partial class RecieveEmail : Form
    {
        private string _email;
        private string _pass;
        private IMailFolder _inbox; // Declare inbox as a class-level variable
        private List<MimeMessage> _messages; // List to store fetched messages
        private int _emailLoadCount; // Track the number of emails loaded
        private const int EmailLoadIncrement = 10; // Number of emails to load per increment

        public RecieveEmail(string email, string pass)
        {
            InitializeComponent();
            _email = email;
            _pass = pass;
            _messages = new List<MimeMessage>();
            _emailLoadCount = 0; // Start with 0 loaded emails

            try
            {
                using (var client = new ImapClient())
                {
                    // Connect to IMAP server
                    client.Connect("imap.gmail.com", 993, true);
                    client.Authenticate(_email, _pass);

                    // Select the Inbox folder
                    _inbox = client.Inbox;
                    _inbox.Open(FolderAccess.ReadOnly);

                    // Set the total number of emails in lblTotal
                    lblTotal.Text = $"Total: {_inbox.Count}";

                    // Get recent emails count
                    var recentMessages = _inbox.Fetch(0, -1, MessageSummaryItems.Flags)
                                              .Where(m => m.Flags != null && m.Flags.Value.HasFlag(MessageFlags.Recent))
                                              .Count();
                    lblRecent.Text = $"Recent: {recentMessages}";

                    // Load initial emails into the ListView
                    LoadEmails();

                    // Disconnect from server
                    client.Disconnect(true);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Login Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            // Add DoubleClick event handler for ListView items
            listView1.DoubleClick += ListView1_DoubleClick;

        }

        private void InitializeListView()
        {
            listView1.Columns.Add("Email", 300);
            listView1.Columns.Add("From", 200);
            listView1.Columns.Add("Thời gian", 200);
            listView1.View = View.Details;
        }

        private void LoadEmails()
        {
            if (_emailLoadCount == 0)
            {
                InitializeListView(); // Initialize ListView columns only once
                listView1.Items.Clear(); // Clear any existing items
                _messages.Clear(); // Clear any previous email messages stored
            }

            // Load emails from the newest to the oldest in increments of EmailLoadIncrement
            int totalEmails = _inbox.Count;
            int newLoadCount = Math.Min(_emailLoadCount + EmailLoadIncrement, totalEmails);

            for (int i = totalEmails - 1 - _emailLoadCount; i >= totalEmails - newLoadCount; i--)
            {
                var message = _inbox.GetMessage(i);
                _messages.Add(message); // Store the message in the list

                // Create a new ListViewItem with the email subject
                ListViewItem item = new ListViewItem(message.Subject);

                // Add the "From" subitem - include the name and email address if available
                var fromMailbox = message.From.Mailboxes.FirstOrDefault();
                string fromInfo = fromMailbox != null
                    ? $"{fromMailbox.Name} <{fromMailbox.Address}>"
                    : "Unknown Sender";
                item.SubItems.Add(fromInfo);

                // Add the "Date" subitem - format it to match the format in your screenshot
                string date = message.Date.DateTime.ToString("dd/MM/yyyy hh:mm:ss tt");
                item.SubItems.Add(date);

                // Add the complete ListViewItem to the ListView control
                listView1.Items.Add(item);
            }

            // Update the count of emails loaded
            _emailLoadCount = newLoadCount;
        }



        private void ListView1_DoubleClick(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                // Get the selected email index
                int selectedIndex = listView1.SelectedItems[0].Index;
                MimeMessage selectedMessage = _messages[selectedIndex];

                // Open the EmailDetailsForm to display the full email content
                EmailDetailsForm detailsForm = new EmailDetailsForm(selectedMessage);
                detailsForm.ShowDialog();
            }
        }

        private void RecieveEmail_Load(object sender, EventArgs e)
        {
        }

        private void SendEmail_Click(object sender, EventArgs e)
        {
            SendEmail SendEmail = new SendEmail(_email, _pass);
            SendEmail.ShowDialog();
        }

        private void loadmoreEmails_Click_1(object sender, EventArgs e)
        {
            try
            {
                using (var client = new ImapClient())
                {
                    // Reconnect to the IMAP server to load more emails
                    client.Connect("imap.gmail.com", 993, true);
                    client.Authenticate(_email, _pass);

                    // Select the Inbox folder
                    _inbox = client.Inbox;
                    _inbox.Open(FolderAccess.ReadOnly);

                    // Load more emails
                    LoadEmails();

                    // Disconnect from server
                    client.Disconnect(true);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Failed to Load Emails", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }


}
