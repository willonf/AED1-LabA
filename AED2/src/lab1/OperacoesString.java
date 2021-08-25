package lab1;

import java.util.Locale;
import java.util.Scanner;

public class OperacoesString {
    public void operations() {
        Scanner input = new Scanner(System.in);
        String word;
        int countVowels = 0;

        word = input.next();
        System.out.println(word.length());
        System.out.println(word.charAt(0));
        System.out.println(word.chars().max());
        System.out.println(word.toUpperCase());
        System.out.println(word.toLowerCase());
        System.out.println(word.replaceAll("a", "e"));
        for (int i = 0; i < word.length(); i += 2) {
            switch (word.charAt(i)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    countVowels++;
            }
            System.out.println(word.charAt(i));
        }
        System.out.println(countVowels);
    }
}
