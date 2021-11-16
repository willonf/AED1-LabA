package graphs;

public class GrafoMatrizAdj {
    private int numVertices;
    private int numArestas;
    private int[][] matrizAdj;

    public GrafoMatrizAdj(int numVertices) {
        this.numVertices = numVertices;
        this.numArestas = 0;
        this.matrizAdj = new int[numVertices][numVertices];
    }

    public int getNumVertices() {
        return numVertices;
    }

    public int getNumArestas() {
        return numArestas;
    }

    public void insereAresta(int v1, int v2, int peso) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }
        matrizAdj[v1][v2] = peso;
        numArestas++;
    }

    public void insereArestaAssimetrica(int v1, int v2, int peso) {
        this.insereAresta(v1, v2, peso);
        this.insereAresta(v2, v1, peso);
    }

    public int existeAresta(int v1, int v2) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }
        return this.matrizAdj[v1][v2];
    }

    public void removeAresta(int v1, int v2) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }

        matrizAdj[v1][v2] = 0;
        numArestas--;
    }

    public void imprime() {
        for (int i = 0; i < numArestas; i++) {
            for (int j = 0; j < numVertices; j++) {
                System.out.println(this.matrizAdj[i][j] + "\t");
            }
            System.out.println();
        }
    }
}
