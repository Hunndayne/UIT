using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Collections.Generic;

namespace udp_server
{
    public partial class Form1 : Form
    {
        private CancellationTokenSource cancellationTokenSource;
        private Thread listeningThread;

        private static IDictionary<int, Socket> socket_connected = new Dictionary<int, Socket>();

     
        private EndPoint SaveremoteEndPoint;
        private int clientPort;
        public Form1()
        {
            InitializeComponent();
        }

        private void Port_Click(object sender, EventArgs e)
        {
            try
            {
                if (!int.TryParse(textBox1.Text, out var port) || port <= 0 || port > 65535 || port == 34556)
                {
                    MessageBox.Show("Port không hợp lệ, hãy nhập lại");
                    return;
                }

                if (port == 34556)
                {
                    MessageBox.Show("Port 34556 sử dụng để giao tiếp server và client, hãy nhập lại");
                    return;
                }
                if (socket_connected.ContainsKey(port))
                {
                    MessageBox.Show("Server đã được khởi chạy trên cổng này.");
                    return;
                }

               
                cancellationTokenSource = new CancellationTokenSource();

                
                listeningThread = new Thread(() => StartListening(port, cancellationTokenSource.Token));
                listeningThread.IsBackground = true;
                listeningThread.Start();
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

        private void StartListening(int port, CancellationToken cancellationToken)
        {
            try
            {
                
                Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                IPEndPoint localEndPoint = new IPEndPoint(IPAddress.Any, port);
                listener.Bind(localEndPoint);

           
                socket_connected.Add(port, listener);

                byte[] buffer = new byte[4096];
                EndPoint tempRemoteEndPoint = new IPEndPoint(IPAddress.Any, 0);

                while (!cancellationToken.IsCancellationRequested)
                {
                    if (listener.Poll(100000, SelectMode.SelectRead))
                    {
                        int receivedBytes = listener.ReceiveFrom(buffer, ref tempRemoteEndPoint);
                        string receivedData = Encoding.UTF8.GetString(buffer, 0, receivedBytes);

                        SaveremoteEndPoint = tempRemoteEndPoint; 

                        IPEndPoint clientEndPoint = (IPEndPoint)SaveremoteEndPoint;
                        string clientIP = clientEndPoint.Address.ToString();
                        clientPort = clientEndPoint.Port;

                   

                        richTextBox1.Invoke((MethodInvoker)delegate
                        {
                            richTextBox1.AppendText($"Received from {clientIP}:{clientPort} : {receivedData}\n");
                        });
                    }
                }
            }
            catch (SocketException ex)
            {
                Invoke((MethodInvoker)delegate
                {
                    MessageBox.Show($"Socket error: {ex.Message}");
                });
            }
            catch (Exception ex)
            {
                Invoke((MethodInvoker)delegate
                {
                    MessageBox.Show($"An error occurred: {ex.Message}");
                });
            }
            finally
            {
                socket_connected[port]?.Close(); 
            }
        }


        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            cancellationTokenSource?.Cancel();

            foreach (var socket in socket_connected.Values)
            {
                socket.Close();
            }

            socket_connected.Clear();
        }

        private void SendToClient_Click_1(object sender, EventArgs e)
        {
            try
            {
                if (SaveremoteEndPoint != null && socket_connected.ContainsKey(Int32.Parse(textBox1.Text)))
                {
                   
                    Socket udpSocket = socket_connected[Int32.Parse(textBox1.Text)];

                  
                    string messageToSend = Message.Text;
                    byte[] sendData = Encoding.UTF8.GetBytes(messageToSend);

                    
                    IPEndPoint clientEndPoint = new IPEndPoint(((IPEndPoint)SaveremoteEndPoint).Address, 34556);

                   
                    udpSocket.SendTo(sendData, clientEndPoint);
                    Message.Text = "";
                }
                else
                {
                    MessageBox.Show("Không có client kết nối hoặc chưa nhận được yêu cầu từ client.");
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
    }
}
