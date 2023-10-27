/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10;
import java.util.*;
import java.lang.*;
/**
 *
 * @author student
 */
class NegativeNumberException extends Exception{}

public class Main6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number : ");
        int n = sc.nextInt();
        try {
            if(n<0) {
                throw new NegativeNumberException();
            }
            double d = Math.sqrt(n);
            System.out.println("Square root : " + d);
        } catch(NegativeNumberException e) {
            System.out.println("Can't square root negative numbers!");
        }
    }
}
