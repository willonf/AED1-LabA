package exercicios.socketinteiros;


import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class TCPObjIntegerClient {
    public final static int PORT = 9000;

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        String hostname = args.length > 0 ? args[0] : "localhost";
        Socket client = new Socket(hostname, PORT);
        ObjectInputStream in = new ObjectInputStream(client.getInputStream());
        ObjectOutputStream out = new ObjectOutputStream(client.getOutputStream());

        while(true){
            // Recebendo número
            int serverData = (int) in.readObject();
            System.out.println("Receveid: " + serverData);
            Thread.sleep(1000);
            // Enviando número + 1
            serverData += 1;
            System.out.println("Sending: " + serverData);
            out.writeObject(serverData);

            // Recebendo número + 2
            serverData = ((int) in.readObject());
            System.out.println("Receveid: " + serverData);

            in.close();
            out.close();
            client.close();
        }

    }
}
