import trabalhopratico2.ListaInvertida;

public class GoogleMain {

    public static void main(String[] args) {
        ListaInvertida lista = new ListaInvertida(6);
        lista.insere("remember", "document1.txt");
        lista.insere("remember", "document2.txt");
        System.out.println(lista.tamanhoMedioListas());
        System.out.println(lista);
    }
}

