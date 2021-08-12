package lab1;

import java.util.Scanner;

public class IdadeUfam {

    public void imprimeIdadeUfam() {
        Scanner input = new Scanner(System.in);
        int anoAtual;
        int anoFundacaoUfam = 1909;

        anoAtual = input.nextInt();
        System.out.printf("A UFAM tem %d anos de fundacao", anoAtual-anoFundacaoUfam);
    }
}
