import avltree.ArvorePacotesForaDeOrdem;

public class TCPMain {

    public static void main(String[] args) {
        ArvorePacotesForaDeOrdem a = new ArvorePacotesForaDeOrdem();
        a.pacoteRecebido(6, 9192, 3000);
        a.pacoteRecebido(4, 9192, 3000);
        a.pacoteRecebido(3, 9192, 3000);
        a.pacoteRecebido(1, 9192, 3000);
    }
}

