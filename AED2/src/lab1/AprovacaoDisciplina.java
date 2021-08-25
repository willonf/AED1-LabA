package lab1;

import java.util.Scanner;

public class AprovacaoDisciplina {
    public void operations() {
        Scanner input = new Scanner(System.in);
        double[] arrayGrades = new double[100];
        int[] arrayFrequency = new int[100];
        int workload, frequency, count = 0;
        double grade, workloadPercent;
        int approved = 0, notApprovedByGrade = 0, notApprovedByFrequency = 0;

        for (int i = 0; i < arrayGrades.length; i++) {
            grade = input.nextDouble();
            if (grade == -1) {
                break;
            }
            count++;
            arrayGrades[i] = grade;
        }

        for (int i = 0; i < arrayGrades.length; i++) {
            frequency = input.nextInt();
            if (frequency == -1) {
                break;
            }
            arrayFrequency[i] = frequency;
        }

        workload = input.nextInt();
        for (int i = 0; i < count; i++) {
            workloadPercent = ((double) arrayFrequency[i]) / workload;
            if (arrayGrades[i] >= 5 && workloadPercent >= 0.75) {
                approved++;
            } else if (workloadPercent < 0.75) {
                notApprovedByFrequency++;
            } else{
                notApprovedByGrade++;
            }
        }

        System.out.printf("%d %d %d", approved, notApprovedByGrade, notApprovedByFrequency);


    }
}
