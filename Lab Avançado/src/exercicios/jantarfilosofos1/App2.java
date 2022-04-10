package exercicios.jantarfilosofos1;

// JANTAR DOS FILÓSOFOS (COM DEADLOCKS)
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

class Filosofo1 extends Thread {
    private int numero;
    private Semaphore hashiEsquerdo;
    private Semaphore hashiDireito;

    public Filosofo1(int numero, Semaphore hashiEsquerdo, Semaphore hashiDireito) {
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
                Thread.sleep(time);
                hashiEsquerdo.acquire();
                hashiDireito.acquire();
                this.comer();
                Thread.sleep(time);
                hashiEsquerdo.release();
                hashiDireito.release();

            }
        } catch (InterruptedException ignored) {
        }
    }
}

public class App2 {

    public static void main(String[] args) {
        Semaphore garfo0 = new Semaphore(1);
        Semaphore garfo1 = new Semaphore(1);
        Semaphore garfo2 = new Semaphore(1);
        Semaphore garfo3 = new Semaphore(1);
        Semaphore garfo4 = new Semaphore(1);
        ExecutorService executor = Executors.newFixedThreadPool(5);

        executor.submit(new Filosofo1(0, garfo0, garfo1));
        executor.submit(new Filosofo1(1, garfo1, garfo2));
        executor.submit(new Filosofo1(2, garfo2, garfo3));
        executor.submit(new Filosofo1(3, garfo3, garfo4));
        executor.submit(new Filosofo1(4, garfo4, garfo0));

        executor.shutdown();

        try {
            executor.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException ignored) {
        }
    }
}
