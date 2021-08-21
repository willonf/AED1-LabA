package lab1;

import java.util.Scanner;

public class ArteAscii {
    public void imprimir() {

        Scanner input = new Scanner(System.in);
        String character = "";
        int cutValue;
        int base = input.nextInt();

        cutValue = base - 1;
        for (int i = 0; i < base; i++) {
            character = character.concat("*");
        }
        for (int i = 0; i < base; i++) {
            System.out.printf("%s\n", character);
            character = character.substring(0, cutValue);
            cutValue--;
        }


        character = "*";
        for (int i = 0; i < base; i++) {
            System.out.printf("%s\n", character);
            character = character.concat("*");
        }
    }
}
