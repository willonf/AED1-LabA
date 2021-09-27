import hashtables.CacheRotas;
import trabalhopratico2.PalavraNo;

public class GoogleMain {

    public static void main(String[] args) {
        PalavraNo p = new PalavraNo("force", "TheJediPath.pdf");
        System.out.println(p.getDocumentosTamanho());
        System.out.println(p.insereDocumento("WaysOfTheForce.pdf"));
        System.out.println(p.toString());
    }
}

