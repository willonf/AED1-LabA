import hashtables.CacheRotas;

public class CacheMain {

    public static void main(String[] args) {
        CacheRotas c = new CacheRotas(20);
        System.out.println(c.tamanho());
        c.insere("192.168.200.5", 3);
        c.insere("192.168.200.2", 5);
        c.insere("192.168.200.6", 4);
        c.insere("192.168.200.123", 92);
        c.insere("192.168.200.7", 5);
        System.out.println(c.tamanho());
        c.imprime();
        System.out.println(c.busca("192.168.200.7").getInterfaceSaida());
        c.remove("192.168.200.123");
        c.imprime();
    }
}

