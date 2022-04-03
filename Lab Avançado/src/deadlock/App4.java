package deadlock;

class Flintstone implements Runnable {
    private int option;
    private Object lock_1;
    private Object lock_2;


    public Flintstone (Object lock_1, Object lock_2, int option) {
        this.lock_1 = lock_1;
        this.lock_2 = lock_2;
        this.option = option;
    }

    public void fred() {
        synchronized(lock_1) {
            System.out.println("Fred: Holding lock 1...");
            synchronized(lock_2) {
                System.out.println("Fred: Holding lock 2...");
            }
        }
    }

    public void barney () {
        synchronized(lock_2) {
            System.out.println("Barney: Holding lock 2...");
            synchronized(lock_1) {
                System.out.println("Barney: Holding lock 1...");
            }
        }
    }

    public void run() {
        if (option==1) fred();
        if (option==2) barney();
    }
}

public class App4 {
    public static void main(String arg[]) throws InterruptedException {
        Object lock1 = new Object();
        Object lock2 = new Object();
        Thread wilma = new Thread(new Flintstone(lock1, lock2, 1));
        Thread betty = new Thread(new Flintstone(lock1, lock2, 2));

        wilma.start();
        betty.start();
        wilma.join();
        betty.join();

        System.out.println("Finished");
    }
}