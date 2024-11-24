using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Lab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            // Initialize DataGridView columns for displaying headers
            dataGridView1.Columns.Add("STT", "STT");
            dataGridView1.Columns.Add("Name", "Header");
            dataGridView1.Columns.Add("Value", "Value");


        }

        private async void button1_Click(object sender, EventArgs e)
        {
            // Get the selected URL from the TextBox
            string URL = Search.Text;
            richTextBox1.Text = "Loading...";

            string urlInput = URL.Trim();

            // Automatically add "http://" if no scheme is provided.
            if (!urlInput.StartsWith("http://") && !urlInput.StartsWith("https://"))
            {
                urlInput = "http://" + urlInput;
            }

            // Validate URL
            if (!Uri.TryCreate(urlInput, UriKind.Absolute, out Uri uriResult) ||
                (uriResult.Scheme != Uri.UriSchemeHttp && uriResult.Scheme != Uri.UriSchemeHttps))
            {
                richTextBox1.Text = "Please enter a valid URL.";
                return;
            }



            // Get the selected User-Agent string from the ComboBox


            // Fetch HTML content asynchronously
            string htmlContent = await Task.Run(() => GetHtmlContent(urlInput));
            richTextBox1.Text = htmlContent;

            // Fetch headers asynchronously and update DataGridView
            var headers = await Task.Run(() => GetHeaders(urlInput));
            dataGridView1.Rows.Clear(); // Clear any previous data
            int index = 1;
            foreach (var header in headers)
            {
                dataGridView1.Rows.Add(index++, header.Key, header.Value);
            }
        }

        private string GetHtmlContent(string url)
        {
            try
            {
                // Create an HttpWebRequest for the URL
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);


                // Get the response
                using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
                using (Stream dataStream = response.GetResponseStream())
                {
                    // Read HTML content
                    return GetHtmlFromStream(dataStream);
                }
            }
            catch (Exception ex)
            {
                return $"Error: {ex.Message}";
            }
        }

        private string GetHtmlFromStream(Stream dataStream)
        {
            using (StreamReader reader = new StreamReader(dataStream))
            {
                // Read the HTML content and return it
                return reader.ReadToEnd();
            }
        }

        private List<KeyValuePair<string, string>> GetHeaders(string url)
        {
            List<KeyValuePair<string, string>> headersList = new List<KeyValuePair<string, string>>();

            try
            {
                // Create an HttpWebRequest for the URL
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);


                // Get the response
                using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
                {
                    // Iterate over the headers and add them to the list
                    for (int i = 0; i < response.Headers.Count; i++)
                    {
                        headersList.Add(new KeyValuePair<string, string>(response.Headers.Keys[i], response.Headers[i]));
                    }
                }
            }
            catch (Exception ex)
            {
                // If there's an error, add it to the list
                headersList.Add(new KeyValuePair<string, string>("Error", ex.Message));
            }

            return headersList;
        }
    }
}
