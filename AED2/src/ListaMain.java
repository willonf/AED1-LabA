import listas.ListaDuplamenteEncadeada;
import listas.No2;

public class ListaMain {

    public static void main(String[] args) {
        ListaDuplamenteEncadeada lista = new ListaDuplamenteEncadeada();
        lista.insereInicio("Doctor Who");
        lista.insereInicio("Daleks");
        lista.insereInicio("Cybermen");
        lista.insereInicio("Weeping Angels");
        No2 noTopo = lista.getTopo();
        No2 noTopoProx = noTopo.getProx();
        Object[] listaVetor = lista.vetor();
        ListaDuplamenteEncadeada lista2 = new ListaDuplamenteEncadeada();
        lista2.insereInicio("River Song");
        lista2.insereInicio("Melody Pond");
        lista.concatena(lista2);
        lista.insereIndice(1, "The power of the Daleks");
        lista.imprime();
        System.out.println("+====+++=====+++=====++");
        System.out.println(lista.get(1));
        System.out.println("+====+++=====INVERSO+++=====++");
        lista.imprimeInverso();
        lista.limpa();
        lista2.limpa();
    }
}

