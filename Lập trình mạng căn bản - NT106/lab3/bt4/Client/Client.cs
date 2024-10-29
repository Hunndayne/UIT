using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Net;


namespace Client
{
    public partial class Client : Form
    {
        private TcpClient client;
        private StreamReader reader;
        private StreamWriter writer;
        private Thread listenThread;
        bool connected = false;
        public Client()
        {
            InitializeComponent();
        }

        private void btnConnect_Click_1(object sender, EventArgs e)
        {
            try
            {
                IPAddress ip = IPAddress.Parse(txtIP.Text);
                int port = int.Parse(txtPort.Text);

                // Connect to server
                client = new TcpClient();
                client.Connect(ip, port);

                // Initialize reader and writer for the client
                NetworkStream stream = client.GetStream();
                reader = new StreamReader(stream);
                writer = new StreamWriter(stream) { AutoFlush = true };

                // Send username to server
                writer.WriteLine(txtUsr.Text);
                connected = true;

                richTextBox1.AppendText("Connected to server.\n");

                // Start listening for messages from server
                listenThread = new Thread(ListenForMessages);
                listenThread.Start();
            }
            catch (Exception ex)
            {
                richTextBox1.AppendText($"Error: {ex.Message}\n");
            }
        }

        private void ListenForMessages()
        {
            try
            {
                while (client.Connected)
                {
                    string incomingMessage = reader.ReadLine();
                    if (incomingMessage != null)
                    {
                        richTextBox1.Invoke((MethodInvoker)delegate
                        {
                            richTextBox1.AppendText(incomingMessage + "\n");
                        });
                    }
                }
            }
            catch (IOException)
            {
                // Connection lost
                richTextBox1.Invoke((MethodInvoker)delegate
                {
                    richTextBox1.AppendText("Disconnected from server.\n");
                });
            }
            catch (Exception ex)
            {
                richTextBox1.Invoke((MethodInvoker)delegate
                {
                    richTextBox1.AppendText($"Error: {ex.Message}\n");
                });
            }
            finally
            {
                // Clean up after disconnect
                client?.Close();
            }
        }

        private void btnSend_Click_1(object sender, EventArgs e)
        {
            if (client != null && client.Connected)
            {
                // Send message in the format "Receiver|Message"
                string message = txtRecv.Text + "|" + txtMessage.Text;
                writer.WriteLine(message);

                richTextBox1.AppendText($"You: {txtMessage.Text}\n");
                txtMessage.Clear();
            }
            else
            {
                richTextBox1.AppendText("Not connected to server.\n");
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (client != null)
            {
                try
                {
                    if (connected && client.Connected)
                    {
                        // Close the stream first, then the client
                        writer.Close();
                        reader.Close();
                        client.GetStream().Close();
                        client.Close();
                    }
                    connected = false;

                    richTextBox1.AppendText("Disconnected from server.\n");
                }
                catch (Exception)
                {

                }
            }
        }


    }
}
