package deadlock;

class T1 implements Runnable
{
    private Object first, second;
    public T1(Object first, Object second) {
        this.first = first;
        this.second = second;
    }
    public void run() {
        synchronized (first) {
            System.out.println("Thread T1: Holding lock 1...");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
            synchronized (second) {
                System.out.println("Thread T1: Holding lock 2...");
            }
        }
    }
}

class T2 implements Runnable
{
    private Object first, second;
    public T2(Object first, Object second) {
        this.first = first;
        this.second = second;
    }

    public void run() {
        synchronized (second) {
            System.out.println("Thread T2: Holding lock 2...");
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {}
            synchronized (first) {
                System.out.println("Thread T2: Holding lock 1...");
            }
        }
    }
}

public class App1 {
    public static void main(String arg[]) throws InterruptedException {
        Object lock1 = new Object();
        Object lock2 = new Object();
        Thread threadA = new Thread(new T1(lock1,lock2));
        Thread threadB = new Thread(new T2(lock1,lock2));
        threadA.start();
        threadB.start();
        threadA.join();
        threadB.join();
        System.out.println("Finished");
    }
}