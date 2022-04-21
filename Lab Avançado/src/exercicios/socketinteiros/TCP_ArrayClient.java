package exercicios.socketinteiros;

import socketstcp.Vetores;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class TCP_ArrayClient {
    public final static int PORT = 9000;

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        String hostname = args.length > 0 ? args[0] : "localhost";
        Socket client = new Socket(hostname, PORT);
        ObjectInputStream in = new ObjectInputStream(client.getInputStream());
        ObjectOutputStream out = new ObjectOutputStream(client.getOutputStream());

        Vetores vetores = new Vetores();
        int scalar;


        // Enviando o objeto
        System.out.println("Sending the object...");
        out.writeObject(vetores);

        scalar = (int) in.readObject();
        System.out.println("Receveid: " + scalar);

        in.close();
        out.close();
        client.close();


    }
}
