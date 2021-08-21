package listas;

public class ListaVetor {
    private Object[] dados;
    private int tamanho;

    public ListaVetor(int maxTam) {
        dados = new Object[maxTam];
        tamanho = 0;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void imprime() {
        for (int i = 0; i < getTamanho(); i++) {
            System.out.println(dados[i]);
        }
    }

    // Método get: O(1)
    public Object get(int indice) {
        if (indice < 0 || indice >= tamanho) {
            return null;
        }
        return dados[indice];
    }

    // Método busca: O(n)
    public int busca(Object dado) {
        for (int i = 0; i < getTamanho(); i++) {
            if (dados[i].equals(dado)) {
                return i;
            }
        }
        return -1;
    }
}
