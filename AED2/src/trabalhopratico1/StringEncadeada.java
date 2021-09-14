package trabalhopratico1;

public class StringEncadeada {

    private StringNo topo;
    private StringNo cauda;
    private int tamanho;

    public StringEncadeada() {
        topo = null;
        cauda = null;
        tamanho = 0;
    }

    public StringEncadeada(String conteudo) {
        StringEncadeada str = new StringEncadeada();
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

        if (this.getTopo() == null) {
            this.topo = newChar;
            this.cauda = newChar;
        } else {
            StringNo temp;
            temp = this.cauda;
            newChar.setAnt(temp);
            temp.setProx(newChar);
            this.cauda = newChar;
        }
//        this.topo = newChar;
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
            if (noAtual.getCaractere() == ch) {
                break;
            }
            index++;
        }
        return index;
    }

    public boolean equals(StringEncadeada str) {
        boolean isEqual = true;
        if (str.length() != this.length()) {
            isEqual = false;
        }
        StringNo paramStr = str.getTopo();
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
            if (noAtual.getCaractere() != paramStr.getCaractere()) {
                isEqual = false;
                break;
            }
            paramStr = paramStr.getProx();
        }
        return isEqual;
    }

    public void concat(StringEncadeada str) {
        this.cauda.setProx(str.getTopo());
        this.cauda = str.cauda;
        str.topo.setAnt(this.cauda.getAnt());
        this.tamanho = this.length() + str.tamanho;
    }

    public void replace(char oldChar, char newChar) {
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
           if (noAtual.getCaractere() == oldChar){
               noAtual.setCaractere(newChar);
           }
        }
    }

    public int compareTo(StringEncadeada anotherString) {
        StringNo paramStr = anotherString.getTopo();
        int result = 0;
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
            if(noAtual.getCaractere() != paramStr.getCaractere()){
                result = noAtual.getCaractere() - paramStr.getCaractere();
            }
        }
        return result;

    }

    public String toString() {
        String result = "";
        int num = 0;
        for (StringNo noAtual = this.getTopo(); noAtual != null; noAtual = noAtual.getProx()) {
//            System.out.print(noAtual.getCaractere());
            result = result + noAtual.getCaractere();
        }
        return result;
    }


}