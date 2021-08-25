package lab1;

import java.util.Scanner;

public class CifraCesar {
    public void operation() {
        Scanner input = new Scanner(System.in);
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        String message, newMessage = "";
        int index, newIndex, key;

        key = input.nextInt();
        message = input.nextLine();
        for (int i = 0; i < message.length(); i++) {
            char letter = message.charAt(i);
            index = alphabet.indexOf(letter);
            if (index == -1) {
                newMessage = newMessage.concat(String.valueOf(letter));
            } else {
                newIndex = index + key;
                newIndex = newIndex % alphabet.length();
                newMessage = newMessage.concat(alphabet.substring(newIndex, newIndex + 1));
            }
        }
        System.out.println(newMessage.toUpperCase().replaceFirst(" ", ""));


    }
}
