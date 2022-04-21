package exercicios.socketinteiros;


import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;


public class TCPObjIntegerServer {
    public final static int PORT = 9000;

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        ServerSocket server = new ServerSocket(PORT);

        int number = new Random().nextInt(0, 10);
        System.out.println("Initial number: " + number);


        while (true) {
            Socket client = server.accept();
            System.out.println("Client connected!");
            ObjectOutputStream out = new ObjectOutputStream(client.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(client.getInputStream());

            // Enviando número
            System.out.println("Sending: " + number);
            out.writeObject(number);

            // Recebendo número + 1
            number = (int) in.readObject();
            System.out.println("Receveid: " + number);

            // Enviando número + 2
            number += 2;
            out.writeObject(number);
            System.out.println("Sending: " + number);
            in.close();
            out.close();
            client.close();
        }
    }
}
