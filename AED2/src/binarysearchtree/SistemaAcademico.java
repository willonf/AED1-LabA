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
                noAtual.setNome(nome);
                noAtual.setCurso(curso);
                noAtual.setCoeficiente(coeficiente);
                return;
            }
        } while (noAtual != null);

        NoAluno noNovo = new NoAluno(matricula, nome, curso, coeficiente, noPai);
        if (matricula < noPai.getMatricula()) {
            noPai.setEsquerda(noNovo);
        } else {
            noPai.setDireita(noNovo);
        }
        this.tamanho++;
    }

    public NoAluno busca(int matricula) {
        NoAluno noAtual = this.raiz;

        while (noAtual != null && noAtual.getMatricula() != matricula) {
            if (matricula < noAtual.getMatricula()) {
                noAtual = noAtual.getEsquerda();
            } else {
                noAtual = noAtual.getDireita();
            }
        }

        return noAtual;
    }

    public void caminhaCentral() {
        caminhaCentral(raiz);
    }

    public void caminhaCentral(NoAluno subArvore) {
        if (subArvore != null) {
            caminhaCentral(subArvore.getEsquerda());
            System.out.printf("%d - %s (%s)\n", subArvore.getMatricula(), subArvore.getNome(), subArvore.getCurso());
            caminhaCentral(subArvore.getDireita());
        }
    }

}
