package avltree;

public class ArvorePacotesForaDeOrdem {
    private NoPacoteTCP raiz;
    private int tamanho;
    private int ultimaSequencia;

    public ArvorePacotesForaDeOrdem() {
        this.setRaiz(null);
        this.setTamanho(0);
    }

    public NoPacoteTCP getRaiz() {
        return raiz;
    }

    public void setRaiz(NoPacoteTCP raiz) {
        this.raiz = raiz;
    }

    public int tamanho() {
        return this.tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public int getUltimaSequencia() {
        return ultimaSequencia;
    }

    public void setUltimaSequencia(int ultimaSequencia) {
        this.ultimaSequencia = ultimaSequencia;
    }

    public void insere(int sequencia, int portaOrigem, int portaDestino) {
        if (getRaiz() == null) {
            this.raiz = new NoPacoteTCP(sequencia, portaOrigem, portaDestino, null);
            this.setTamanho(1);
            return;
        }

        NoPacoteTCP noAtual = this.getRaiz();
        NoPacoteTCP noPai;

        do {
            noPai = noAtual;
            if (sequencia < noAtual.getSequencia()) {
                noAtual = noAtual.getEsquerda();
            } else if (sequencia > noAtual.getSequencia()) {
                noAtual = noAtual.getDireita();
            } else {
                noAtual.setPortaOrigem(portaOrigem);
                noAtual.setPortaDestino(portaDestino);
            }
        } while (noAtual != null);

        NoPacoteTCP noNovo = new NoPacoteTCP(sequencia, portaOrigem, portaDestino, noPai);
        if (sequencia < noPai.getSequencia()) {
            noPai.setEsquerda(noNovo);
        } else {
            noPai.setDireita(noNovo);
        }
        this.setTamanho(this.tamanho() + 1);
        this.verificarBalanceamento(noNovo);
        this.setUltimaSequencia(sequencia);
    }

    public NoPacoteTCP minimo() {
        return this.minimo(this.getRaiz());
    }

    public NoPacoteTCP minimo(NoPacoteTCP noAtual) {
        while (noAtual != null && noAtual.getEsquerda() != null) {
            noAtual = noAtual.getEsquerda();
        }
        return noAtual;
    }

    public NoPacoteTCP maximo() {
        return this.maximo(this.getRaiz());
    }

    public NoPacoteTCP maximo(NoPacoteTCP noAtual) {
        while (noAtual != null && noAtual.getDireita() != null) {
            noAtual = noAtual.getDireita();
        }
        return noAtual;
    }

    public NoPacoteTCP predecessor(NoPacoteTCP no) {
        if (no.getEsquerda() != null) {
            return maximo(no.getEsquerda());
        }

        NoPacoteTCP noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getEsquerda()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }

    public NoPacoteTCP sucessor(NoPacoteTCP no) {
        if (no.getDireita() != null) {
            return maximo(no.getDireita());
        }

        NoPacoteTCP noAtual = no.getPai();
        while (noAtual != null && no == noAtual.getDireita()) {
            no = noAtual;
            noAtual = noAtual.getPai();
        }
        return noAtual;
    }

    public int altura() {
        return this.altura(this.getRaiz());
    }

    public int altura(NoPacoteTCP noAtual) {
        if (noAtual == null) {
            return 0;
        } else {
            int alturaEsquerda = this.altura(noAtual.getEsquerda());
            int alturaDireita = this.altura(noAtual.getDireita());
            if (alturaEsquerda > alturaDireita) {
                return alturaEsquerda + 1;
            } else {
                return alturaDireita + 1;
            }
        }
    }

    public void remove(NoPacoteTCP noRemove) {
        this.setTamanho(this.tamanho() - 1);

        NoPacoteTCP noPai = noRemove.getPai();

        if (noRemove.getEsquerda() == null && noRemove.getDireita() == null) {
            if (noPai == null) {
                this.setRaiz(null);
            } else {
                if (noRemove == noPai.getEsquerda()) {
                    noPai.setEsquerda(null);
                } else {
                    noPai.setDireita(null);
                }
            }
        } else if (noRemove.getEsquerda() == null || noRemove.getDireita() == null) {
            NoPacoteTCP y = noRemove.getEsquerda() != null ? noRemove.getEsquerda() : noRemove.getDireita();
            y.setPai(noPai);

            if (noPai == null) {
                this.setRaiz(y);
            } else {
                if (noRemove == noPai.getEsquerda()) {
                    noPai.setEsquerda(y);
                } else {
                    noPai.setDireita(y);
                }
            }
        } else {
            NoPacoteTCP noSucessor = this.sucessor(noRemove);
            noRemove.setSequencia(noSucessor.getSequencia());
            noRemove.setPortaOrigem(noRemove.getPortaOrigem());
            noRemove.setPortaDestino(noRemove.getPortaDestino());
        }

        if (noPai != null) {
            this.verificarBalanceamento(noPai);
        }
    }

    public void verificarBalanceamento(NoPacoteTCP atual) {
        this.setBalanceamento(atual);

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
            this.verificarBalanceamento(atual.getPai());
        } else {
            this.setRaiz(atual);
        }
    }

    private void setBalanceamento(NoPacoteTCP no) {
        no.setBalanceamento(altura(no.getDireita()) - altura(no.getEsquerda()));
    }


    public NoPacoteTCP rotacaoEsquerda(NoPacoteTCP inicial) {
        NoPacoteTCP direita = inicial.getDireita();
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

        this.setBalanceamento(inicial);
        this.setBalanceamento(direita);
        return direita;

    }

    public NoPacoteTCP rotacaoDireita(NoPacoteTCP inicial) {
        NoPacoteTCP esquerda = inicial.getEsquerda();
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

        this.setBalanceamento(inicial);
        this.setBalanceamento(esquerda);

        return esquerda;

    }

    public NoPacoteTCP duplaRotacaoEsquerdaDireita(NoPacoteTCP inicial) {

        inicial.setEsquerda(rotacaoEsquerda(inicial.getEsquerda()));

        return rotacaoDireita(inicial);

    }

    public NoPacoteTCP duplaRotacaoDireitaEsquerda(NoPacoteTCP inicial) {
        inicial.setDireita(rotacaoDireita(inicial.getDireita()));
        return rotacaoEsquerda(inicial);
    }

    public void caminhaCentral() {
        this.caminhaCentral(this.getRaiz());
    }

    public void caminhaCentral(NoPacoteTCP subArvore){
        if(subArvore != null) {
            this.caminhaCentral(subArvore.getEsquerda());
            System.out.println(subArvore);
            this.caminhaCentral(subArvore.getDireita());
        }
    }

    public void pacoteRecebido(int sequencia, int portaOrigem, int portaDestino) {

        if (sequencia - this.getUltimaSequencia() == 1) {
            NoPacoteTCP noNovo = new NoPacoteTCP(sequencia, portaOrigem, portaDestino, null);
            this.setUltimaSequencia(noNovo.getSequencia());
            System.out.println(noNovo);
            this.caminhaCentral();
            // Remove nó
            // Atualiza a última sequência
        } else {
            this.insere(sequencia, portaOrigem, portaDestino);
            System.out.printf("Fora de ordem: %d%n", sequencia);
        }
    }


}
