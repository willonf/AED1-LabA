package avltree;

class NoArvoreAVL {
    private int chave;
    private Object valor;
    private NoArvoreAVL esquerda;
    private NoArvoreAVL direita;
    private NoArvoreAVL pai;
    private int balanceamento;

    public NoArvoreAVL(int chave, Object valor, NoArvoreAVL pai) {
        this.chave = chave;
        this.valor = valor;
        this.pai = pai;
        this.balanceamento = 0;
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

    public NoArvoreAVL getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(NoArvoreAVL esquerda) {
        this.esquerda = esquerda;
    }

    public NoArvoreAVL getDireita() {
        return direita;
    }

    public void setDireita(NoArvoreAVL direita) {
        this.direita = direita;
    }

    public NoArvoreAVL getPai() {
        return pai;
    }

    public void setPai(NoArvoreAVL pai) {
        this.pai = pai;
    }

    public int getBalanceamento() {
        return balanceamento;
    }

    public void setBalanceamento(int balanceamento) {
        this.balanceamento = balanceamento;
    }
}

