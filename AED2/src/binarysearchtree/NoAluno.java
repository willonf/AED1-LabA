package binarysearchtree;

public class NoAluno {
    private int matricula;
    private String nome;
    private String curso;
    private double coeficiente;
    private NoAluno esquerda;
    private NoAluno direita;
    private NoAluno pai;

    public NoAluno(int matricula, String nome, String curso, double coeficiente, NoAluno pai) {
        this.matricula = matricula;
        this.nome = nome;
        this.curso = curso;
        this.coeficiente = coeficiente;
        this.pai = pai;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public double getCoeficiente() {
        return coeficiente;
    }

    public void setCoeficiente(double coeficiente) {
        this.coeficiente = coeficiente;
    }

    public NoAluno getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(NoAluno esquerda) {
        this.esquerda = esquerda;
    }

    public NoAluno getDireita() {
        return direita;
    }

    public void setDireita(NoAluno direita) {
        this.direita = direita;
    }

    public NoAluno getPai() {
        return pai;
    }

    public void setPai(NoAluno pai) {
        this.pai = pai;
    }
}
