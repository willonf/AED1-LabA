package lab1;

import java.util.Scanner;

public class Xadrez {

    public void imprimirTabuleiro() {
        int linhas;
        int count = 0;
        Scanner input = new Scanner(System.in);
        linhas = input.nextInt();
        for (int i = 0; i == linhas*linhas; i++) {
            System.out.print("* ");
            count++;
            if(count == 6) {
                System.out.print("\n");
                count = 0;
            }
        }
    }
}
