package hashtables;

public class Item {
    private String chave;
    private Object valor;
    private boolean removido;

    public Item(String chave, Object valor, boolean removido) {
        this.chave = chave;
        this.valor = valor;
        this.removido = removido;
    }


    public String getChave() {
        return chave;
    }

    public void setChave(String chave) {
        this.chave = chave;
    }

    public Object getValor() {
        return valor;
    }

    public void setValor(Object valor) {
        this.valor = valor;
    }

    public boolean isRemovido() {
        return removido;
    }

    public void setRemovido() {
        this.removido = !this.removido;
    }
}
