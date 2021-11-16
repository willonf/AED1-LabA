import graphs.GrafoListaAdjacencias;

public class GrafoMain {

    public static void main(String[] args) {
        GrafoListaAdjacencias grafo = new GrafoListaAdjacencias(6);

        grafo.getVertice(0).setX(0);
        grafo.getVertice(0).setY(1);
        grafo.getVertice(1).setX(1);
        grafo.getVertice(1).setY(0);
        grafo.getVertice(2).setX(1);
        grafo.getVertice(2).setY(2);
        grafo.getVertice(3).setX(2);
        grafo.getVertice(3).setY(0);
        grafo.getVertice(4).setX(2);
        grafo.getVertice(4).setY(2);
        grafo.getVertice(5).setX(3);
        grafo.getVertice(5).setY(0);

        grafo.insereArestaSimetrica(0, 1, 2);
        grafo.insereArestaSimetrica(0, 2, 8);
        grafo.insereArestaSimetrica(1, 2, 15);
        grafo.insereArestaSimetrica(1, 3, 3);
        grafo.insereArestaSimetrica(2, 4, 2);
        grafo.insereArestaSimetrica(3, 4, 4);
        grafo.insereArestaSimetrica(3, 5, 45);

        System.out.println(grafo);

        int[] caminho = grafo.caminhoGuloso(0, 4);

        System.out.print("Caminho guloso entre 0 e 4: ");
        if (caminho != null)
            for (int i=0; i<caminho.length; i++)
                System.out.print(caminho[i] + " ");
    }
}

