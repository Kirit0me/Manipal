/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab10;
import java.util.*;
/**
 *
 * @author student
 */
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number : ");
        try{
            String num = sc.next();
            int n = Integer.parseInt(num);
            System.out.println(n+1);
        } catch(NumberFormatException e) {
            System.out.println("Invalid String to Number");
        }
    }
}
