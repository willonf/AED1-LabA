package lab1;

import java.util.Scanner;

public class HorasTrabalho {
    public void operations() {
        Scanner input = new Scanner(System.in);
        int[][] hours = new int[100][7];
        int value, line = 0, column = 0;
        int sumHours = 0;
        while (true) {
            value = input.nextInt();
            if (value == -1) {
                break;
            }
            if (column == 7) {
                line++;
                column = 0;
            }
            hours[line][column] = value;
            column++;
        }
        for (int i = 0; i <= line; i++) {
            for (int j = 0; j < 7; j++) {
                sumHours += hours[i][j];
            }
            System.out.print(sumHours);
            sumHours = 0;
            System.out.println();
        }


    }
}
