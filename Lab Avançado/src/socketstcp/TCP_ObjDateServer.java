package socketstcp;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

class Point implements Serializable {
    private float x, y;

    Point(float a, float b) {
        this.x = a;
        this.y = b;
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    @Override
    public String toString() {
        return "Point{" +"x=" + this.x +", y=" + this.y +'}';
    }
}


public class TCP_ObjDateServer {
    public final static int PORT = 2222;

    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(PORT);
        float x = (float) 10.3;
        float y = (float) 21.12;

        while (true) {
            Socket client = server.accept();
            System.out.println("Client connected!");
            ObjectOutputStream out = new ObjectOutputStream(client.getOutputStream());
            out.writeObject(new Point(x, y));
            out.close();
            client.close();
        }
    }
}
