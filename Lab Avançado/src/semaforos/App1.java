package semaforos;

import java.util.concurrent.Semaphore;

class PrintThread extends Thread {
    int id;
    Semaphore semaphore;

    PrintThread(int id, Semaphore semaphore) {
        this.id = id;
        this.semaphore = semaphore;
    }

    public void run() {
        try {
            semaphore.acquire();
            System.out.println("Printer " + id + " is printing...");
            Thread.sleep(2000);
            System.out.println("Printer " + id + " releasing semaphore...");
            semaphore.release();
        } catch(InterruptedException e) {}
    }
}

public class App1 {
    public static void main(String [] args) {
        Semaphore semaphore = new Semaphore(2);
        for (int i=0; i<10; i++)
            new PrintThread(i, semaphore).start();
    }
}