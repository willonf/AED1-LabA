import graphs.GrafoListaAdjacencias;

public class GrafoMain {

    public static void main(String[] args) {
        GrafoListaAdjacencias grafo = new GrafoListaAdjacencias(4);
        grafo.getVertice(0).setX(0);
        grafo.getVertice(0).setY(0);
        grafo.getVertice(1).setX(1);
        grafo.getVertice(1).setY(0);
        grafo.getVertice(2).setX(2);
        grafo.getVertice(2).setY(0);
        grafo.getVertice(3).setX(3);
        grafo.getVertice(3).setY(0);
        grafo.insereArestaSimetrica(0, 1, 1);
        grafo.insereArestaSimetrica(1, 2, 1);
        grafo.insereArestaSimetrica(2, 3, 1);
        int[] prev = grafo.caminhoMinimoDijkstra(0);
//
//        GrafoListaAdjacencias grafo = new GrafoListaAdjacencias(4);
//        grafo.getVertice(0).setX(0);
//        grafo.getVertice(0).setY(0);
//        grafo.getVertice(1).setX(1);
//        grafo.getVertice(1).setY(0);
//        grafo.getVertice(2).setX(2);
//        grafo.getVertice(2).setY(0);
//        grafo.getVertice(3).setX(3);
//        grafo.getVertice(3).setY(0);
//        grafo.insereArestaSimetrica(0, 1, 1);
//        grafo.insereArestaSimetrica(1, 2, 1);
//        grafo.insereArestaSimetrica(2, 3, 1);
//        int[] prev = grafo.caminhoMinimoDijkstra(0);
//// Exemplo dos slides (Dijkstra)
//        grafo = new GrafoListaAdjacencias(8);
//        grafo.getVertice(0).setX(0);
//        grafo.getVertice(0).setY(1);
//        grafo.getVertice(1).setX(1);
//        grafo.getVertice(1).setY(0);
//        grafo.getVertice(2).setX(1);
//        grafo.getVertice(2).setY(2);
//        grafo.getVertice(3).setX(2);
//        grafo.getVertice(3).setY(1);
//        grafo.getVertice(4).setX(4);
//        grafo.getVertice(4).setY(1);
//        grafo.getVertice(5).setX(5);
//        grafo.getVertice(5).setY(0);
//        grafo.getVertice(6).setX(5);
//        grafo.getVertice(6).setY(2);
//        grafo.getVertice(7).setX(6);
//        grafo.getVertice(7).setY(1);
//        grafo.insereArestaSimetrica(0, 1, 2);
//        grafo.insereArestaSimetrica(0, 2, 6);
//        grafo.insereArestaSimetrica(1, 3, 2);
//        grafo.insereArestaSimetrica(1, 5, 7);
//        grafo.insereArestaSimetrica(2, 3, 1);
//        grafo.insereArestaSimetrica(2, 6, 4);
//        grafo.insereArestaSimetrica(3, 4, 2);
//        grafo.insereArestaSimetrica(4, 5, 3);
//        grafo.insereArestaSimetrica(4, 6, 2);
//        grafo.insereArestaSimetrica(5, 7, 3);
//        grafo.insereArestaSimetrica(6, 7, 20);
//        prev = grafo.caminhoMinimoDijkstra(0);
//        prev = grafo.caminhoMinimoDijkstra(5);
        for (int j : prev) {
            System.out.println(j);
        }
    }
}

