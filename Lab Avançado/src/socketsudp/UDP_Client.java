package socketsudp;

import java.io.*;
import java.net.*;
import java.util.*;

class UDP_Client {
    public final static int porta = 9876;
    public static void main(String args[]) throws Exception {
        Scanner input = new Scanner (System.in);
        byte[] sendData = new byte[256];
        byte[] receiveData = new byte[256];

        // Gerando o socket UDP
        DatagramSocket clientSocket = new DatagramSocket();

        // Gerando o endereço IP do servidor
        String hostname = args.length > 0 ? args[0] : "localhost";
        InetAddress IPAddress = InetAddress.getByName(hostname);

        // Preparando a mensagem a ser enviada ao servidor
        System.out.print("Texto a ser enviado ao servidor: ");
        String sentence = input.nextLine();
        sendData = sentence.getBytes();

        // Preparando o pacote
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, porta);

        // Enviando o pacote
        System.out.println("Enviando pacote UDP para " + hostname + ":" + porta);
        clientSocket.send(sendPacket);

        // Esperando receber um pacote do servidor
        System.out.println("Aguardando receber um pacote de " + hostname);

        // Preparando o pacote
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

        // Recebendo o pacote
        clientSocket.receive(receivePacket);

        // Tratando o pacote recebido
        String modifiedSentence = new String(receivePacket.getData());
        System.out.println("Pacote UDP recebido: " + modifiedSentence);

        // Fechando a comunicacao via socket
        clientSocket.close();
        System.out.println("Socket cliente fechado!");
    }
}