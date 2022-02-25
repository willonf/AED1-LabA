import exercicios.relogio.Relogio;

public class Main {
    public static void main(String[] args) {
        Thread relogio1 = new Thread(new Relogio());
        Thread relogio2 = new Thread(new Relogio(10));
        Thread relogio3 = new Thread(new Relogio(5, 10));

        relogio1.start();
        relogio2.start();
        relogio3.start();

    }
}
