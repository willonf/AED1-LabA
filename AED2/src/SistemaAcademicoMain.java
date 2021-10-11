import binarysearchtree.SistemaAcademico;

public class SistemaAcademicoMain {

    public static void main(String[] args) {
        SistemaAcademico arvore = new SistemaAcademico();

        arvore.insere(242, "Scott Summers", "Engenharia", 1.7);
        arvore.insere(159, "Warren Kenneth", "Psicologia", 1.6);
        arvore.insere(101, "Douglas Aarom Ramsey", "computação", 1.5);
        arvore.insere(314 , "Samuel Zachery Guthrie", "Física", 1.8);
        System.out.println(arvore.busca(101));
        arvore.caminhaCentral();
    }
}

