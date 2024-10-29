using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;

namespace chatserver
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            listView.View = View.Details;

            listView.Columns.Add("Messages", 500); 
            listView.HeaderStyle = ColumnHeaderStyle.None;
        }

        private void Listen_Click(object sender, EventArgs e)
        {
            // Parse and validate IP address and port
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

            // Start a new thread
            Thread serverThread = new Thread(() => StartUnsafeThread(serverIP, serverPort))
            {
                IsBackground = true //background thread, stops when the app closes
            };
            serverThread.Start();
        }

        // Server thread 
        void StartUnsafeThread(IPAddress IP, int Port)
        {
            try
            {
                int bytesReceived = 0;
                byte[] recv = new byte[1024]; //buffer size

                // Create the listening socket
                Socket listenerSocket = new Socket(
                    AddressFamily.InterNetwork,
                    SocketType.Stream,
                    ProtocolType.Tcp);

                // Bind to the IP address and port
                IPEndPoint ipepServer = new IPEndPoint(IP, Port);
                listenerSocket.Bind(ipepServer);
                listenerSocket.Listen(10);

                AppendTextToListView("Server started, waiting for connections...");

                // Accept client
                Socket clientSocket = listenerSocket.Accept();
                AppendTextToListView("New client connected.");

                // Receive data
                while (clientSocket.Connected)
                {
                    string text = "";
                    do
                    {
                        bytesReceived = clientSocket.Receive(recv);
                        text += Encoding.UTF8.GetString(recv, 0, bytesReceived);
                    } while (text.Length == 0 || text[text.Length - 1] != '\n');

                    AppendTextToListView(text.Trim());
                }

                // Clean sockets
                clientSocket.Shutdown(SocketShutdown.Both);
                clientSocket.Close();
                listenerSocket.Close();
            }
            catch (Exception ex)
            {
                AppendTextToListView($"Error: {ex.Message}");
            }
        }

        // Append text
        private void AppendTextToListView(string text)
        {
            if (listView.InvokeRequired)
            {
                listView.Invoke((MethodInvoker)delegate
                {
                    listView.Items.Add(new ListViewItem(text));
                });
            }
            else
            {
                listView.Items.Add(new ListViewItem(text));
            }
        }
    }
}
