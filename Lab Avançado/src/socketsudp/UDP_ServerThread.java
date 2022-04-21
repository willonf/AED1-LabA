package socketsudp;

import java.io.*;
import java.net.*;
import java.util.*;

class ClientRunnable implements Runnable {
    protected DatagramSocket clientSocket;
    protected DatagramPacket sendPacket, receivePacket;
    protected String message;
    protected InetAddress IPAddress;
    protected int port;
    protected byte[] sendData = new byte[256];

    public ClientRunnable(DatagramPacket receivePacket) {
        message = new String(receivePacket.getData());
        System.out.println("Dentro da Thread - Mensagem recebida: " + message);
        IPAddress = receivePacket.getAddress();    // endereco do cliente
        port = receivePacket.getPort();              // porta do cliente
    }

    public void run() {
        try {
            // Preparando a mensagem
            String capitalizedSentence = message.toUpperCase();
            System.out.println("Dentro da Thread - Mensagem a ser enviada: " + capitalizedSentence);
            sendData = capitalizedSentence.getBytes();

            // Preparando o pacote
            sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);

            // Enviando o pacote
            clientSocket = new DatagramSocket();
            clientSocket.send(sendPacket);
            System.out.println("Dentro da Thread - Fechando o socket");
            clientSocket.close();
        } catch (IOException e) {}
    }
}

class UDP_ServerThread {
    public final static int ServerPort = 9876;
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(ServerPort);

        byte[] receiveData = new byte[256];
        byte[] sendData = new byte[256];

        while (true) {
            // Especificando o pacote
            System.out.println("Fora Thread - Esperando por datagrama na porta " + ServerPort);
            Arrays.fill(receiveData, (byte)0);
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

            // Recebendo o pacote
            serverSocket.receive(receivePacket);
            System.out.println("Fora Thread - Datagrama UDP recebido: ");

            // Iniciando uma thread
            System.out.println ("Fora Thread - Iniciando uma Thread...");
            new Thread(new ClientRunnable(receivePacket)).start();

        }
    }
}
