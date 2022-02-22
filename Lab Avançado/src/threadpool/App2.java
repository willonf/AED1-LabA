package threadpool;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class App2 {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);
        long start = System.currentTimeMillis();
        Worker worker = new Worker();

        for (int i = 0; i < 5; i++){
            executor.submit(worker);
        }

        executor.shutdown();

        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException ex){
            System.out.println(ex.getMessage());
        }

        long end = System.currentTimeMillis();
        System.out.println("Time taken: " + (end - start));
        System.out.printf("List 1: %d; List 2: %d\n", worker.list1.size(), worker.list2.size());
    }
}
