package exercicios;
// Sem condição de corrida
public class Deposito {
    private int qtdeItems = 0;
    private int capacidade;

    public Deposito(int capacidade) {
        this.capacidade = capacidade;
    }

    synchronized void armazenar() {
        System.out.println("Tentando armazenar uma caixa no depósito...");
        if (this.getQtdeItems() <= this.getCapacidade()) {
            this.setQtdeItems(this.getQtdeItems() + 1);
            System.out.println("Armazenada - Caixas no Deposito: " + this.getQtdeItems());
            System.out.println("Caixa armazenada\n");
        } else {
            System.out.println("Não foi possível armazenar...\n");
        }
    }

    synchronized void retirar() {
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

class DepCaixasSem {
    static class Produtor implements Runnable {

        private Deposito deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Produtor(Deposito deposito, int tempo) {
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
        private Deposito deposito;
        private int tempo;
        int MAX = 5;
        int count = 0;

        public Consumidor(Deposito deposito, int tempo) {
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
        Deposito dep = new Deposito(2);
        Thread prod = new Thread(new Produtor(dep, 100));
        Consumidor cons = new Consumidor(dep, 200);

        prod.start();
        cons.start();

        try {
            prod.join();
            cons.join();
        } catch (InterruptedException ignored) {
        }
    }

}


