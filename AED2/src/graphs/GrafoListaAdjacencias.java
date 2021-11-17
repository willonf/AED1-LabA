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

    public void removeArestaSimetrica(int v1, int v2) {
        removeAresta(v1, v2);
        removeAresta(v2, v1);
    }

    public int[] caminhoGuloso(int origem, int destino) {
        int tamCaminho = 0;
        int[] caminho = new int[this.getNumVertices()];
        boolean[] visitado = new boolean[this.getNumVertices()];

        Vertice vDestino = this.getVertice(destino);
        Vertice vizinho;
        VerticeAdjacente vizinhos;
        Vertice melhorVizinho = null;
        double dist;
        int menorDistancia = Integer.MAX_VALUE;

        double xDestino = this.getVertice(destino).getX();
        double yDestino = this.getVertice(destino).getY();

        for (int i = 0; i < this.getNumVertices(); i++) {
            caminho[i] = -1;
            visitado[i] = false;
        }

        caminho[tamCaminho++] = origem;
        Vertice noAtual = this.getVertice(origem);

        while (noAtual != vDestino) {
            vizinhos = noAtual.getVizinhos();
            do {
                if (!visitado[vizinhos.getVertice().getId()]) {
                    vizinho = vizinhos.getVertice();
                    double xAtual = vizinho.getX();
                    double yAtual = vizinho.getY();
                    dist = Math.sqrt(Math.pow(xAtual-xDestino, 2) + Math.pow(yAtual - yDestino, 2));
                    if(dist < menorDistancia){
                        melhorVizinho = vizinho;
                        menorDistancia = (int) dist;
                    }
                }
                vizinhos = vizinhos.getProx();
            } while (vizinhos != null);


            if (melhorVizinho == null) {
                return null;
            }
            caminho[tamCaminho++] = melhorVizinho.getId();
            visitado[melhorVizinho.getId()] = true;
            noAtual = melhorVizinho;
        }


        return caminho;
    }



    public int getNumVertices() {
        return numVertices;
    }

    public int getNumArestas() {
        return numArestas;
    }
}
