package socketsudp;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Random;

public class UDP_Server{

    public final static int PORT = 9000;

    public static void main(String[] args) throws Exception{
        
        DatagramSocket server = new DatagramSocket(PORT);
        Random random_number = new Random();
        byte[] receive = new byte[256];
        byte[] send;

        while(true){
            Arrays.fill(receive, (byte) 0);
            DatagramPacket packetReceived = new DatagramPacket(receive, receive.length);

            server.receive(packetReceived);
            String textReceveid = new String(packetReceived.getData());
            
            InetAddress IPAddress = packetReceived.getAddress();
            int clientPORT = packetReceived.getPort();

            int numRandom = random_number.nextInt(1000);
            String sentText = String.valueOf(numRandom);
            send = sentText.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(send, send.length, IPAddress, clientPORT);
            server.send(sendPacket);
            System.out.println("Sending the number: " + sentText);
            
            Arrays.fill(receive, (byte) 0);
            packetReceived = new DatagramPacket(receive, receive.length);
            server.receive(packetReceived);
            textReceveid = new String(packetReceived.getData());
            int receivedNumber = Integer.parseInt(textReceveid.replaceAll("[\\D]", ""));
            System.out.println("Client number: " + receivedNumber);
            
            int sendNumber = receivedNumber + 2;
            sentText = String.valueOf(sendNumber);
            send = sentText.getBytes();
            sendPacket = new DatagramPacket(send, send.length, IPAddress, clientPORT);
            server.send(sendPacket);
            System.out.println("Sending the number: " + sentText + "\n");
        }
    }
}