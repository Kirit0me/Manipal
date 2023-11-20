/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab9;

import java.util.Scanner;

/**
 *
 * @author student
 */

public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String instr = sc.next();
        char[] rchars = repeating(instr);

        System.out.println("Repeating Characters: ");
        for (char c : rchars) {
            if (c != '\0') {
                System.out.print(c);
            }
        }
    }

    public static char[] repeating(String str) {
        int[] charCount = new int[26];

        str = str.toLowerCase();

        for (char c : str.toCharArray()) {
            if (Character.isLetter(c)) {
                int index = c - 'a';
                charCount[index]++;
            }
        }

        char[] repeatingChars = new char[26];
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (charCount[i] > 1) {
                repeatingChars[count++] = (char) (i + 'a');
            }
        }

        return repeatingChars;
    }
}
