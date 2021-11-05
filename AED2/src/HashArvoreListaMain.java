import trabalhopratico3.TabelaHash;

import java.util.Arrays;


public class HashArvoreListaMain {

    public static void main(String[] args) {
        TabelaHash t = new TabelaHash(3);

        boolean a = t.insere(66, "Stass Allie");
        boolean b =t.insere(66, "Stass Allie");
        t.insere(66, "Cin Drallig");
        t.insere(1, "Obi-Wan Kenobi");
        t.insere(5, "Will");
        t.insere(5, "Ferreira");
        t.insere(8, "silva");
        System.out.println(a);
        System.out.println(b);
        System.out.println("+++++++++++++++++++++++++++++++");
        System.out.println(t);
        System.out.println("+++++++++++++++++++++++++++++++");
        System.out.println(t.busca(5));
        System.out.println(t.busca(8));
        System.out.println(Arrays.toString(t.getTabela()));
    }
}

