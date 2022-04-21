package socketstcp;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;
import java.util.Date;

public class TCP_ObjDateClient {
    public final static int PORT = 2222;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        String hostname = args.length > 0 ? args[0] : "localhost";
        Socket client = new Socket(hostname, PORT);
        ObjectInputStream input = new ObjectInputStream(client.getInputStream());
        Point serverData = (Point) input.readObject();
        input.close();
        System.out.println(serverData);
        System.out.println(serverData.getX());
        System.out.println(serverData.getY());
        client.close();

    }
}
