import trabalhopratico1.StringEncadeada;

public class StringEncadeadaMain {

    public static void main(String[] args) {
        StringEncadeada word1 = new StringEncadeada(new StringEncadeada(new char[]{'T', 'e', 's', 't', 'e', '1'}));
        StringEncadeada word2 = new StringEncadeada(new StringEncadeada());

        word1.concat(word2);
        System.out.println(word1);
    }
}

