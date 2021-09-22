package hashtables;

public class TabelaHashEndAberto {
    private int tamanho;
    private Item[] tabela;

    public TabelaHashEndAberto(int maxTam) {
        tabela = new Item[maxTam];
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTabela(Item[] tabela) {
        this.tabela = tabela;
    }

    public void imprime() {

    }

//    public Item busca(String chave) {
//        if (chave == null) {
//            return null;
//        }
//
//        int indice = funcaoHash(chave);
//        int i = 0;
//        while(tabela[indice])
//    }

    private int funcaoHash(String chave) {
        int soma = 0;
        for (int i = 0; i < chave.length(); i++) {
            soma += chave.charAt(i);
        }
        return soma % tabela.length;
    }

    public boolean insere(String chave, Object valor) {
        return true;
    }

    public boolean remove(String chave) {
        return true;
    }
}
