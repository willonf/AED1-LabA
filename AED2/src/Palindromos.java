import java.util.Scanner;

public class Palindromos {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String word, parsedWord;
        word = input.nextLine();
        int index = 0;
        int isPalind = 1;
        parsedWord = word.toUpperCase().replaceAll(" ", "");
        for (int i = parsedWord.length() - 1; i >= 0; i--) {
            if (parsedWord.charAt(i) != parsedWord.charAt(index)) {
                isPalind = 0;
                break;
            }
            index++;
        }
        System.out.println(parsedWord + " " + isPalind);
    }
}
