package listas;

public class ListaDuplamenteEncadeada {
    private No2 topo;
    private No2 cauda;
    private No2 prox;
    private No2 ant;
    private int tamanho;

    public ListaDuplamenteEncadeada() {
        topo = null;
        cauda = null;
        tamanho = 0;
    }

    public No2 getTopo() {
        return this.topo;
    }

    public int getTamanho() {
        return this.tamanho;
    }

    public void imprime() {
        for (No2 no = this.getTopo(); no != null; no = no.getProx()) {
            System.out.println(no.getDado());
        }
    }

    public Object get(int indice) {
        if (indice < 0 || indice >= this.getTamanho()) {
            return null;
        }
        No2 noAtual = this.getTopo();
        while (indice-- > 0) {
            noAtual = noAtual.getProx();
        }
        return noAtual.getDado();
    }

    public void insereInicio(Object dado) {
        No2 noNovo = new No2(dado);
        noNovo.setProx(this.getTopo());

        if (this.getTopo() != null) {
            this.topo.setAnt(noNovo);
        } else {
            this.cauda = noNovo;
        }
        this.topo = noNovo;
        this.tamanho++;
    }

    public void imprimeInverso() {
        for (int i = this.getTamanho() - 1; i >= 0; i--) {
            System.out.println(this.get(i));
        }
    }

    public void limpa() {
        this.tamanho = 0;
        this.topo = null;
        this.cauda = null;
    }

    public boolean insereIndice(int indice, Object dado) {
        No2 noNovo = new No2(dado);
        No2 no = this.getTopo();
        No2 noAnterior = new No2(null);
        if (indice < 0 || indice >= this.getTamanho()) {
            return false;
        }
        for (int i = 0; i < indice; i++) {
            no = no.getProx();
        }
        noAnterior = no.getAnt();
        noAnterior.setProx(noNovo);
        noNovo.setProx(no);
        this.tamanho = this.getTamanho() + 1;
        return true;
    }

    public void concatena(ListaDuplamenteEncadeada lista) {
        this.cauda.setProx(lista.getTopo());
        this.cauda = lista.cauda;
        lista.topo.setAnt(this.cauda.getAnt());

        this.tamanho = this.tamanho + lista.tamanho;
    }

    public Object[] vetor() {
        int length = this.getTamanho();
        Object[] arrayDados = new Object[length];

        for (int i = 0; i < length; i++) {
            arrayDados[i] = this.get(i);
        }
        return arrayDados;
    }

}
