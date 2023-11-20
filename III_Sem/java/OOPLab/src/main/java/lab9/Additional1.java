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
public class Additional1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 4;
        String strs[] = new String[10];
        int c = 1, k = 0;
        while(c==1){
            System.out.println("Enter string : ");
            strs[k] = sc.next();
            k++;
            System.out.println("To continue, press 1");
            c = sc.nextInt();
        }
        String temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (strs[i].compareTo(strs[j]) > 0) {
                    temp = strs[i];
                    strs[i] = strs[j];
                    strs[j] = temp;
                }
            }
        }
        System.out.println("The strings in alphabetical order are: ");
        for (int i = 0; i < n; i++) {
            System.out.println(strs[i]);
        }
    }
}
