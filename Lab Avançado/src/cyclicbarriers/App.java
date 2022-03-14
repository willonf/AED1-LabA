package cyclicbarriers;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

class One extends Thread {
    CyclicBarrier barrier;

    public One(CyclicBarrier barrier) {
        this.barrier = barrier;
    }

    public void run() {
        try {
            barrier.await();
        } catch (InterruptedException | BrokenBarrierException e) {
        }
        System.out.println("Thread One begins...");
    }
}

class Two extends Thread {
    CyclicBarrier barrier;

    public Two(CyclicBarrier barrier) {
        this.barrier = barrier;
    }

    public void run() {
        try {
            barrier.await();
        } catch (InterruptedException | BrokenBarrierException e) {
        }
        System.out.println("Thread Two begins...");
    }
}

public class App {
    public static void main(String[] args) {
        CyclicBarrier barrier = new CyclicBarrier(2); // 2 = Qtde. de threads
        System.out.println("Aguardando passageiros...");

        System.out.println("Iniciando a volta na montanha russa!");
        try {
            Thread.sleep(5000);
        } catch (InterruptedException ignored){}
        System.out.println("A volta na Montanha Russa foi completada!");
    }
}
