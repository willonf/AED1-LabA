package exercicios.jantarfilosofos1;

// JANTAR DOS FILÓSOFOS (COM DEADLOCKS)

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

class Filosofo extends Thread {
    private int numero;
    private Semaphore hashiEsquerdo;
    private Semaphore hashiDireito;

    public Filosofo(int numero, Semaphore hashiEsquerdo, Semaphore hashiDireito) {
        this.numero = numero;
        this.hashiEsquerdo = hashiEsquerdo;
        this.hashiDireito = hashiDireito;
    }

    public void pensar() {
        System.out.printf("O filósofo %d pensou\n", this.numero);
    }

    public void comer() {
        System.out.printf("O filósofo %d comeu\n", this.numero);
    }

    @Override
    public void run() {
        int time = new Random().nextInt(100, 800);
        try {
            while (true) {
                this.pensar();
                boolean comeu = false;
                Thread.sleep(time);
                do {
                    hashiEsquerdo.acquire();
                    boolean pegou = hashiDireito.tryAcquire(time, TimeUnit.MILLISECONDS);
                    if (pegou) {
                        this.comer();
                        comeu = true;
                        Thread.sleep(time);
                        hashiDireito.release();
                        hashiEsquerdo.release();
                    } else {
                        hashiEsquerdo.release();
                        Thread.sleep(time);
                    }
                } while (!comeu);
            }
        } catch (InterruptedException ignored) {
        }
    }
}

public class App1 {

    public static void main(String[] args) {
        Semaphore garfo0 = new Semaphore(1);
        Semaphore garfo1 = new Semaphore(1);
        Semaphore garfo2 = new Semaphore(1);
        Semaphore garfo3 = new Semaphore(1);
        Semaphore garfo4 = new Semaphore(1);
        ExecutorService executor = Executors.newFixedThreadPool(5);

        executor.submit(new Filosofo(0, garfo0, garfo1));
        executor.submit(new Filosofo(1, garfo1, garfo2));
        executor.submit(new Filosofo(2, garfo2, garfo3));
        executor.submit(new Filosofo(3, garfo3, garfo4));
        executor.submit(new Filosofo(4, garfo4, garfo0));

        executor.shutdown();

        try {
            executor.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException ignored) {
        }
    }
}
