package avltree;

public class ArvoreAVL {

    private NoArvoreAVL raiz;
    private int tamanho;

    public ArvoreAVL() {
        raiz = null;
        tamanho = 0;
    }

    public NoArvoreAVL getRaiz() {
        return raiz;
    }

    public int tamanho() {
        return tamanho;
    }

    public void insere(int chave, Object valor) {
        if (raiz == null) {
            raiz = new NoArvoreAVL(chave, valor, null);
            tamanho = 1;
            return;
        }

        NoArvoreAVL noAtual = raiz;
        NoArvoreAVL noPai;

        do {
            noPai = noAtual;
            if (chave < noAtual.getChave())      noAtual=noAtual.getEsquerda();
            else if (chave > noAtual.getChave()) noAtual=noAtual.getDireita();
            else {
                noAtual.setValor(valor);
                return;
            }
        } while (noAtual != null);

        NoArvoreAVL noNovo = new NoArvoreAVL(chave, valor, noPai);
        if (chave < noPai.getChave()) noPai.setEsquerda(noNovo);
        else                          noPai.setDireita(noNovo);

        tamanho++;
        verificarBalanceamento(noNovo);
    }

    public NoArvoreAVL busca(int chave) {
        NoArvoreAVL noAtual = raiz;

        while (noAtual != null && noAtual.getChave() != chave) {
            if (chave < noAtual.getChave())
                noAtual = noAtual.getEsquerda();
            else
                noAtual = noAtual.getDireita();
        }

        return noAtual;
    }

    public void caminhaPreOrdem() {
        caminhaPreOrdem(raiz);
    }

    public void caminhaPreOrdem(NoArvoreAVL subArvore) {
        if (subArvore != null) {
            System.out.print(subArvore.getChave() + " ");
            caminhaPreOrdem(subArvore.getEsquerda());
            caminhaPreOrdem(subArvore.getDireita());
        }
    }

    public void caminhaPosOrdem() {
        caminhaPosOrdem(raiz);
    }

    public void caminhaPosOrdem(NoArvoreAVL subArvore) {
        if (subArvore != null) {
            caminhaPosOrdem(subArvore.getEsquerda());
            caminhaPosOrdem(subArvore.getDireita());
            System.out.print(subArvore.getChave() + " ");
        }
    }

    public void caminhaCentral() {
        caminhaCentral(raiz);
    }

    public void caminhaCentral(NoArvoreAVL subArvore) {
        if (subArvore != null) {
            caminhaCentral(subArvore.getEsquerda());
            System.out.print(subArvore.getChave() + " ");
            caminhaCentral(subArvore.getDireita());
        }
    }  

    public void caminhaIdentado() {
        caminhaIdentado(raiz, 0);
    }
    public void caminhaIdentado(NoArvoreAVL subArvore, int identacao) {
        if (subArvore == null) return;

        for (int i=0; i<identacao; i++) System.out.print("  ");

        System.out.println(subArvore.getChave());
        caminhaIdentado(subArvore.getEsquerda(), identacao+1);
        caminhaIdentado(subArvore.getDireita(), identacao+1);
    }

    public void caminhaIdentadoDE() {
        caminhaIdentadoDE(raiz, 0, 'R');
    }
    public void caminhaIdentadoDE(NoArvoreAVL subArvore, int identacao, char de) {
        if (subArvore == null) return;

        for (int i=0; i<identacao; i++) System.out.print("  ");
        System.out.print(de + ": ");

        System.out.println(subArvore.getChave());
        caminhaIdentadoDE(subArvore.getEsquerda(), identacao+1, 'E');
        caminhaIdentadoDE(subArvore.getDireita(), identacao+1, 'D');
    }

    public NoArvoreAVL minimo() {
        return minimo(raiz);
    }
    public NoArvoreAVL minimo(NoArvoreAVL noAtual) {
        while (noAtual!= null && noAtual.getEsquerda() != null)
            noAtual = noAtual.getEsquerda();
        return noAtual;
    }

    public NoArvoreAVL maximo() {
        return maximo(raiz);
    }
    public NoArvoreAVL maximo(NoArvoreAVL noAtual) {
        while (noAtual!= null && noAtual.getDireita() != null)
            noAtual = noAtual.getDireita();
        return noAtual;
    }

    public NoArvoreAVL predecessor(NoArvoreAVL no) {
        if (no.getEsquerda() != null)
            return maximo(no.getEsquerda());

        NoArvoreAVL noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getEsquerda()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }  

    public NoArvoreAVL sucessor(NoArvoreAVL no) {
        if (no.getDireita() != null)
            return minimo(no.getDireita());

        NoArvoreAVL noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getDireita()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }

    public int altura() {
        return altura(raiz);
    }
    public int altura(NoArvoreAVL noAtual) {
        if (noAtual == null) return 0;
        else {
            int altEsquerda = altura(noAtual.getEsquerda());
            int altDireita  = altura(noAtual.getDireita());
            if (altEsquerda > altDireita) return altEsquerda + 1;
            else return altDireita + 1;
        }
    }

