package lab1;

import java.util.Scanner;

public class Media {
    public void media() {
        Scanner input = new Scanner(System.in);
        double number1, number2, number3, avg;

        number1 = input.nextDouble();
        number2 = input.nextDouble();
        number3 = input.nextDouble();
        avg = (number1 + number2 + number3) / 3;
        System.out.printf("%.2f", avg);
    }
}
