package exercicios.depositowaitnotify;


import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Deposito {
    private int qtdeItens = 1;
    private int qtdeMaxim;

    // True if receiver should wait - False if sender should wait
    private boolean transfer = true;

    public Deposito(int qtdeMaxim) {
        this.qtdeMaxim = qtdeMaxim;
    }

    public synchronized void armazenar() { // Sender
        while (!transfer) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        transfer = false;
        if (qtdeItens == qtdeMaxim) {
            System.out.println("Não é possível armazenar. Depósito cheio!");
            return;
        } else {
            System.out.println("Adicionando um item do depósito!");
            this.qtdeItens++;
        }
        notifyAll();

    }

    public synchronized void retirar() { // Receiver
        while (transfer) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        transfer = true;

        notifyAll();
        if (qtdeItens == 0) {
            System.out.println("Não é possível retirar. Depósito vazio!");
            return;
        } else {
            System.out.println("Retirando um item do depósito!");
            this.qtdeItens--;
        }
    }

    public int getQtdeItens() {
        return qtdeItens;
    }
}

class Produtor implements Runnable {
    private Deposito deposito;
    private int tempo;

    public Produtor(Deposito deposito, int tempo) {
        this.deposito = deposito;
        this.tempo = tempo;
    }

    public void run() {

        try {
            Thread.sleep(tempo);
            deposito.armazenar();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumidor implements Runnable {
    private Deposito deposito;
    private int tempo;

    public Consumidor(Deposito deposito, int tempo) {
        this.deposito = deposito;
        this.tempo = tempo;
    }

    public void run() {

        try {
            Thread.sleep(tempo);
            deposito.retirar();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class App1 {
    public static void main(String[] args) {
        Deposito deposito = new Deposito(20);

        ExecutorService executor = Executors.newFixedThreadPool(20);

        for (int i = 0; i < 10; i++) {
            executor.submit(new Produtor(deposito, 300));
            executor.submit(new Consumidor(deposito, 300));

        }
        executor.shutdown();
        System.out.println("Quantidade de itens atuais no depósito: " + deposito.getQtdeItens());
        System.out.println("Iniciando produção e consumo...");

        try {
            executor.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException ignored) {

        }

        System.out.println("Finalizando produção e consumo...");
        System.out.println("Quantidade de itens atuais no depósito: " + deposito.getQtdeItens());
    }
}

