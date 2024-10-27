using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;

namespace bt2
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

        private void StartListen_Click(object sender, EventArgs e)
        {
            Thread serverThread = new Thread(new ThreadStart(StartUnsafeThread));
            serverThread.IsBackground = true; // Make it a background thread so it stops when the application closes
            serverThread.Start();
        }

        void StartUnsafeThread()
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

                IPEndPoint ipepServer = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8080);
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
