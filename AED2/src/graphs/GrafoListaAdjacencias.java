package graphs;

public class GrafoListaAdjacencias {
    private Vertice[] vertices;
    private int numVertices;
    private int numArestas;


    public GrafoListaAdjacencias(int numVertices) {
        this.numVertices = numVertices;
        this.numArestas = 0;
        this.vertices = new Vertice[numVertices];

        for (int i = 0; i < numVertices; i++) {
            vertices[i] = new Vertice(i);
        }
    }

    public Vertice getVertice(int v) {
        if (v < 0 || v >= numVertices) {
            throw new IndexOutOfBoundsException();
        }
        return vertices[v];
    }

    public void insereAresta(int v1, int v2, int peso) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }

        vertices[v1].insereVizinho(vertices[v2], peso);
        numArestas++;
    }

    public void insereArestaSimetrica(int v1, int v2, int peso) {
        this.insereAresta(v1, v2, peso);
        this.insereAresta(v2, v1, peso);
    }

    public String toString() {
        String result = "";
        for (int i = 0; i < numVertices; i++) {
            result = result.concat(vertices[i] + "\n");
        }
        return result;
    }

    public int existeAresta(int v1, int v2) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }

        VerticeAdjacente v = vertices[v1].buscaVizinho(vertices[v2]);

        return v != null ? v.getPeso() : -1;
    }

    public void removeAresta(int v1, int v2) {
        if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices) {
            throw new IndexOutOfBoundsException();
        }

        vertices[v1].removeVizinho(vertices[v2]);
        numVertices--;
    }

    public int getNumVertices() {
        return numVertices;
    }

    public int getNumArestas() {
        return numArestas;
    }
}
