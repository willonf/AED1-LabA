import trabalhopratico2.ListaInvertida;
import trabalhopratico2.PalavraNo;

public class GoogleMain {

    public static void main(String[] args) {
        ListaInvertida l = new ListaInvertida(10);
        l.rehash(20);
        l = new ListaInvertida(10);
        l.insere("force", "TheJediPath.pdf");
        System.out.println(l.cargaUtilizacao());
    }
}

