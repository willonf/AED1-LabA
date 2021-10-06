package binarysearchtree;

public class NoArvore {
    private int chave;
    private Object valor;
    private NoArvore esquerda;
    private NoArvore direita;
    private NoArvore pai;

    public NoArvore(int chave, Object valor, NoArvore pai) {
        this.chave = chave;
        this.valor = valor;
        this.pai = pai;
    }

    public int getChave() {
        return chave;
    }

    public void setChave(int chave) {
        this.chave = chave;
    }

    public Object getValor() {
        return valor;
    }

    public void setValor(Object valor) {
        this.valor = valor;
    }

    public NoArvore getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(NoArvore esquerda) {
        this.esquerda = esquerda;
    }

    public NoArvore getDireita() {
        return direita;
    }

    public void setDireita(NoArvore direita) {
        this.direita = direita;
    }

    public NoArvore getPai() {
        return pai;
    }

    public void setPai(NoArvore pai) {
        this.pai = pai;
    }
}
