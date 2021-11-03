import trabalhopratico3.TabelaHash;

public class HashArvoreListaMain {

    public static void main(String[] args) {
        TabelaHash t = new TabelaHash(3);
        t.insere(66, "Stass Allie");
        boolean b = t.insere(66, "Cin Drallig");
        System.out.println(t);
    }
}

