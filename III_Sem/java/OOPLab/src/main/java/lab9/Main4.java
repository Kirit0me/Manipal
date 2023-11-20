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
public class Main4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter choice 1-4");
        int c = sc.nextInt();
        switch(c) {
            case 1:
                System.out.println("Enter two strings : ");
                String str1 = sc.next();
                String str2 = sc.next();
                if(str1.compareTo(str2) > 0){
                    System.out.println("First String is greater");
                } else if(str1.compareTo(str2) == 0) {
                    System.out.println("Strings are Equal");
                } else {
                    System.out.println("Second String is greater");
                }
                break;
            case 2:
                System.out.println("Enter string : ");
                String str = sc.next();
                System.out.println("Upper case : " + str.toUpperCase());
                System.out.println("Lower Case : " + str.toLowerCase());
                break;
            case 3:
                System.out.println("Enter main string : ");
                String mainstr = sc.next();
                System.out.println("Enter substring : ");
                String substr = sc.next();
                if(mainstr.contains(substr)){
                    System.out.println("Substring in main string");
                } else {
                    System.out.println("Substring not in main string");
                }
                break;
            case 4:
                System.out.println("Enter main string : ");
                String main = sc.next();
                System.out.println("Enter substring : ");
                String sub = sc.next();
                if(main.contains(sub)){
                    String replaced = main.replaceAll(sub, "Hello");
                    System.out.println(replaced);
                }
                break;
            default:
                System.out.println("Enter Valid number");
        }
    }
}
