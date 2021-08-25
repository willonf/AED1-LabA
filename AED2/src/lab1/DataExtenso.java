package lab1;

import java.util.Scanner;

public class DataExtenso {
    public void imprimir() {
        Scanner input = new Scanner(System.in);
        String date, day, month, year;
        String[] months = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

        date = input.next();
        day = date.substring(0,2);
        month = months[Integer.parseInt(date.substring(2, 4)) - 1];
        year = date.substring(4, 8);
        System.out.printf("%s de %s de %s\n", day, month, year);
    }

}