    public void remove(NoArvoreAVL noRemove) {
        tamanho--;
        NoArvoreAVL noPai = noRemove.getPai();

        if (noRemove.getEsquerda() == null && noRemove.getDireita() == null) {
            if (noPai == null) raiz = null; // É a raiz (sem filhos)
            else {
                if (noRemove == noPai.getEsquerda()) noPai.setEsquerda(null);
                else                                 noPai.setDireita(null);
            }
        }

        else if (noRemove.getEsquerda()==null || noRemove.getDireita()==null){
            NoArvoreAVL y = noRemove.getEsquerda() != null ? noRemove.getEsquerda()
                    : noRemove.getDireita();
            y.setPai(noPai);
            if (noPai == null) raiz = y; // É a raiz (com um filho)
            else {
                if (noRemove == noPai.getEsquerda()) noPai.setEsquerda(y);
                else                                 noPai.setDireita(y);
            }
        }

        else {
            NoArvoreAVL noSucessor = sucessor(noRemove);
            noRemove.setChave(noSucessor.getChave());
            noRemove.setValor(noSucessor.getValor());
            remove(noSucessor);
        }

        if (noPai != null) verificarBalanceamento(noPai);

    }

    /*
     * O código acima veio dos slides da disciplina com modificações mínimas para
     * incluir o balanceamento AVL (última linha dos métodos insere e remove).
     * 
     * A parte de balanceamento abaixo foi baseada na implementação disponível em
     *   - https://gist.github.com/rodrigovilar/5754425
     * que foi baseada na implementação original disponível em
     *   - http://blog.blackbam.at/2012/05/04/avl-tree-implementation-in-java/
     */
    public void verificarBalanceamento(NoArvoreAVL atual) {
        setBalanceamento(atual);
        int balanceamento = atual.getBalanceamento();

        if (balanceamento == -2) {

            if (altura(atual.getEsquerda().getEsquerda()) >= altura(atual.getEsquerda().getDireita())) {
                atual = rotacaoDireita(atual);

            } else {
                atual = duplaRotacaoEsquerdaDireita(atual);
            }

        } else if (balanceamento == 2) {

            if (altura(atual.getDireita().getDireita()) >= altura(atual.getDireita().getEsquerda())) {
                atual = rotacaoEsquerda(atual);

            } else {
                atual = duplaRotacaoDireitaEsquerda(atual);
            }
        }

        if (atual.getPai() != null) {
            verificarBalanceamento(atual.getPai());
        } else {
            this.raiz = atual;
        }
    }

    private void setBalanceamento(NoArvoreAVL no) {
        no.setBalanceamento(altura(no.getDireita()) - altura(no.getEsquerda()));
    }  

    public NoArvoreAVL rotacaoEsquerda(NoArvoreAVL inicial) {
        NoArvoreAVL direita = inicial.getDireita();
        direita.setPai(inicial.getPai());

        inicial.setDireita(direita.getEsquerda());

        if (inicial.getDireita() != null) {
            inicial.getDireita().setPai(inicial);
        }

        direita.setEsquerda(inicial);
        inicial.setPai(direita);

        if (direita.getPai() != null) {

            if (direita.getPai().getDireita() == inicial) {
                direita.getPai().setDireita(direita);

            } else if (direita.getPai().getEsquerda() == inicial) {
                direita.getPai().setEsquerda(direita);
            }
        }

        setBalanceamento(inicial);
        setBalanceamento(direita);

        return direita;
    }

    public NoArvoreAVL rotacaoDireita(NoArvoreAVL inicial) {
        NoArvoreAVL esquerda = inicial.getEsquerda();
        esquerda.setPai(inicial.getPai());

        inicial.setEsquerda(esquerda.getDireita());

        if (inicial.getEsquerda() != null) {
            inicial.getEsquerda().setPai(inicial);
        }

        esquerda.setDireita(inicial);
        inicial.setPai(esquerda);

        if (esquerda.getPai() != null) {

            if (esquerda.getPai().getDireita() == inicial) {
                esquerda.getPai().setDireita(esquerda);

            } else if (esquerda.getPai().getEsquerda() == inicial) {
                esquerda.getPai().setEsquerda(esquerda);
            }
        }

        setBalanceamento(inicial);
        setBalanceamento(esquerda);

        return esquerda;
    }

    public NoArvoreAVL duplaRotacaoEsquerdaDireita(NoArvoreAVL inicial) {
        inicial.setEsquerda(rotacaoEsquerda(inicial.getEsquerda()));
        return rotacaoDireita(inicial);
    }

    public NoArvoreAVL duplaRotacaoDireitaEsquerda(NoArvoreAVL inicial) {
        inicial.setDireita(rotacaoDireita(inicial.getDireita()));
        return rotacaoEsquerda(inicial);
    }

}
