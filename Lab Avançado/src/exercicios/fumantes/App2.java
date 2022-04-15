package exercicios.fumantes;

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;

class Agente extends Thread {
    public Semaphore papel = new Semaphore(1);
    public Semaphore tabaco = new Semaphore(1);
    public Semaphore fosforo = new Semaphore(1);


    @Override
    public void run() {
        // 1 -> Colocar TABACO e FÓSFORO na mesa
        // 2 -> Colocar PAPEL e FÓSFORO na mesa
        // 3 -> Colocar PAPEL e TABACO na mesa

        try {
            while (true) {
                int ingredienteFora = new Random().nextInt(1, 4);
                switch (ingredienteFora) {
                    case 1 -> {
                        this.tabaco.release();
                        this.fosforo.release();
                    }
                    case 2 -> {
                        this.papel.release();
                        this.fosforo.release();
                    }
                    case 3 -> {
                        this.papel.release();
                        this.tabaco.release();
                    }
                }
                Thread.sleep(1000);
            }
        } catch (InterruptedException ignored) {
        }
    }
}

class Fumante extends Thread {
    private boolean hasPapel;
    private boolean hasTabaco;
    private boolean hasFosforo;
    private String nome;
    private Agente agente;

    public Fumante(String nome, Agente agente, boolean hasFosforo, boolean hasTabaco, boolean hasPapel) {
        this.nome = nome;
        this.agente = agente;
        this.hasFosforo = hasFosforo;
        this.hasPapel = hasPapel;
        this.hasTabaco = hasTabaco;
    }

    @Override
    public void run() {
        try {
            while (true) {
                if (hasFosforo) {
                    agente.tabaco.acquire();
                    agente.papel.acquire();
                    System.out.printf("%s: Tenho FÓSFORO. Preciso de TABACO e PAPEL.\n", this.nome);
                    Thread.sleep(3000);
                    System.out.printf("%s: Fumei!\n", this.nome);
                } else if (hasTabaco) {
                    agente.fosforo.acquire();
                    agente.papel.acquire();
                    System.out.printf("%s: Tenho TABACO. Preciso de FÓSFORO e PAPEL.\n", this.nome);
                    Thread.sleep(3000);
                    System.out.printf("%s: Fumei!\n", this.nome);
                } else if (hasPapel) {
                    agente.tabaco.acquire();
                    agente.fosforo.acquire();
                    System.out.printf("%s: Tenho PAPEL. Preciso de TABACO e FÓSFORO.\n", this.nome);
                    Thread.sleep(3000);
                    System.out.printf("%s: Fumei!\n", this.nome);
                }
            }
        } catch (InterruptedException ignored) {
        }
    }
}

public class App2 {
    public static void main(String[] args) {

        Agente agente = new Agente();

        ExecutorService executor = Executors.newFixedThreadPool(4);


        executor.submit(new Fumante("Fumante " + 1, agente, true, false, false));
        executor.submit(new Fumante("Fumante " + 2, agente, false, true, false));
        executor.submit(new Fumante("Fumante " + 3, agente, false, false, true));
        executor.submit(agente);
        executor.shutdown();
        try {
            executor.awaitTermination(10, TimeUnit.SECONDS);
        } catch (InterruptedException ignored) {
        }
    }
}
