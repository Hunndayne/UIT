using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;

namespace Client
{
    public partial class Form1 : Form
    {
        private TcpClient _client;
        private NetworkStream _networkStream;

        public Form1()
        {
            InitializeComponent();
        }

        private void Connect_Click(object sender, EventArgs e)
        {
            try
            {
                // Create a new TcpClient object
                _client = new TcpClient();

                if (!IPAddress.TryParse(IP.Text, out var serverIP))
                {
                    MessageBox.Show("IP không hợp lệ, hãy nhập lại");
                    return;
                }

                if (!int.TryParse(Port.Text, out var serverPort) || serverPort <= 0 || serverPort > 65535)
                {
                    MessageBox.Show("Port không hợp lệ, hãy nhập lại");
                    return;
                }

                // Connect to the server
                _client.Connect(serverIP, serverPort);
                _networkStream = _client.GetStream(); // Get the stream for communication

                MessageBox.Show("Kết nối thành công!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Lỗi khi kết nối: {ex.Message}");
            }
        }

        private void Send_Message_Click(object sender, EventArgs e)
        {
            if (_client == null || !_client.Connected)
            {
                MessageBox.Show("Chưa kết nối đến server.");
                return;
            }

            string message = Message.Text;
            Log.Text = Message.Text;
            Message.Text = "";
            if (string.IsNullOrWhiteSpace(message))
            {
                MessageBox.Show("Vui lòng nhập tin nhắn.");
                return;
            }

            try
            {
                // Convert the message to byte array
                byte[] messageBuffer = Encoding.UTF8.GetBytes("Client: "+message+"\n");


                // Send the message through the stream
                _networkStream.Write(messageBuffer, 0, messageBuffer.Length);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Lỗi khi gửi tin nhắn: {ex.Message}");
            }
        }

        // Ensure to close the stream and client socket properly
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            if (_networkStream != null)
            {
                _networkStream.Close();
            }
            if (_client != null)
            {
                _client.Close();
            }

            base.OnFormClosing(e);
        }
    }
}
