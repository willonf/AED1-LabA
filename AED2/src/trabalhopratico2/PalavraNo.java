package trabalhopratico2;

public class PalavraNo {
    private String palavra;
    private DocumentoNo documentosTopo;
    private int documentosTamanho;
    private PalavraNo prox;

    public PalavraNo(String palavra, String documento) {
        this.palavra = palavra;
        this.documentosTopo = new DocumentoNo(documento);
        this.prox = null;
    }

    public DocumentoNo getDocumentosTopo() {
        return this.documentosTopo;
    }

    public int getDocumentosTamanho() {
        return this.documentosTamanho;
    }

    public DocumentoNo buscaDocumento(String documento) {

    }

    public boolean insereDocumento(String documento) {
        
    }

    public PalavraNo getProx() {
        return this.prox;
    }
    
    public void setProx(PalavraNo prox) {
        this.prox = prox;
    }

    public String getPalavra() {
        return palavra;
    }

    public void setPalavra(String palavra) {
        this.palavra = palavra;
    }

    @Override
    public String toString(){
        String result = "Palavra ";
        result = result.concat("'").concat(this.getPalavra()).concat("'");
        for (:
             ) {
            
        }
    }
    
}

