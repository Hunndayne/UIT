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

            listView.View = View.Details;

            listView.Columns.Add("Messages", 500); 
            listView.HeaderStyle = ColumnHeaderStyle.None; 
        }

        private void StartListen_Click(object sender, EventArgs e)
        {
            Thread serverThread = new Thread(new ThreadStart(StartUnsafeThread));
            serverThread.IsBackground = true; 
            serverThread.Start();
        }

        void StartUnsafeThread()
        {
            try
            {
                int bytesReceived = 0;
                byte[] recv = new byte[1024]; 


                Socket listenerSocket = new Socket(
                    AddressFamily.InterNetwork,
                    SocketType.Stream,
                    ProtocolType.Tcp);

                IPEndPoint ipepServer = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8080);
                listenerSocket.Bind(ipepServer);
                listenerSocket.Listen(10);

                AppendTextToListView("Server started, waiting for connections...");

                Socket clientSocket = listenerSocket.Accept();
                AppendTextToListView("New client connected.");

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
