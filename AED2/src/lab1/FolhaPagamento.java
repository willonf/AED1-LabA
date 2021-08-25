package lab1;

import java.util.Scanner;

public class FolhaPagamento {
    public void pagamento() {
        double discountIncomeTax = 0.11;
        double discountINSS = 0.08;
        double payPerHour;
        int hours;
        Scanner input = new Scanner(System.in);

        payPerHour = input.nextDouble();
        hours = input.nextInt();

        System.out.printf("Salario bruto: R$%.2f\n", hours * payPerHour);
        System.out.printf("IR: R$%.2f\n", hours * payPerHour * discountIncomeTax);
        System.out.printf("INSS: R$%.2f\n", hours * payPerHour * discountINSS);
        System.out.printf("Total de descontos: R$%.2f\n", hours * payPerHour * (discountIncomeTax + discountINSS));
        System.out.printf("Salario liquido: R$%.2f\n", hours * payPerHour - hours * payPerHour * (discountIncomeTax + discountINSS));

    }
}
