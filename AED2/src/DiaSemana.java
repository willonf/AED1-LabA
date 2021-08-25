import java.util.Arrays;
import java.util.Scanner;

public class DiaSemana {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[][] hours = new int[100][7];
        int[] hoursByDay = new int[7];
        int value, line = 0, column = 0;
        int sumHours = 0, index = 0, maior;
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

        for (int columnIndex = 0; columnIndex < 7; columnIndex++) {
            for (int lineIndex = 0; lineIndex <= line; lineIndex++) {
                sumHours += hours[lineIndex][columnIndex];
            }
            hoursByDay[index] = sumHours;
            sumHours = 0;
            index++;
        }
        maior = hoursByDay[0];
        for (int i = 1; i < 7; i++) {
            if (hoursByDay[i] > maior) {
                maior = hoursByDay[i];
            }
        }
        for (int i = 0; i < 7; i++) {
            if (maior == hoursByDay[i]) {
                System.out.printf("%d\n", i + 1);
            }
        }

    }
}
