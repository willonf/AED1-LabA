package listas;

public class No2 {
    private Object dado;
    private No2 ant;
    private No2 prox;

    public No2(Object dado) {
        this.dado = dado;
    }

    public Object getDado() {
        return dado;
    }

    public No2 getAnt() {
        return ant;
    }

    public void setAnt(No2 ant) {
        this.ant = ant;
    }

    public No2 getProx() {
        return prox;
    }

    public void setProx(No2 prox) {
        this.prox = prox;
    }
}
