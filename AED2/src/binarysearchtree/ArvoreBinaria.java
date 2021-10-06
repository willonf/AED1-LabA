package binarysearchtree;

public class ArvoreBinaria {

    private NoArvore raiz;
    private int tamanho;

    public ArvoreBinaria() {
//        Opcionais:
//        raiz = null;
//        this.tamanho = 0;
    }

    public int tamanho() {
        return this.tamanho;
    }

    public void insere(int chave, Object valor) {
        if (raiz == null) {
            raiz = new NoArvore(chave, valor, null);
            tamanho = 1;
            return;
        }

        NoArvore noAtual = this.raiz;
        NoArvore noPai;

        do {
            noPai = noAtual;
            if (chave < noAtual.getChave()) {
                noAtual = noAtual.getEsquerda();
            } else if (chave > noAtual.getChave()) {
                noAtual = noAtual.getDireita();
            } else {
                noAtual.setValor(valor);
                return;
            }
        } while (noAtual != null);

        NoArvore noNovo = new NoArvore(chave, valor, noPai);
        if (chave < noPai.getChave()) {
            noPai.setEsquerda(noNovo);
        } else {
            noPai.setDireita(noNovo);
        }
        this.tamanho++;
    }

    public NoArvore busca(int chave) {
        NoArvore noAtual = this.raiz;

        while (noAtual != null || noAtual.getChave() != chave) {
            if (chave < noAtual.getChave()) {
                noAtual = noAtual.getEsquerda();
            } else {
                noAtual = noAtual.getDireita();
            }
        }

        return noAtual;
    }

    public NoArvore buscaRecursiva(NoArvore subArvore, int chave) {
        if (subArvore == null || subArvore.getChave() == chave) {
            return subArvore;
        }

        if (chave < subArvore.getChave()) {
            return buscaRecursiva(subArvore.getEsquerda(), chave);
        } else {
            return buscaRecursiva(subArvore.getDireita(), chave);
        }
    }

}
