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

    public void caminhaPreOrdem() {
        caminhaPreOrdem(raiz);
    }

    public void caminhaPreOrdem(NoArvore subArvore) {
        if (subArvore != null) {
            System.out.println(subArvore.getChave() + " ");
            caminhaPreOrdem(subArvore.getEsquerda());
            caminhaPreOrdem(subArvore.getDireita());
        }
    }

    public void caminhaPosOrdem() {
        caminhaPosOrdem(raiz);
    }

    public void caminhaPosOrdem(NoArvore subArvore) {
        if (subArvore != null) {
            caminhaPosOrdem(subArvore.getEsquerda());
            caminhaPosOrdem(subArvore.getDireita());
            System.out.println(subArvore.getChave() + " ");
        }
    }

    public void caminhaCentral() {
        caminhaCentral(raiz);
    }

    public void caminhaCentral(NoArvore subArvore) {
        if (subArvore != null) {
            caminhaCentral(subArvore.getEsquerda());
            System.out.println(subArvore.getChave() + " ");
            caminhaCentral(subArvore.getDireita());
        }
    }

    public void caminhaIndetado() {
        caminhaIndetado(raiz, 0);
    }

    public void caminhaIndetado(NoArvore subArvore, int indetacao) {
        if (subArvore == null) {
            return;
        }
        for (int i = 0; i < indetacao; i++) {
            System.out.println(" ");
        }
        System.out.println(subArvore.getChave());
        caminhaIndetado(subArvore.getEsquerda(), indetacao + 1);
        caminhaIndetado(subArvore.getDireita(), indetacao + 1);
    }

    public NoArvore minimo() {
        return minimo(raiz);
    }

    public NoArvore minimo(NoArvore noAtual) {
        while (noAtual != null && noAtual.getEsquerda() != null) {
            noAtual = noAtual.getEsquerda();
        }
        return noAtual;
    }

    public NoArvore maximo() {
        return maximo(raiz);
    }

    public NoArvore maximo(NoArvore noAtual) {
        while (noAtual != null && noAtual.getDireita() != null) {
            noAtual = noAtual.getDireita();
        }
        return noAtual;
    }

    public NoArvore predecessor(NoArvore no) {
        if (no.getEsquerda() != null) {
            return maximo(no.getEsquerda());
        }
        NoArvore noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getEsquerda()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }

    public NoArvore sucessor(NoArvore no) {
        if (no.getDireita() != null) {
            return minimo(no.getDireita());
        }
        NoArvore noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getDireita()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }

    public int altura() {
        return altura(raiz);
    }

    public int altura(NoArvore noAtual) {
        if (noAtual == null) {
            return 0;
        } else {
            int altEsquerda = altura(noAtual.getEsquerda());
            int altDireita = altura(noAtual.getDireita());
            if (altEsquerda > altDireita) {
                return altEsquerda + 1;
            } else {
                return altDireita + 1;
            }

        }
    }

    public void remove(NoArvore noRemove) {
        tamanho--;
        NoArvore noPai = noRemove.getPai();
        if (noRemove.getEsquerda() == null && noRemove.getDireita() == null) {
            if (noPai == null) raiz = null; // É a raiz (sem filhos)
            else {
                if (noRemove == noPai.getEsquerda()) noPai.setEsquerda(null);
                else noPai.setDireita(null);
            }
        } else if (noRemove.getEsquerda() == null || noRemove.getDireita() == null) {
            NoArvore y = noRemove.getEsquerda() != null ? noRemove.getEsquerda()
                    : noRemove.getDireita();
            y.setPai(noPai);
            if (noPai == null) raiz = y; // É a raiz (com um filho)
            else {
                if (noRemove == noPai.getEsquerda()) noPai.setEsquerda(y);
                else noPai.setDireita(y);
            }
        } else {
            NoArvore noSucessor = sucessor(noRemove);
            noRemove.setChave(noSucessor.getChave());
            noRemove.setValor(noSucessor.getValor());
            remove(noSucessor);
        }
    }


}
