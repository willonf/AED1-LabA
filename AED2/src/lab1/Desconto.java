package lab1;

import java.util.Scanner;

public class Desconto {
    public void calculoDesconto() {
        Scanner input = new Scanner(System.in);
        double valorCompra;
        valorCompra = input.nextDouble();
        if (valorCompra >= 200) {
            System.out.printf("%.2f", valorCompra * 0.95);
        } else {
            System.out.printf("%.2f", valorCompra);

        }
    }
}
