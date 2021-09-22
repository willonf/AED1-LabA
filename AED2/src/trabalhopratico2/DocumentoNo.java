package trabalhopratico2;

public class DocumentoNo {
    private String documento;
    private DocumentoNo prox;

    public DocumentoNo(String documento) {
        this.documento = documento;
    }

    public DocumentoNo getProx() {
        return prox;
    }

    public void setProx(DocumentoNo prox) {
        this.prox = prox;
    }

    @Override
    public String toString() {
        return this.documento;
    }
}
