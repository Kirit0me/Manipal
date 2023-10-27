/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab9;
import java.util.*;
/**
 *
 * @author student
 */
public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter word : ");
        String s = sc.next();
        System.out.println("Enter choice 1-4 : ");
        int c = sc.nextInt();
        switch(c){
            case 1:
                checkPallindrome(s);
                break;
            case 2:
                sortstr(s);
                break;
            case 3:
                System.out.println(reversestr(s));
                break;
            case 4:
                concatOgToRev(s);
                break;
            default:
                System.out.println("Enter valid number next time");
        }
    }
    
    static String reversestr(String str){
        String reverseStr = "";

        int strLength = str.length();

        for (int i = (strLength - 1); i >=0; --i) {
            reverseStr = reverseStr + str.charAt(i);
        }
        return reverseStr;
    }
            
    static void checkPallindrome(String str){
        String reverseStr = reversestr(str);   

        if (str.toLowerCase().equals(reverseStr.toLowerCase())) {
            System.out.println(str + " is a Palindrome String.");
        }
        else {
            System.out.println(str + " is not a Palindrome String.");
        }
    }
    
    static void concatOgToRev(String str){
        String rev = reversestr(str);
        System.out.println(str+rev);
    }
    
    static void sortstr(String str){
        char charArray[] = str.toCharArray();
        Arrays.sort(charArray);
        System.out.println(new String(charArray));
    }
}
