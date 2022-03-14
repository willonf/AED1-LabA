package exercicios.montanharussa;

// EXERCÍCIO INCORRETO!!!
// EXERCÍCIO INCORRETO!!!
// EXERCÍCIO INCORRETO!!!
// EXERCÍCIO INCORRETO!!!

import java.util.concurrent.*;

class Passageiro extends Thread {

    private CyclicBarrier cyclicBarrier;

    public Passageiro(int id, CyclicBarrier cyclicBarrier) {
        this.setName("Thread - " + id);
        this.cyclicBarrier = cyclicBarrier;
    }


    @Override
    public void run() {
        String threadName = Thread.currentThread().getName();
        try {
            System.out.println(threadName + " está na fila.");
            cyclicBarrier.await();
        } catch (InterruptedException | BrokenBarrierException e) {
        }
        System.out.println(threadName + " está no carro.");
    }
}

public class MontanhaRussa {
    private CyclicBarrier cyclicBarrier;

    public void runExecutor(int capacidade, int passageiros) {
        ExecutorService executor = Executors.newFixedThreadPool(capacidade);
        for (int i = 0; i < capacidade; i++) {
            executor.submit(new Passageiro(i, cyclicBarrier));
        }
        try {
            System.out.println("Volta inciada!");
            executor.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException ignored) {
        }
        System.out.println("Volta finalizada!");
    }

    public static void main(String[] args) {

        MontanhaRussa demo = new MontanhaRussa();
        demo.runExecutor(3, 6);
    }

}
