package threadpool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class App1 {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);

        for (int i = 0; i < 5; i++){
            executor.submit(new Processor(i));
        }

        executor.shutdown();

        System.out.println("All five tasks submitted.");
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException ignored){

        }
        System.out.println("All five tasks completed!");
    }
}
