package lab1;

import java.util.Arrays;
import java.util.Scanner;

public class OperacoesInteiros {
    public void operations() {
        Scanner input = new Scanner(System.in);
        int[] array = new int[100];
        int value, bigger, smaller;
        int sum = 0, count = 0, countOdds = 0, countEvens = 0;
        double avg;

        while (true) {
            value = input.nextInt();
            if (value == -1) {
                break;
            }

            array[0] = value;
            count++;
            sum += value;
            if (value % 2 == 0) {
                countEvens++;
            } else {
                countOdds++;
            }

            for (int i = 1; i < array.length; i++) {
                value = input.nextInt();

                if (value == -1) {
                    break;
                }

                array[i] = value;
                count++;
                sum += value;
                if (value % 2 == 0) {
                    countEvens++;
                } else {
                    countOdds++;
                }
            }

            bigger = array[0];
            smaller = array[0];

            for (int i = 1; i < count; i++) {
                if (array[i] >= bigger) {
                    bigger = array[i];
                }
                if (array[i] <= smaller) {
                    smaller = array[i];
                }
            }
            avg = ((double) Arrays.stream(array).sum()) / count;

            System.out.println(count);
            System.out.println(countEvens);
            System.out.println(countOdds);
            System.out.println(Arrays.stream(array).sum());
            System.out.printf("%.2f\n", avg);
            System.out.println(bigger);
            System.out.println(smaller);

            value = 0;
            array = new int[100];
            sum = 0;
            count = 0;
            countEvens = 0;
            countOdds = 0;
        }
    }
}
