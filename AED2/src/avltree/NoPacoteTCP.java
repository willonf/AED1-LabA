package avltree;

public class NoPacoteTCP {
    private int sequencia; //chave
    private int portaOrigem; //valor1
    private int portaDestino; //valor2
    private NoPacoteTCP esquerda;
    private NoPacoteTCP direita;
    private NoPacoteTCP pai;
    private int balanceamento;

    public NoPacoteTCP(int sequencia, int portaOrigem, int portaDestino, NoPacoteTCP pai) {
        this.sequencia = sequencia;
        this.portaOrigem = portaOrigem;
        this.portaDestino = portaDestino;
        this.pai = pai;
    }

    public int getSequencia() {
        return sequencia;
    }

    public void setSequencia(int sequencia) {
        this.sequencia = sequencia;
    }

    public int getPortaOrigem() {
        return portaOrigem;
    }

    public void setPortaOrigem(int portaOrigem) {
        this.portaOrigem = portaOrigem;
    }

    public int getPortaDestino() {
        return portaDestino;
    }

    public void setPortaDestino(int portaDestino) {
        this.portaDestino = portaDestino;
    }

    public NoPacoteTCP getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(NoPacoteTCP esquerda) {
        this.esquerda = esquerda;
    }

    public NoPacoteTCP getDireita() {
        return direita;
    }

    public void setDireita(NoPacoteTCP direita) {
        this.direita = direita;
    }

    public NoPacoteTCP getPai() {
        return pai;
    }

    public void setPai(NoPacoteTCP pai) {
        this.pai = pai;
    }

    public int getBalanceamento() {
        return balanceamento;
    }

    public void setBalanceamento(int balanceamento) {
        this.balanceamento = balanceamento;
    }

    public String toString() {
        return String.format("Seq: %d, Origem: %d, Destino: %d", this.sequencia, this.portaOrigem, this.portaDestino);
    }
}
