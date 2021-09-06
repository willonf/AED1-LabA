package trabalhopratico1;

public class StringEncadeada {

    private StringNo topo;
    private StringNo cauda;
    private int tamanho;

    public StringEncadeada() {
        this.topo = null;
        this.cauda = null;
        this.tamanho = 0;
    }

    public StringEncadeada(String conteudo) {
        for (int i = 0; i < conteudo.length(); i++) {
            this.insereFim(conteudo.charAt(i));
        }

    }

    public StringEncadeada(char[] conteudo) {
        for (char c : conteudo) {
            this.insereFim(c);
        }
    }

    public StringEncadeada(StringEncadeada conteudo) {
        this.tamanho = conteudo.length();
        this.topo = conteudo.getTopo();
        this.cauda = conteudo.getCauda();
    }

    public StringNo getTopo() {
        return this.topo;
    }

    public StringNo getCauda() {
        return this.cauda;
    }

    public void insereInicio(char c) {
        StringNo newChar = new StringNo(c);
        newChar.setProx(this.getTopo());

        if (this.getTopo() != null) {
            this.topo.setAnt(newChar);
        } else {
            this.cauda = newChar;
        }
        this.topo = newChar;
        this.tamanho++;
    }

    public void insereFim(char c) {
        StringNo newChar = new StringNo(c);
        newChar.setProx(null);

        if (this.getTopo() == null) {
            this.topo = newChar;
        } else {
            newChar.setAnt(this.getCauda());
            this.cauda = newChar;
        }
        this.tamanho++;

    }

    public boolean isEmpty() {
        return this.length() == 0;
    }

    public int length() {
        return this.tamanho;
    }

    public char charAt(int index) {
        if (index < 0 || index >= this.tamanho) {
            return 0;
        }
        StringNo noAtual = this.getTopo();

        while (index-- > 0) {
            noAtual = noAtual.getProx();
        }
        return noAtual.getCaractere();
    }

    public int indexOf(int ch) {
        int index = 0;
        boolean contains = false;
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
            System.out.println(noAtual.getCaractere());
        }
        return index;
    }

    public boolean equals(Object str) {
        return true;
    }

    public void concat(StringEncadeada str) {
        this.cauda.setProx(str.getTopo());
        this.cauda = str.cauda;
        str.topo.setAnt(this.cauda.getAnt());
        this.tamanho = this.length() + str.tamanho;
    }

    public void replace(char oldChar, char newChar) {

    }

    public int compareTo(StringEncadeada anotherString) {
        return 1;
    }

    public void toStr() {
        StringBuilder result = new StringBuilder("");
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
            System.out.println(noAtual.getCaractere());
        }
//        return result.toString();
    }


}
