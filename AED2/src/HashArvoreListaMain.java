import trabalhopratico3.TabelaHash;

import java.util.Arrays;

public class HashArvoreListaMain {

    public static void main(String[] args) {
        TabelaHash t = new TabelaHash(3);

        t.insere(66, "Stass Allie");
        t.insere(66, "Stass Allie");
        t.insere(66, "Cin Drallig");
        t.insere(1, "Obi-Wan Kenobi"); // index == 0
        System.out.println(Arrays.toString(t.getTabela())); //index == 1
    }
}

