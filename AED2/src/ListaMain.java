import trabalhopratico1.StringEncadeada;

public class ListaMain {

    public static void main(String[] args) {
        StringEncadeada word1 = new StringEncadeada(new StringEncadeada(new char[]{'T', 'e', 's', 't', 'e', '3'}));
        StringEncadeada word2 = new StringEncadeada(new StringEncadeada("Teste2"));
        StringEncadeada word3 = new StringEncadeada(new StringEncadeada(new StringEncadeada("Teste3")));
//        StringEncadeada word4 = new StringEncadeada(new StringEncadeada(new StringEncadeada(new char[]{'T', 'e', 's', 't', 'e','4'})));
//        System.out.println(word2.getTopo());
//        System.out.println(word2.getCauda());
//        word2.insereInicio('W');
//        word2.insereFim('W');
//        System.out.println(word2.isEmpty());
//        System.out.println(word2.length());
//        System.out.println(word2.charAt(1));
//        System.out.println(word2.indexOf('t'));
//        System.out.println(word2.equals("Willon"));
//        word2.concat(word1);
//        System.out.println(word2.equals(word1));
//        word2.replace('T','W');
        System.out.println(word1.compareTo(word3));
//        System.out.println(word2.toString());

    }
}

