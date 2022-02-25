package exercicios.matrizes;

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Matrizes {

    static class Produto implements Runnable {
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

    public static void main(String[] args) {
        int n = new Random().nextInt(10);
        // O Thread Pool recebe "+1" no tamanho pois n pode resultar em zero;
        ExecutorService executor = Executors.newFixedThreadPool(n * n + 1);
        long start = System.currentTimeMillis();

        double[][] matrizA;
        double[][] matrizB;
        double[][] matrizC = new double[n][n];

        matrizA = new double[n][n];
        matrizB = new double[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrizA[i][j] = Math.random();
                matrizB[i][j] = Math.random();
            }
        }

        for (int i = 0; i < matrizA.length; i++) {
            for (int j = 0; j < matrizB[0].length; j++) {
                executor.submit(new Produto(n, matrizA, matrizB, i, j, matrizC));
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
        System.out.println("Time taken: " + (end - start));

    }

}
