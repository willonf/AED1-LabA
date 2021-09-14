package trabalhopratico1;

public class StringNo {
    private char caractere;
    private StringNo ant;
    private StringNo prox ;

    public StringNo(char caractere) {
        this.caractere = caractere;
    }

    public char getCaractere() {
        return caractere;
    }

    public void setCaractere(char caractere) {
        this.caractere = caractere;
    }

    public StringNo getAnt() {
        return ant;
    }

    public void setAnt(StringNo ant) {
        this.ant = ant;
    }

    public StringNo getProx() {
        return prox;
    }

    public void setProx(StringNo prox) {
        this.prox = prox;
    }
}
