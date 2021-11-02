package trabalhopratico3;

public class NoArvore {
    private int chave;
    private Object valor;
    private NoLista listaTopo;
    private int listaTamanho;
    private NoArvore esquerda;
    private NoArvore direita;
    private NoArvore pai;
    private NoLista itemLista;

    public NoArvore(int chave, Object valor) {
        this.chave = chave;
        this.valor = valor;
        this.insereLista(valor);
    }

    public int getChave() {
        return chave;
    }

    public Object getValor() {
        return valor;
    }

    public NoLista getListaTopo() {
        return listaTopo;
    }

    public int getListaTamanho() {
        return listaTamanho;
    }

    public NoArvore getEsquerda() {
        return esquerda;
    }

    public NoArvore getDireita() {
        return direita;
    }

    public NoArvore getPai() {
        return pai;
    }

    public void setEsquerda(NoArvore esquerda) {
        this.esquerda = esquerda;
    }

    public void setDireita(NoArvore direita) {
        this.direita = direita;
    }

    public void setPai(NoArvore pai) {
        this.pai = pai;
    }

    public void setListaTamanho(int listaTamanho) {
        this.listaTamanho = listaTamanho;
    }

    public void setListaTopo(NoLista listaTopo) {
        this.listaTopo = listaTopo;
    }

    public NoLista buscaLista(Object valor) {
        if (valor == null) {
            return null;
        }
        for (NoLista no = this.getListaTopo(); no != null; no = no.getProx()) {
            if (no.toString().equals(valor.toString())) {
                return no;
            }
        }
        return null;
    }

    public boolean insereLista(Object valor) {
        if (valor == null) {
            return false;
        }
        if (this.buscaLista(valor) == null) {
            NoLista novoNo = new NoLista(valor);
            NoLista topo = this.getListaTopo();
            this.setListaTopo(novoNo);
            novoNo.setProx(topo);
            this.setListaTamanho(this.getListaTamanho() + 1);
            return true;
        }
        return false;
    }


    @Override
    public String toString() {
        String result = String.valueOf(this.getChave()).concat(" - ");
        String valores;
        String[] valoresVetor = new String[this.getListaTamanho()];
        int pos = 0;
        for (NoLista no = this.getListaTopo(); no != null; no = no.getProx()) {
            valoresVetor[pos] = no.getValor().toString();
            pos++;
        }
        valores = String.join(", ", valoresVetor);
        return result.concat(valores);
    }
}
