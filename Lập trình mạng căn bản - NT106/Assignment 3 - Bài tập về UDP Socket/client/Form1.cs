using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace client
{
    public partial class Form1 : Form
    {
        private Socket _listenerSocket;
        private bool _isListening = false;

        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
          
            if (!IPAddress.TryParse(IP.Text, out var serverIP))
            {
                MessageBox.Show("IP không hợp lệ, hãy nhập lại");
                return;
            }

           
            if (!int.TryParse(Port.Text, out var serverPort) || serverPort <= 0 || serverPort > 65535||serverPort== 34556)
            {
                MessageBox.Show("Port không hợp lệ, hãy nhập lại");
                return;
            }
            if (serverPort == 34556)
            {
                MessageBox.Show("Port 34556 sử dụng để giao tiếp server và client, hãy nhập lại");
                return;
            }
            try
            {


                using (Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp))
                {
                    IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 0); 
                    socket.Bind(localEndPoint);

                    EndPoint serverEndPoint = new IPEndPoint(serverIP, serverPort);

                    string messageToSend = Message.Text;
                    byte[] sendData = Encoding.UTF8.GetBytes(messageToSend);

                  
                    socket.SendTo(sendData, serverEndPoint);
                    Message.Text = "";
                }

             
                if (!_isListening)
                {
                    _isListening = true;
                    await Task.Run(() => StartListening());
                }
            }
            catch (SocketException ex)
            {
                MessageBox.Show($"Socket error: {ex.Message}");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }
        }

        private void StartListening()
        {
            try
            {
                _listenerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, 34556); // Listening on port 34556
                _listenerSocket.Bind(localEndPoint);

                EndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0); // Remote client info
                byte[] buffer = new byte[4096];

                while (_isListening)
                {
                    int receivedBytes = _listenerSocket.ReceiveFrom(buffer, ref remoteEndPoint);
                    string receivedData = Encoding.UTF8.GetString(buffer, 0, receivedBytes);

                    IPEndPoint clientEndPoint = (IPEndPoint)remoteEndPoint;
                    string clientIP = clientEndPoint.Address.ToString();
                    int clientPort = clientEndPoint.Port;

                    // Update UI with received message
                    ServerRespond.Invoke((MethodInvoker)delegate {
                        ServerRespond.AppendText($"Received from Server {clientIP}:{clientPort} : {receivedData}\n");
                    });
                }
            }
            catch (SocketException ex)
            {
                MessageBox.Show($"Socket error: {ex.Message}");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            IP.Text = string.Empty;
            Port.Text = string.Empty;
            Message.Text = string.Empty;
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
           
            _isListening = false;
            _listenerSocket?.Close();
            base.OnFormClosing(e);
        }
    }
}
