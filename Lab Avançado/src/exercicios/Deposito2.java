package exercicios;

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


public class Deposito2 {
    private int qtdeItems = 0;
    private int capacidade;
    private final Object lock1 = new Object();
    private final Object lock2 = new Object();

    public Deposito2(int capacidade) {
        this.capacidade = capacidade;
    }

    void armazenar() {  // "Stage one"
        synchronized (lock1) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Tentando armazenar uma caixa no depósito...");
            if (this.getQtdeItems() <= this.getCapacidade()) {
                this.setQtdeItems(this.getQtdeItems() + 1);
                System.out.println("Armazenada - Caixas no Deposito: " + this.getQtdeItems());
                System.out.println("Caixa armazenada\n");
            } else {
                System.out.println("Não foi possível armazenar...\n");
            }
        }

    }

    void retirar() {   // "Stage two"
        synchronized (lock2) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Tentando retirar uma caixa no depósito...");
            if (this.getQtdeItems() > 0) {
                this.setQtdeItems(this.getQtdeItems() - 1);
                System.out.println("Retirada - Caixas no Deposito: " + this.getQtdeItems());
                System.out.println("Caixa retirada\n");
            } else {
                System.out.println("Não foi possível retirar...\n");
            }
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

class App {
    static class Produtor implements Runnable {

        private Deposito2 deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Produtor(Deposito2 deposito, int tempo) {
            this.deposito = deposito;
            this.tempo = tempo;
        }

        @Override
        public void run() {
            this.deposito.armazenar();
            try {
                Thread.sleep(this.tempo);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Consumidor implements Runnable {
        private Deposito2 deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Consumidor(Deposito2 deposito, int tempo) {
            this.deposito = deposito;
            this.tempo = tempo;
        }

        @Override
        public void run() {
            this.deposito.retirar();
            try {
                Thread.sleep(this.tempo);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public static void main(String[] args) {
        Deposito2 dep = new Deposito2(20);
        ExecutorService executor = Executors.newFixedThreadPool(5);
        Produtor prod;
        Consumidor consum;
        Random random = new Random();


        for (int i = 0; i < 20; i++) {
            prod = new Produtor(dep, random.nextInt(200));
            consum = new Consumidor(dep, random.nextInt(200));
            executor.submit(prod);
            executor.submit(consum);
        }


        executor.shutdown();
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException ignored) {}
        System.out.println(dep.getQtdeItems());

    }

}


