package binarysearchtree;

public class SistemaAcademico {
    private NoAluno raiz;
    private int tamanho;

    public SistemaAcademico() {
        this.raiz = null;
        this.tamanho = 0;
    }

    public int tamanho() {
        return this.tamanho;
    }

    public void insere(int matricula, String nome, String curso, double coeficiente) {
        if (raiz == null) {
            raiz = new NoAluno(matricula, nome, curso, coeficiente, null);
            tamanho = 1;
            return;
        }

        NoAluno noAtual = this.raiz;
        NoAluno noPai;

        do {
            noPai = noAtual;
            if (matricula < noAtual.getMatricula()) {
                noAtual = noAtual.getEsquerda();
            } else if (matricula > noAtual.getMatricula()) {
                noAtual = noAtual.getDireita();
            } else {
                noAtual.setMatricula(matricula);
                return;
            }
        } while (noAtual != null);

        NoArvore noNovo = new NoArvore(matricula, valor, noPai);
        if (matricula < noPai.getChave()) {
            noPai.setEsquerda(noNovo);
        } else {
            noPai.setDireita(noNovo);
        }
        this.tamanho++;
    }

}
