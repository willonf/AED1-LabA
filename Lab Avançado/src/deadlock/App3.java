package deadlock;

import java.util.concurrent.locks.ReentrantLock;

class A implements Runnable
{
    private ReentrantLock first, second;
    public A(ReentrantLock first, ReentrantLock second) {
        this.first = first;
        this.second = second;
    }
    public void run() {
        try {
            first.lock();
            System.out.println("Thread A: Holding lock 1...");
            second.lock();
            System.out.println("Thread A: Holding lock 2...");
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        finally {
            first.unlock();
            second.unlock();
        }
    }
}
class B implements Runnable
{
    private ReentrantLock first, second;
    public B(ReentrantLock first, ReentrantLock second) {
        this.first = first;
        this.second = second;
    }
    public void run() {
        try {
            first.lock();
            System.out.println("Thread B: Holding lock 1...");
            second.lock();
            System.out.println("Thread B: Holding lock 2...");
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        finally {
            second.unlock();
            first.unlock();
        }
    }
}
public class App3 {
    public static void main(String arg[]) throws InterruptedException {
        ReentrantLock lock1 = new ReentrantLock();
        ReentrantLock lock2 = new ReentrantLock();
        Thread threadA = new Thread(new A(lock1,lock2));
        Thread threadB = new Thread(new B(lock1,lock2));
        threadA.start();
        threadB.start();
        threadA.join();
        threadB.join();
        System.out.println("Finished");
    }
}