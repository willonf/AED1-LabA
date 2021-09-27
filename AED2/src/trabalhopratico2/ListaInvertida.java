package trabalhopratico2;

public class ListaInvertida {
    private PalavraNo[] tabela;
    private int tamanho;
    private int colisoes = 0;

    public ListaInvertida(int maxTam) {
        this.tabela = new PalavraNo[maxTam];
    }

    public int tamanho() {
        return this.tamanho;
    }

    public PalavraNo[] getTabela() {
        return tabela;
    }

    private int funcaoHash(String chave) {
        int soma = 0;
        for (int i = 0; i < chave.length(); i++) {
            soma += chave.charAt(i);
        }
        return soma % tabela.length;
    }

    public PalavraNo busca(String chave) {
        if (chave == null) {
            return null;
        }
        for (PalavraNo result = tabela[funcaoHash(chave)];
             result != null; result = result.getProx()) {
            if (result.getPalavra().equals(chave)) {
                return result;
            }
        }
        return null;
    }

    public boolean insere(String palavra, String documento) {

        PalavraNo result = this.busca(palavra);
        if (result != null) {
            this.setNumColisoes(this.getNumColisoes() + 1);
            if (result.buscaDocumento(documento) != null) {
                result.insereDocumento(documento);
                return true;
            }
            return false;
        } else {
            int indice = this.funcaoHash(palavra);
            PalavraNo topo = this.tabela[indice];
            this.tabela[indice] = new PalavraNo(palavra, documento);
            this.tabela[indice].setProx(topo);
            this.tamanho++;
            return true;
        }
    }

    public double cargaUtilizacao() {
//        int count = 0;
//        for (int i = 0; i < this.getTabela().length; i++) {
//            if(tabela[i] != null){
//                count++;
//            }
//        }
        return ((double) this.tamanho() / this.getTabela().length) * 100;
    }

    public int getNumColisoes() {
        return this.colisoes;
    }

    public void setNumColisoes(int qtdeColisoes) {
        this.colisoes = qtdeColisoes;
    }

    public double tamanhoMedioListas() {
        int sum = 0;
        double result;
        for (int i = 0; i < this.getTabela().length; i++) {
            if (this.getTabela()[i].getDocumentosTopo() != null) {
                sum += this.getTabela()[i].getDocumentosTamanho();
            }
        }
        result = ((double) sum) / this.tamanho();
        return result;
    }

    public void rehash(int novoTamanho) {
        PalavraNo[] tabelaNova = new PalavraNo[novoTamanho];
        for (PalavraNo palavra : this.getTabela()) {
            int soma = 0;
            for (int i = 0; i < palavra.getPalavra().length(); i++) {
                soma += palavra.getPalavra().charAt(i);
            }
            tabelaNova[soma % tabelaNova.length] = palavra;
        }
        this.tabela = tabelaNova;
    }

    @Override
    public String toString(){
        String result = "";
        for (int i = 0; i < this.getTabela().length; i++) {
            String prefix = "[Indice".concat(String.valueOf(i)).concat("] ");
            if (this.getTabela()[i].getDocumentosTopo() != null) {
                for (PalavraNo word = this.getTabela()[i]; word != null; word = word.getProx()) {
                    result = result.concat(prefix).concat(word.toString());
                }
                result = result.concat("\n");
            }
        }
        return result;
    }


}
