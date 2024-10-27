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

            // Set the ListView to Details view
            listView.View = View.Details;

            // Add a single column and set its width
            listView.Columns.Add("Messages", 500); // Adjust the width as necessary
            listView.HeaderStyle = ColumnHeaderStyle.None; // Hide the column header if not needed
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

            // Start a new thread for the server, passing IP and Port as parameters
            Thread serverThread = new Thread(() => StartUnsafeThread(serverIP, serverPort))
            {
                IsBackground = true // Make it a background thread so it stops when the application closes
            };
            serverThread.Start();
        }

        // Server thread method accepting IP and Port
        void StartUnsafeThread(IPAddress IP, int Port)
        {
            try
            {
                int bytesReceived = 0;
                byte[] recv = new byte[1024]; // Use a larger buffer size to improve efficiency

                // Create the listening socket
                Socket listenerSocket = new Socket(
                    AddressFamily.InterNetwork,
                    SocketType.Stream,
                    ProtocolType.Tcp);

                // Bind to the provided IP address and port
                IPEndPoint ipepServer = new IPEndPoint(IP, Port);
                listenerSocket.Bind(ipepServer);
                listenerSocket.Listen(10);

                AppendTextToListView("Server started, waiting for connections...");

                // Accept client connection
                Socket clientSocket = listenerSocket.Accept();
                AppendTextToListView("New client connected.");

                // Receive data from the client
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

                // Clean up sockets
                clientSocket.Shutdown(SocketShutdown.Both);
                clientSocket.Close();
                listenerSocket.Close();
            }
            catch (Exception ex)
            {
                AppendTextToListView($"Error: {ex.Message}");
            }
        }

        // Append text to the ListView (thread-safe)
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
