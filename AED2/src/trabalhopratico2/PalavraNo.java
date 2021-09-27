package trabalhopratico2;

public class PalavraNo {
    private String palavra;
    private DocumentoNo documentosTopo;
    private int documentosTamanho = 0;
    private PalavraNo prox;

    public PalavraNo(String palavra, String documento) {
        this.palavra = palavra;
        this.documentosTopo = new DocumentoNo(documento);
        this.prox = null;
        this.documentosTamanho++;
    }

    public DocumentoNo getDocumentosTopo() {
        return this.documentosTopo;
    }

    public int getDocumentosTamanho() {
        return this.documentosTamanho;
    }

    public DocumentoNo getDocumento(int indice) {
        if(indice < 0 || indice >= this.getDocumentosTamanho()){
            return null;
        }
        DocumentoNo doc = this.getDocumentosTopo();
        while(indice-- > 0) {
            doc = doc.getProx();
        }
        return doc;
    }


    public DocumentoNo buscaDocumento(String documento) {
        if (documento == null) { return null; }
        for(DocumentoNo doc = this.getDocumentosTopo(); doc != null; doc=doc.getProx()){
            if (doc.toString().equals(documento)){
                return doc;
            }
        }
        return null;
    }

    public boolean insereDocumento(String documento) {
        if(this.buscaDocumento(documento) == null){
            DocumentoNo newDoc = new DocumentoNo(documento);
            newDoc.setProx(this.getDocumentosTopo());
            this.documentosTopo = newDoc;
            this.documentosTamanho++;
            return true;
        }
        return false;
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
    public String toString() {
        String result = "Palavra ";
        result = result.concat("'").concat(this.getPalavra()).concat("': ");
        for (DocumentoNo doc = this.getDocumentosTopo(); doc != null; doc = doc.getProx()) {
            result = result.concat(doc.toString() + " ");
        }
        return result;
    }

}

