import trabalhopratico2.ListaInvertida;

public class GoogleMain {

    public static void main(String[] args) {
        ListaInvertida lista = new ListaInvertida(6);
        lista.insere("remember", "document1.txt");
        lista.insere("the", "document1.txt");
        lista.insere("the", "document2.txt");
        lista.insere("the", "document3.txt");
        lista.insere("force", "document1.txt");
        lista.insere("force", "document2.txt");
        lista.insere("force", "document3.txt");
        lista.insere("will", "document1.txt");
        lista.insere("be", "document1.txt");
        lista.insere("with", "document1.txt");
        lista.insere("jed", "document1.txt");
        lista.insere("masteryoda", "document1.txt");
        System.out.println(lista.tamanhoMedioListas());
        System.out.println(lista);
    }
}

