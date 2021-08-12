import java.util.Scanner;

public class PorcentagemAcerto {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] respostas = new int[100];
        int[] gabarito = new int[100];
        int valor = 0;
        int count = -1;
        int acertos = 0;
        double porc;

        for (int i = 0; valor != -1; i++) {
            valor = input.nextInt();
            respostas[i] = valor;
            count++;
        }
        valor = 0;
        for (int i = 0; valor != -1; i++) {
            valor = input.nextInt();
            gabarito[i] = valor;
            if(gabarito[i] == respostas[i] && gabarito[i] != -1) {
                acertos++;
            }
        }
        porc = ((double)acertos/count)*100;
        System.out.printf("%.2f", porc);
    }
}