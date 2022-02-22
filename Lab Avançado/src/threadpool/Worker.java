package threadpool;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Worker implements Runnable {
    private Random random = new Random();
    private final Object lock1 = new Object();
    private final Object lock2 = new Object();
    public List<Integer> list1 = new ArrayList<>();
    public List<Integer> list2 = new ArrayList<>();


    @Override
    public void run() {
        process();
    }

    public void process() {
        System.out.println("Starting a thread...");
        for (int i = 0; i < 1000; i++) {
            stageOne();
            stageTwo();
        }
        System.out.println("Finishing a thread...");
    }

    public void stageOne() {
        synchronized (lock1) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
            }
            list1.add(random.nextInt(100));
        }
    }

    public void stageTwo() {
        synchronized (lock2) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
            }
            list2.add(random.nextInt(100));
        }
    }
}
