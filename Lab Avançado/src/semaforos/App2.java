package semaforos;

import java.util.concurrent.*;

public class App2 {
    static int count = 0;

    static class AddSubThread extends Thread {
        String threadName;
        Semaphore sem;
        char op;

        public AddSubThread(Semaphore sem, String threadName, char op) {
            this.sem = sem;
            this.threadName = threadName;
            this.op = op;
        }

        public void run() {
            System.out.println("Starting Thread: " + threadName);
            try {
                System.out.println("Thread " + threadName + " is waiting for a permit.");
                sem.acquire();
                System.out.println("Thread " + threadName + " gets a permit.");
                for (int i = 0; i < 5; i++) {
                    if (op == '+') count++;
                    else count--;
                    System.out.println("Thread " + threadName + ": " + count);
                    Thread.sleep(10);
                }
            } catch (InterruptedException exc) {}
            System.out.println("Thread " + threadName + " releases the permit.");
            sem.release();
        }
    }

    public static void main(String args[]) throws InterruptedException {
        Semaphore sem = new Semaphore(1);
        AddSubThread t2 = new AddSubThread(sem, "Sub", '-');
        AddSubThread t1 = new AddSubThread(sem, "Add", '+');

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("count: " + count);
    }
}
