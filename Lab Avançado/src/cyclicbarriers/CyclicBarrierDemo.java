package cyclicbarriers;

// Com método automático

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class CyclicBarrierDemo {
    private CyclicBarrier cyclicBarrier;
    List<List<Integer>> partialResults = Collections.synchronizedList(new ArrayList<>());
    private Random random = new Random();
    private int NUM_PARTIAL_RESULTS;
    private int NUM_WORKERS;

    class NumberGenThread implements Runnable {
        @Override
        public void run() {
            String threadName = Thread.currentThread().getName();
            List<Integer> partialResult = new ArrayList<>();

            for (int i = 0; i < NUM_PARTIAL_RESULTS; i++) {
                Integer num = random.nextInt(10);
                System.out.println(threadName + ": number: " + num);
                partialResult.add(num);
            }

            partialResults.add(partialResult);

            try {
                System.out.println(threadName + " finished: " + partialResult);
                System.out.println(threadName + " waiting for barrier...");
                cyclicBarrier.await();
            } catch (InterruptedException | BrokenBarrierException e) {
            }
        }
    }

    class AggreagatorThread implements Runnable {
        @Override
        public void run() {
            String threadName = Thread.currentThread().getName();
            System.out.println(threadName + ": Computing sum");
            int sum = 0;
            for (List<Integer> threadResult : partialResults) {
                System.out.println("Adding...");
                for (Integer partialResult : threadResult) {
                    System.out.println(partialResult + " ");
                    sum += partialResult;
                }
                System.out.println();
            }
            System.out.println(threadName + ": Final result = " + sum);
        }
    }

    public void runExecutor(int numWorkers, int numPartialResults) {
        NUM_PARTIAL_RESULTS = numPartialResults;
        NUM_WORKERS = numWorkers;
        cyclicBarrier = new CyclicBarrier(NUM_WORKERS, new AggreagatorThread());
        System.out.println("Generating " + NUM_WORKERS + " threads to compute " + NUM_PARTIAL_RESULTS + " partial results each");

        for (int i = 0; i < NUM_WORKERS; i++) {
            Thread worker = new Thread(new NumberGenThread());
            worker.setName("Thread-" + i);
            worker.start();
        }
    }

    public static void main(String[] args) {
        CyclicBarrierDemo demo = new CyclicBarrierDemo();
        demo.runExecutor(5, 3);
    }

}
