package exercicios.socketinteiros;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;

import socketstcp.Vetores;

class ClientRunnable implements Runnable {

    protected Socket clientSocket = null;
    int scalar;

    public ClientRunnable(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    public void run() {
        try {
            ObjectOutputStream output = new ObjectOutputStream(clientSocket.getOutputStream());
            ObjectInputStream input = new ObjectInputStream(clientSocket.getInputStream());
            Vetores serverData = (Vetores) input.readObject();
            System.out.println(Arrays.toString(serverData.getVetor1()));
            System.out.println(Arrays.toString(serverData.getVetor2()));

            for (int i = 0; i < serverData.getVetor1().length; i++) {
                scalar += serverData.getVetor1()[i] * serverData.getVetor2()[i];
            }

            output.writeObject(scalar);
            output.close();
        } catch (IOException ignored) {
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class TCP_ArrayServer {
    public final static int PORT = 9000;
    protected static ServerSocket serverSocket = null;

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        serverSocket = new ServerSocket(PORT);
        while (true) {
            Socket clientSocket = serverSocket.accept();
            new Thread(new ClientRunnable(clientSocket)).start();
        }

    }
}

