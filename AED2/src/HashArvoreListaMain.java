import trabalhopratico3.TabelaHash;

public class HashArvoreListaMain {

    public static void main(String[] args) {
        TabelaHash t = new TabelaHash(3);
       boolean a = t.insere(66, "Stass Allie");
        boolean b = t.insere(66, "Will");
        boolean c = t.insere(66, "Will");
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}

