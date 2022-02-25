package exercicios.matrizes;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Produto implements Runnable {
    private int n;
    private double a[][];
    private double b[][];
    private double c[][];
    private int i;
    private int j;

    public Produto(int n, double[][] a, double[][] b, int i, int j, double[][] c) {
        this.n = n;
        this.a = a;
        this.b = b;
        this.c = c;
        this.i = i;
        this.j = j;
    }

    @Override
    public void run() {
        for (int k = 0; k < n; k++)
            c[i][j] += a[i][k] * b[k][j];
    }

}

class Worker4 {

    private Random random = new Random();

    private final Object lock1 = new Object();
    private final Object lock2 = new Object();

    private List<Integer> list1 = new ArrayList<>();
    private List<Integer> list2 = new ArrayList<>();


    private int n = new Random().nextInt(10);
    // O Thread Pool recebe "+1" no tamanho pois n pode resultar em zero;
    ExecutorService executor = Executors.newFixedThreadPool(n * n + 1);
    long start = System.currentTimeMillis();

    private double[][] matrizA = new double[n][n];
    private double[][] matrizB = new double[n][n];
    private double[][] matrizC = new double[n][n];


    public void popularMatrizes(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrizA[i][j] = Math.random();
                matrizB[i][j] = Math.random();
            }
        }
    }

    public void stageOne() {
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        synchronized (lock1) {
            list1.add(random.nextInt(10000));
        }
    }

    public void stageTwo() {
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        synchronized (lock2) {
            list2.add(random.nextInt(10000));
        }
    }

    public void process() {
        for (int i = 0; i < 1000; i++) {
            stageOne();
            stageTwo();
        }
    }

    public void principal () {
        System.out.println("Starting ...");
        long start = System.currentTimeMillis();
        Thread t1 = new Thread(new Runnable() {
            public void run() {
                process();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                process();
            }
        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


        for (int i = 0; i < matrizA.length; i++) {
            for (int j = 0; j < matrizB[0].length; j++) {
                executor.submit(new Matrizes.Produto(n, matrizA, matrizB, i, j, matrizC));
            }
        }

        executor.shutdown();

        try {
            boolean pool_result = executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException ignored) {
        }

        long end = System.currentTimeMillis();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%2f ", matrizC[i][j]);
            }
            System.out.println();
        }
        System.out.println("++++++++++++++++++++++++++++++");

        System.out.println("Time taken: " + (end - start));
        System.out.println("List1: " + list1.size() + "; List2: " + list2.size());
    }
}


public class Bonus {
    public static void main (String[] args) {
        Worker4 w = new Worker4();
        w.popularMatrizes();
        w.principal();

        // Tempo sem inclusão da multiplicação de matrizes (3 leituras): 3853, 3908, 3928. Média = 3896.33
        // Tempo com a inclusão da multiplicação de matrizes (3 leituras): 3901, 3943, 3900. Média = 3914.66



    }

}