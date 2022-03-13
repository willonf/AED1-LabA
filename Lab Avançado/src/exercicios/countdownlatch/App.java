package exercicios.countdownlatch;


import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Deposito {
    private int qtdeItems = 0;
    private int capacidade;

    public Deposito(int capacidade) {
        this.capacidade = capacidade;
    }

    void armazenar() {
        System.out.println("Tentando armazenar uma caixa no depósito...");
        if (this.getQtdeItems() < this.getCapacidade()) {
            this.setQtdeItems(this.getQtdeItems() + 1);
            System.out.println("Armazenada - Caixas no Deposito: " + this.getQtdeItems());
            System.out.println("Caixa armazenada\n");
        } else {
            System.out.println("Não foi possível armazenar...\n");
        }
    }

    void retirar() {
        System.out.println("Tentando retirar uma caixa no depósito...");
        if (this.getQtdeItems() > 0) {
            this.setQtdeItems(this.getQtdeItems() - 1);
            System.out.println("Retirada - Caixas no Deposito: " + this.getQtdeItems());
            System.out.println("Caixa retirada\n");
        } else {
            System.out.println("Não foi possível retirar...\n");
        }
    }

    public int getQtdeItems() {
        return qtdeItems;
    }

    public void setQtdeItems(int qtdeItems) {
        this.qtdeItems = qtdeItems;
    }

    public int getCapacidade() {
        return capacidade;
    }
}

class Produtor implements Runnable {

    private Deposito deposito;
    private int tempo;
    private CountDownLatch latch;
    int MAX = 5;
    int count = 0;

    public Produtor(Deposito deposito, int tempo, CountDownLatch latch) {
        this.deposito = deposito;
        this.tempo = tempo;
        this.latch = latch;
    }

    @Override
    public void run() {
        System.out.println("Produção iniciada...");
        while (count < MAX) {
            this.deposito.armazenar();
            count++;
            try {
                Thread.sleep(this.tempo);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(latch.getCount());
        latch.countDown();
        System.out.println(latch.getCount());
        System.out.println("Produção finalizada");
    }
}

class Consumidor extends Thread {
    private Deposito deposito;
    private int tempo;
    private CountDownLatch latch;
    int MAX = 5;
    int count = 0;

    public Consumidor(Deposito deposito, int tempo, CountDownLatch latch) {
        this.deposito = deposito;
        this.tempo = tempo;
        this.latch = latch;
    }

    public void run() {

        while (count < MAX) {
            this.deposito.retirar();
            count++;
        }
    }

}

public class App {
    public static void main(String[] args) {
        System.out.println("Waiting threads to finish...");
        int N = 1;
        CountDownLatch latch = new CountDownLatch(N);
        ExecutorService executor = Executors.newFixedThreadPool(2 * N);
        Deposito deposito = new Deposito(5);
        Produtor produtor = new Produtor(deposito, 1, latch);
        Consumidor consumidor = new Consumidor(deposito, 1, latch);

        for (int i = 0; i < 5; i++) {
            executor.submit(produtor);
        }
        executor.shutdown();
        try {
            latch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Threads finished...");
        consumidor.start();

    }
}