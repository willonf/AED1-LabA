package deadlock;

import java.util.concurrent.locks.*;

public class App2 {

    static Lock lock1 = new ReentrantLock();
    static Lock lock2 = new ReentrantLock();

    public static void acquire(Lock firstLock, Lock secondLock) throws InterruptedException {
        while (true) {
            boolean gotFirstLock = false;
            boolean gotSecondLock = false;
            try {
                gotFirstLock = firstLock.tryLock();
                gotSecondLock = secondLock.tryLock();
            }
            finally {
                if (gotFirstLock && gotSecondLock) return;
                else if (gotFirstLock) firstLock.unlock();
                else if (gotSecondLock) secondLock.unlock();
            }
        }
    }

    public static void release(Lock firstLock, Lock secondLock) {
        firstLock.unlock();
        secondLock.unlock();
    }

    static class T3 extends Thread
    {
        public void run() {
            System.out.println("Thread T3: Trying to hold both locks...");
            try {
                acquire(lock1, lock2);
                System.out.println("Thread T3: Hold all locks!");
                Thread.sleep(1);
                release(lock1, lock2);
            } catch (InterruptedException e) {}
            System.out.println("Thread T3: Finished");
        }
    }

    static class T4 extends Thread
    {
        public void run() {
            System.out.println("Thread T4: Trying to hold both locks...");
            try {
                acquire(lock2, lock1);
                System.out.println("Thread T4: Hold all locks!");
                Thread.sleep(1);
                release(lock2, lock1);
            } catch (InterruptedException e) {}
            System.out.println("Thread T4: Finished");
        }
    }

    public static void main(String arg[]) throws InterruptedException {

        T3 thread3 = new T3();
        T4 thread4 = new T4();
        thread3.start(); thread4.start();
        thread3.join();	thread4.join();
        System.out.println("Finished");
    }
}