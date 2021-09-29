package trabalhopratico2;

public class ListaInvertida {
    private PalavraNo[] tabela;
    private int tamanho = 0;
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
            if (result.buscaDocumento(documento) == null) {
                boolean inserido = result.insereDocumento(documento);
                if (!inserido) {
                    this.setNumColisoes(this.getNumColisoes() + 1);
                }
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
        int count = 0;
        if (this.tamanho() == 0) {
            return 0.0;
        }
        for (int i = 0; i < this.getTabela().length; i++) {
            if (this.getTabela()[i] == null) {
                continue;
            }
            if (this.getTabela()[i].getDocumentosTopo() != null) {
                count++;
            }
        }
        return ((double) count / this.getTabela().length) * 100;
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
        int count = 0;
        if (this.tamanho() == 0) {
            return 0.0;
        }
        for (int i = 0; i < this.getTabela().length; i++) {

            if (this.getTabela()[i] == null) {
                continue;
            }
            count++;
            if (this.getTabela()[i].getDocumentosTopo() != null) {
                sum += this.getTabela()[i].getDocumentosTamanho();
            }
        }
        result = ((double) sum) / this.tamanho();
        return result;
    }

    public void rehash(int novoTamanho) {
        PalavraNo[] tabelaNova = new PalavraNo[novoTamanho];
        for (int i = 0; i < this.getTabela().length; i++) {
            PalavraNo palavra = this.getTabela()[i];
            int soma = 0;
            if (palavra == null || palavra.getDocumentosTamanho() == 0) {
                continue;
            }
            for (int j = 0; j < palavra.getPalavra().length(); j++) {
                soma += palavra.getPalavra().charAt(j);
            }
            tabelaNova[soma % tabelaNova.length] = palavra;
        }
        this.setNumColisoes(0);
        this.tabela = tabelaNova;
    }

    @Override
    public String toString() {
        String result = "";

        if (this.getTabela() != null) {
            return "";
        }

        for (int i = 0; i < this.getTabela().length; i++) {
            String prefix = "[Indice ".concat(String.valueOf(i)).concat("] ");

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
