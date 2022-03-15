package exercicios.semaforo;


import java.util.Random;
import java.util.concurrent.*;

public class App {
    static int saldo = 0;

    static class Banco extends Thread {
        String threadName;
        Semaphore sem;
        char op;


        public Banco(Semaphore sem, String threadName, char op) {
            this.sem = sem;
            this.threadName = threadName;
            this.op = op;
        }

        void deposito(int quantia) {
            saldo += quantia;
        }

        void retirada(int quantia) {
            saldo -= quantia;
        }

        public void run() {
            int quantia;
            System.out.println("Starting Thread: " + threadName);
            Random random = new Random();
            try {
                System.out.println(threadName + " está esperando...");
                sem.acquire();
                System.out.println(threadName + " vai realizar a transação bancária.");
                if (op == '-') {
                    for (int i = 0; i < 4; i++) {
                        quantia = random.nextInt(0, 1000);
                        this.retirada(quantia);
                        System.out.println(threadName + ": Retirou a quantia r$ " + quantia);
                    }
                } else {
                    quantia = random.nextInt(0, 1000);
                    this.deposito(quantia);
                    System.out.println(threadName + ": Depositou a quantia r$ " + quantia);
                }

                Thread.sleep(10);
            } catch (
                    InterruptedException exc) {
            }
            System.out.println(threadName + " encerrou a transação bancária");
            sem.release();
        }

    }

    public static void main(String args[]) throws InterruptedException {
        Semaphore sem = new Semaphore(1);
        Banco t2 = new Banco(sem, "Marido", '-');
        Banco t1 = new Banco(sem, "Mulher", '+');

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Saldo final após as transações: R$" + saldo);
    }
}
