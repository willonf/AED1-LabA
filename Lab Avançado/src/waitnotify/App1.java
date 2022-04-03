package waitnotify;

class Data {
    private String packet;

    // True if receiver should wait - False if sender should wait
    private boolean transfer = true;

    public synchronized void send(String packet) {
        while (!transfer) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }
        transfer = false;

        this.packet = packet;
        notifyAll();
    }

    public synchronized String receive() {
        while (transfer) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }
        transfer = true;

        notifyAll();
        return packet;
    }
}

class Sender implements Runnable {
    private Data data;

    public Sender (Data data) {
        this.data = data;
    }

    public void run() {
        String[] packets = {
                "First packet",
                "Second packet",
                "Third packet",
                "Fourth packet",
                "End"
        };

        for (String packet : packets) {
            data.send(packet);
            System.out.println("Sent: " + packet);

            try {
                Thread.sleep(300);
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class Receiver implements Runnable {
    private Data load;

    public Receiver (Data load) {
        this.load = load;
    }

    public void run() {
        for(String receivedMessage = load.receive(); !"End".equals(receivedMessage);
            receivedMessage = load.receive()) {

            System.out.println("Received: " + receivedMessage);

            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class App1 {
    public static void main(String[] args) {
        Data data = new Data();
        Thread sender = new Thread(new Sender(data));
        Thread receiver = new Thread(new Receiver(data));

        sender.start();
        receiver.start();
    }
}