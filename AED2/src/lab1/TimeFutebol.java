package lab1;

import java.util.Arrays;
import java.util.Scanner;

public class TimeFutebol {
    public void operations() {
        Scanner input = new Scanner(System.in);
        int[] arrayTeam = new int[100];
        int[] arrayAdv = new int[100];
        int value, countVictories = 0, countDraws = 0, countDefeats = 0;

        for (int i = 0; i < arrayTeam.length; i++) {
            value = input.nextInt();
            if (value == -1) {
                break;
            }
            arrayTeam[i] = value;
        }

        for (int i = 0; i < arrayAdv.length; i++) {
            value = input.nextInt();
            if (value == -1) {
                break;
            }
            arrayAdv[i] = value;

            if (value == arrayTeam[i]) {
                countDraws++;
            } else if (value > arrayTeam[i]) {
                countDefeats++;
            } else {
                countVictories++;
            }
        }

        System.out.printf("%d %d %d", countVictories, countDraws, countDefeats);

    }
}
