package hashtables;

public class CacheRotas {
    private CacheItem[] tabela;
    private int tamanho;

    public CacheRotas(int tamanhoMax) {
        tabela = new CacheItem[tamanhoMax];
    }

    public int tamanho() {
        return this.tamanho;
    }

    private void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public void imprime() {
        for (CacheItem item : tabela) {
            if (item != null && !item.isRemovido()) {
                System.out.println(item.getDestino() + " = " + item.getInterfaceSaida());
            }
        }
    }

    private int funcaoHash(String chave) {
        int soma = 0;
        for (int i = 0; i < chave.length(); i++) {
            soma += chave.charAt(i);
        }
        return soma % tabela.length;
    }

    public CacheItem busca(String chave) {
        if (chave == null) {
            return null;
        }
        int index = funcaoHash(chave);
        int i = 0;

        while (tabela[index] != null && !tabela[index].getDestino().equals(chave) && i < tabela.length) {
            i++;
            index = (index + 1) % tabela.length;
        }
        CacheItem result = tabela[index];
        if (result != null && !result.isRemovido() && result.getDestino().equals(chave)) {
            return result;
        }
        return null;
    }

    public boolean insere(String chave, int valor) {
        if (this.tamanho() == tabela.length || this.busca(chave) != null) {
            return false;
        }
        int index = funcaoHash(chave);
        int i = 0;

        while (tabela[index] != null && !tabela[index].isRemovido() && i < tabela.length) {
            i++;
            index = (index + 1) % tabela.length;
        }
        tabela[index] = new CacheItem(chave, valor);
        this.setTamanho(this.tamanho() + 1);
        return true;
    }

    public boolean remove(String chave) {
        CacheItem item = busca(chave);

        if(item == null){ return false; }
        item.setRemovido(true);
        item.setDestino(null);
        item.setInterfaceSaida(0);

        this.setTamanho(this.tamanho() - 1);
        return true;
    }


}
