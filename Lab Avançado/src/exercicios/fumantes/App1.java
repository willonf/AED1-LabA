//package exercicios.fumantes;
//
//import java.util.Random;
//
//class Agente extends Thread {
//    private boolean tabaco;
//    private boolean papel;
//    private boolean fosforos;
//
//    private int sorteio;
//
//    public void Agente() {
//        // 0 -> Tabaco
//        // 1 -> Papel
//        // 2 -> Fósforos
//
//        this.tabaco = false;
//        this.papel = false;
//        this.fosforos = false;
//    }
//
//    public boolean temTabaco() {
//        return this.tabaco;
//    }
//
//    public boolean temPapel() {
//        return this.papel;
//    }
//
//    public boolean temFosforos() {
//        return this.fosforos;
//    }
//
//    public void consomeTabaco() {
//        this.tabaco = false;
//    }
//
//    public void consomePapel() {
//        this.papel = false;
//    }
//
//    public void consomeFosforos() {
//        this.fosforos = false;
//    }
//
//    public void sorteio() {
//        Random random = new Random();
//        this.sorteio = random.nextInt(3);
//
//        switch (this.sorteio) {
//            case 0 -> {
//                System.out.println("O agente colocou na mesa: PAPEL e FÓSFOROS");
//                this.tabaco = false;
//                this.papel = true;
//                this.fosforos = true;
//            }
//            case 1 -> {
//                System.out.println("O agente colocou na mesa: TABACO e FÓSFOROS");
//                this.tabaco = true;
//                this.papel = false;
//                this.fosforos = true;
//            }
//            case 2 -> {
//                System.out.println("O agente colocou na mesa: PAPEL e TABACO");
//                this.tabaco = true;
//                this.papel = true;
//                this.fosforos = false;
//            }
//        }
//    }
//
//    @Override
//    public void run() {
//        while (true) {
//            try {
//                // Sorteio
//                Thread.sleep(1000);
//            } catch (InterruptedException ignored) {
//            }
//        }
//    }
//}
//
//class Ingredientes {
//    // 0 -> Tabaco
//    // 1 -> Papel
//    // 2 -> Fósforos
//
//    int ingredientes;
//
//    public Ingredientes() {
//        int tabaco = 0;
//        int papel = 1;
//        int fosforos = 2;
//    }
//
//    public void tabaco() {
//        System.out.println("O fumante com: tabaco está fumando");
//    }
//
//    public void papel() {
//        System.out.println("O fumante com: papel está fumando");
//    }
//
//    public void fosforos() {
//        System.out.println("O fumante com: fosforos está fumando");
//    }
//}
//
//class Fumante extends Thread {
//
//    // 0 -> Tabaco
//    // 1 -> Papel
//    // 2 -> Fósforos
//
//    private int ingredientes;
//    private Ingredientes ingrediente = new Ingredientes();
//    private String nome;
//    private Agente ag;
//
//
//    public Fumante(String nome, int ingredientes, Agente ag) {
//        this.nome = nome;
//        this.ingredientes = ingredientes;
//        this.ag = ag;
//
//        switch (ingredientes) {
//            case 0 -> System.out.println("O fumante " + this.nome + " está com o ingrediente TABACO.");
//            case 1 -> System.out.println("O fumante " + this.nome + " está com o ingrediente PAPEL.");
//            case 2 -> System.out.println("O fumante " + this.nome + " está com o ingrediente FÓSFOROS.");
//        }
//    }
//
//    @Override
//    public void run() {
//        while(true) {
//            if(ag.temTabaco() && ag.temPapel() && ingredientes == 2) {
//                System.out.println("O fumante " + this.nome + " que tem FÓSFOROS fumou.");
//                ag.consomeTabaco();
//                ag.consomePapel();
//            } else if (ag.temPapel() && ag.temFosforos() && ingredientes == 0){
//                System.out.println("O fumante " + this.nome + " que tem TABACO fumou.");
//                ag.consomePapel();
//                ag.consomeFosforos();
//            } else if (ag.temTabaco() && ag.temFosforos() && ingredientes == 1){
//                System.out.println("O fumante " + this.nome + " que tem PAPEL fumou.");
//                ag.consomeTabaco();
//                ag.consomeFosforos();
//            }
//
//            try{
//                Thread.sleep(100);
//            }catch (InterruptedException ignored){}
//        }
//    }
//}
//
//public class App1 {
//    public static void main(String[] args) {
//        Agente agente = new Agente();
//        Fumante fumante0 = new Fumante("Fumante 0", 0, agente);
//        Fumante fumante1 = new Fumante("Fumante 1", 1, agente);
//        Fumante fumante2 = new Fumante("Fumante 2", 2, agente);
//
//        new Thread(agente).start();
//        new Thread(fumante0).start();
//        new Thread(fumante1).start();
//        new Thread(fumante2).start();
//
//
//
//    }
//}
