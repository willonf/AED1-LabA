package socketsudp;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDP_Client{

    public final static int PORT = 9000;

    public static void main(String[] args) throws Exception{

        DatagramSocket client = new DatagramSocket();

        String hostname = args.length > 0 ? args[0] : "localhost";
        InetAddress IPAddress = InetAddress.getByName(hostname);

        String sendString = "Start!";
        byte[] sendData = new byte[256];
        byte[] receivedData = new byte[256];
        sendData = sendString.getBytes();

        DatagramPacket send = new DatagramPacket(sendData, sendData.length, IPAddress, PORT);

        client.send(send);

        DatagramPacket receive = new DatagramPacket(receivedData, receivedData.length);
        client.receive(receive);
        String integerNumber = new String(receive.getData());
        int number = Integer.parseInt(integerNumber.replaceAll("[\\D]", ""));
        System.out.println("Receveid number: " + number);

        sendString = String.valueOf(number + 1);
        sendData = sendString.getBytes();
        send = new DatagramPacket(sendData, sendData.length, IPAddress, PORT);
        client.send(send);
        System.out.println("Sending the number: " + ++number);

        receive = new DatagramPacket(receivedData, receivedData.length);
        client.receive(receive);
        integerNumber = new String(receive.getData());
        number = Integer.parseInt(integerNumber.replaceAll("[\\D]", ""));
        System.out.println("Receveid number: " + number);

        client.close();
    }
}