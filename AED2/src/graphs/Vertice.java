package graphs;

public class Vertice {
    private int id;
    private int x, y; // Informações armazenados no vértice
    private VerticeAdjacente topoVizinhos;

    public Vertice(int id) {
        this.id = id;
        this.x = -1; // Não inicializado
        this.y = -1; // Não inicializado
    }

    public VerticeAdjacente buscaVizinho(Vertice vertice) {
        VerticeAdjacente vAtual = this.topoVizinhos;

        while (vAtual != null && vAtual.getVertice() != vertice) {
            vAtual = vAtual.getProx();
        }
        return vAtual;
    }

    public void insereVizinho(Vertice vertice, int peso) {
        insereVizinho(new VerticeAdjacente(vertice, peso));
    }

    public void insereVizinho(VerticeAdjacente novoVertice) {
        if (this.buscaVizinho(novoVertice.getVertice()) != null) {
            return;
        }
        novoVertice.setProx(this.topoVizinhos);
        this.topoVizinhos = novoVertice;
    }

    public VerticeAdjacente getVizinhos() {
        return this.topoVizinhos;
    }

    public String toString() {
        String result = "Vertice " + id + " (" + x + "," + y + "):";
        for (VerticeAdjacente vAtual = this.topoVizinhos; vAtual != null; vAtual = vAtual.getProx()) {
            result = result.concat(vAtual + " ");
        }
        return result;
    }

    public VerticeAdjacente removeVizinho(Vertice vertice) {
        VerticeAdjacente vAtual = this.topoVizinhos;
        VerticeAdjacente vAnterior = null;

        while (vAtual != null && vAtual.getVertice() != vertice) {
            vAnterior = vAtual;
            vAtual = vAtual.getProx();
        }

        if (vAtual == null) {
            return null;
        }

        if(vAtual == this.topoVizinhos) {
            this.topoVizinhos = this.topoVizinhos.getProx();
        } else {
            vAnterior.setProx(vAtual.getProx());
        }
        return vAtual;

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getX() {
        return x;
    }

    public void setValores(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public VerticeAdjacente getTopoVizinhos() {
        return topoVizinhos;
    }

    public void setTopoVizinhos(VerticeAdjacente topoVizinhos) {
        this.topoVizinhos = topoVizinhos;
    }
}
