package lab1;

import java.util.Scanner;

public class PorcentagemAcerto {
    public void calcularAcertos() {
        int respostas[] = new int[100];
        int gabarito[] = new int[100];
        int valor = 0;
        int count = -1;
        int acertos = 0;
        Scanner input = new Scanner(System.in);

        for (int i = 0; valor != -1; i++) {
            valor = input.nextInt();
            respostas[i] = valor;
            count++;
        }
        valor = 0;
        for (int i = 0; valor != -1; i++) {
            valor = input.nextInt();
            gabarito[i] = valor;
            if(gabarito[i] == respostas[i]) {
                acertos++;
            }
        }
        System.out.printf("%.2f", (acertos/count)*100);
    }
}
