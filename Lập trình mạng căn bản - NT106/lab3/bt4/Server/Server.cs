using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices.ComTypes;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Server
{
    public partial class Server : Form
    {
        private TcpListener server;
        private Thread listenerThread;
        private Dictionary<string, TcpClient> clients = new Dictionary<string, TcpClient>();

        public Server()
        {
            InitializeComponent();
        }

        private void btnListen_Click(object sender, EventArgs e)
        {
            // Parse IP and Port
            IPAddress ip = IPAddress.Parse(txtIP.Text);
            int port = int.Parse(txtPort.Text);

            // Start the server
            server = new TcpListener(ip, port);
            server.Start();
            richTextBox1.AppendText("Server started...\n");

            // Start a new thread to listen for incoming connections
            listenerThread = new Thread(ListenForClients);
            listenerThread.IsBackground = true;
            listenerThread.Start();
        }

        private void ListenForClients()
        {
            while (true)
            {
                TcpClient client = server.AcceptTcpClient();
                Thread clientThread = new Thread(() => HandleClientComm(client));
                clientThread.IsBackground = true;
                clientThread.Start();
            }
        }

        private void HandleClientComm(TcpClient client)
        {
            try
            {
                // Get the network stream to read and write data from the client
                NetworkStream clientStream = client.GetStream();
                StreamReader reader = new StreamReader(clientStream);
                StreamWriter writer = new StreamWriter(clientStream);
                writer.AutoFlush = true;

                // First message from client should be the username
                string username = reader.ReadLine();
                lock (clients)
                {
                    clients[username] = client;
                }

                // Log the connection in the richTextBox1
                richTextBox1.Invoke((MethodInvoker)delegate
                {
                    richTextBox1.AppendText($"{username} connected.\n");
                });

                // Listen for messages from the client
                while (client.Connected)
                {
                    string message = reader.ReadLine();
                    if (message == null) break;
                    if (message != null)
                    {
                        string[] messageParts = message.Split('|'); // Format: "Receiver|Message"
                        string receiver = messageParts[0];
                        string chatMessage = messageParts[1];

                        if (string.IsNullOrEmpty(receiver))
                        {
                            BroadcastMessage(username, chatMessage);
                        }
                        else
                        {
                            SendToReceiver(receiver, $"{username}: {chatMessage}");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                richTextBox1.Invoke((MethodInvoker)delegate
                {
                    richTextBox1.AppendText($"Error handling client: {ex.Message}\n");
                });
            }
            finally
            {
                RemoveClient(client);
            }
        }

        private void BroadcastMessage(string sender, string message)
        {
            lock (clients)
            {
                foreach (var client in clients.Values)
                {
                    var username = clients.FirstOrDefault(x => x.Value == client).Key;

                    if (username == sender)
                    {
                        continue;
                    }

                    try
                    {

                        //StreamWriter writer = new StreamWriter(client.GetStream());
                        //writer.AutoFlush = true;
                        //writer.WriteLine($"{sender}: {message}");

                        NetworkStream stream = client.GetStream();
                        StreamWriter writer = new StreamWriter(stream) { AutoFlush = true };
                        writer.WriteLine($"{sender}: {message}");
                    }
                    catch (Exception)
                    {
                        // Handle broken connections
                    }
                }

                // Log the broadcast in the richTextBox1
                richTextBox1.Invoke((MethodInvoker)delegate
                {
                    richTextBox1.AppendText($"Broadcast from {sender}: {message}\n");
                });
            }
        }

        private void SendToReceiver(string receiver, string message)
        {
            lock (clients)
            {
                if (clients.ContainsKey(receiver))
                {
                    try
                    {
                        //StreamWriter writer = new StreamWriter(clients[receiver].GetStream());
                        //writer.AutoFlush = true;
                        //writer.WriteLine(message);

                        NetworkStream stream = clients[receiver].GetStream();
                        StreamWriter writer = new StreamWriter(stream) { AutoFlush = true };
                        writer.WriteLine(message);

                        // Log message sending to receiver
                        richTextBox1.Invoke((MethodInvoker)delegate
                        {
                            richTextBox1.AppendText($"Message sent to {receiver}: {message}\n");
                        });
                    }
                    catch (Exception)
                    {
                        // Handle broken connections
                    }
                }
                else
                {
                    richTextBox1.Invoke((MethodInvoker)delegate
                    {
                        richTextBox1.AppendText($"Receiver {receiver} not found.\n");
                    });
                }
            }
        }
        private void RemoveClient(TcpClient client)
        {
            lock (clients)
            {
                foreach (var pair in clients)
                {
                    if (pair.Value == client)
                    {
                        clients.Remove(pair.Key);
                        richTextBox1.Invoke((MethodInvoker)delegate
                        {
                            richTextBox1.AppendText($"{pair.Key} disconnected.\n");
                        });
                        break;
                    }
                }
            }

            client.Close();
        }

        private void ServerForm_FormClosing_1(object sender, FormClosingEventArgs e)
        {
            lock (clients)
            {
                // Close all client connections
                foreach (var client in clients.Values)
                {
                    try
                    {
                        client.GetStream().Close(); // Close the network stream
                        client.Close(); // Close the TcpClient
                    }
                    catch (Exception ex)
                    {
                        richTextBox1.Invoke((MethodInvoker)delegate
                        {
                            richTextBox1.AppendText($"Error closing client: {ex.Message}\n");
                        });
                    }
                }

                clients.Clear(); // Clear the dictionary
            }

            // Stop the listener if it's running
            if (server != null)
            {
                try
                {
                    server.Stop();
                }
                catch (Exception ex)
                {
                    richTextBox1.Invoke((MethodInvoker)delegate
                    {
                        richTextBox1.AppendText($"Error stopping server: {ex.Message}\n");
                    });
                }
            }
        }
    }
}