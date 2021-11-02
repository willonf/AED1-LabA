package trabalhopratico3;

public class TabelaHash {
    private NoArvore[] tabela;
    private int tamanho;

    public TabelaHash(int maxTam) {
        this.tamanho = maxTam;
    }

    public NoArvore[] getTabela() {
        return tabela;
    }

    public int tamanho() {
        return tamanho;
    }

    private int funcaoHash(int chave) {
        return (int) (Math.floor(this.tamanho() * (chave * 0.567 % 1)));
    }

    public NoArvore busca(int chave) {
        int index = funcaoHash(chave);
        int i = 0;

        while (this.getTabela()[i] != null
                && !this.getTabela()[index].getValor().equals(chave)
                && i < this.getTabela().length) {
            i++;

            //VERIFICAR ESSA ATRIBUIÇÃO
            index = (index + 1) % this.getTabela().length;
        }
        NoArvore result = this.getTabela()[index];
        if (result != null && result.getValor().equals(chave)) {
            return result;
        }
        return result;
    }

    public boolean insere(int chave, Object valor) {

    }

    @Override
    public String toString() {
        return "TabelaHash{}";
    }

    public String caminhaIdentado(NoArvore subArvore, int identacao) {

    }
}
