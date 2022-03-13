package countdownlatch;


import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Processor implements Runnable {
    private CountDownLatch latch;
    public Processor(CountDownLatch latch) {
        this.latch = latch;
    }
    public void run() {
        System.out.println("Thread started");
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ignored) {}
        latch.countDown();
        System.out.println("Thread finished");
    }
}

public class App1 {
    public static void main(String[] args) {
        System.out.println("Waiting three threads to finish");
        CountDownLatch latch = new CountDownLatch(3);
        ExecutorService executor = Executors.newFixedThreadPool(3);
        for (int i = 0; i < 3; i++) {
            executor.submit(new Processor(latch));
        }
        executor.shutdown();
        try {
            latch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Three threads finished... Go on!");
    }
}
