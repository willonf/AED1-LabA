package socketsudp;

import java.io.*;
import java.net.*;
import java.util.*;

class UDP_Server {
    public final static int ServerPort = 9876;
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(ServerPort);

        byte[] receiveData = new byte[256];
        byte[] sendData = new byte[256];

        while (true) {
            // Especificando o pacote
            System.out.println("Esperando por datagrama UDP na porta " + ServerPort);
            Arrays.fill(receiveData, (byte)0);
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

            // Recebendo o pacote
            serverSocket.receive(receivePacket);
            String sentence = new String(receivePacket.getData());
            System.out.println("Datagrama UDP recebido: " + sentence);

            // Preparando endereco para onde enviar o pacote
            InetAddress IPAddress = receivePacket.getAddress();    // endereco do cliente
            int ClientPort = receivePacket.getPort();              // porta do cliente
            System.out.println("Server Port: " + ServerPort + " Client Port: " + ClientPort);
            // Preparando a mensagem que vai estar no pacote
            String capitalizedSentence = sentence.toUpperCase();
            sendData = capitalizedSentence.getBytes();
            // Contruindo o pacote
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, ClientPort);
            System.out.println("Enviando " + capitalizedSentence);
            // Enviando o pacote
            serverSocket.send(sendPacket);
        }
    }
}
