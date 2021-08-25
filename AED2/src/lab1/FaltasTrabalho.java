package lab1;

import java.util.Scanner;

public class FaltasTrabalho {
    public void operations() {
        Scanner input = new Scanner(System.in);
        int[] absentsArray = new int[100];
        double[] absentsPercentArray = new double[100];
        int day;
        int length = 0;


        for (int i = 0; i < absentsArray.length; i++) {
            day = input.nextInt();
            if (day == -1) {
                break;
            }
            absentsArray[i] = day;
            absentsPercentArray[day - 1]++;
            length++;
        }
        for (int i = 1; i < 7; i++) {
            System.out.printf("%.1f ", absentsPercentArray[i] * 100 / length);
        }

    }
}
