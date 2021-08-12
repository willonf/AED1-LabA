package lab1;

import java.util.Scanner;

public class ContaEnergia {
    public void precoAPagar(){
        Scanner input = new Scanner(System.in);
        double consumoEnergia;
        char tipoInstalacao;
        double preco = 0;

        consumoEnergia = input.nextDouble();
        tipoInstalacao = input.next().toUpperCase().charAt(0);
        switch (tipoInstalacao){
            case 'R':
                preco = consumoEnergia <= 500 ? 0.40 : 0.65;
                break;
            case 'I':
                preco = consumoEnergia <= 1000 ? 0.55 : 0.60;
                break;
            case 'C':
                preco = consumoEnergia <= 5000 ? 0.55 : 0.60;
                break;
        }
        System.out.printf("%.2f", consumoEnergia * preco);

    }
}
