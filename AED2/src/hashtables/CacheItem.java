package hashtables;

public class CacheItem {

    // Endereço IP de destino. Chave da tabela hash:
    private String destino;

    // Interface de saída do pacote. Valor da tabela hash:
    private int interfaceSaida;

    private boolean removido;

    public CacheItem(String destino, int interfaceSaida) {
        this.destino = destino;
        this.interfaceSaida = interfaceSaida;
        this.removido = false;
    }

    public String getDestino() {
        return this.destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public int getInterfaceSaida() {
        return this.interfaceSaida;
    }

    public void setInterfaceSaida(int interfaceSaida) {
        this.interfaceSaida = interfaceSaida;
    }

    public boolean isRemovido() {
        return this.removido;
    }

    public void setRemovido(boolean removido) {
        this.removido = removido;
    }
}
