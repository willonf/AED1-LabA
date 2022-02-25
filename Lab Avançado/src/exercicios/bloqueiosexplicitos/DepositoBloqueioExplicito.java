package exercicios.bloqueiosexplicitos;

// Sem condição de corrida
public class DepositoBloqueioExplicito {
    private int qtdeItems = 0;
    private int capacidade;
    private final Object lock1 = new Object();
    private final Object lock2 = new Object();

    public DepositoBloqueioExplicito(int capacidade) {
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

    public void process(){
        this.armazenar();
        this.retirar();
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

class DepCaixasComBloqExplicito {
    static class Produtor implements Runnable {

        private DepositoBloqueioExplicito deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Produtor(DepositoBloqueioExplicito deposito, int tempo) {
            this.deposito = deposito;
            this.tempo = tempo;
        }

        @Override
        public void run() {
            while (count < MAX) {
                this.deposito.armazenar();
                count++;
                try {
                    Thread.sleep(this.tempo);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumidor extends Thread {
        private DepositoBloqueioExplicito deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Consumidor(DepositoBloqueioExplicito deposito, int tempo) {
            this.deposito = deposito;
            this.tempo = tempo;
        }

        public void run() {
            while (count < MAX) {
                this.deposito.retirar();
                count++;
                try {
                    Thread.sleep(this.tempo);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

    }

    public static void main(String[] args) {
        DepositoBloqueioExplicito dep = new DepositoBloqueioExplicito(2);

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                dep.process();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                dep.process();
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
    }

}


