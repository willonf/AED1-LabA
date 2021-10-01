import trabalhopratico2.ListaInvertida;

public class GoogleMain {

    public static void main(String[] args) {
        ListaInvertida l = new ListaInvertida(10);
        l.rehash(20);
        l = new ListaInvertida(10);
        l.insere("force", "TheJediPath.pdf");
        l.rehash(20);
        l.insere("force", "TheJediPath.pdf");
        l.insere("jed", "TheReturnOfJedi.pdf");
        System.out.println(l.getNumColisoes());
    }
}

