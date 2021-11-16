package graphs;

public class VerticeAdjacente {

    private Vertice vertice;
    private int peso;
    private VerticeAdjacente prox;

    public VerticeAdjacente(Vertice vertice, int peso) {
        this.vertice = vertice;
        this.peso = peso;
    }

    @Override
    public String toString() {
        return this.vertice.getId() + "(" + peso + ")";
    }

    public Vertice getVertice() {
        return vertice;
    }

    public void setVertice(Vertice vertice) {
        this.vertice = vertice;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    public VerticeAdjacente getProx() {
        return prox;
    }

    public void setProx(VerticeAdjacente prox) {
        this.prox = prox;
    }
}
