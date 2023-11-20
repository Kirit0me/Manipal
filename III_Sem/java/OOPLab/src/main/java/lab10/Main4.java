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
class MyEx extends Exception{}

public class Main4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number : ");
        int n = sc.nextInt();
        try {
            if(n<0) {
                throw new MyEx();
            }
            System.out.println("Nice, and Good Positive Integers!");
        } catch(MyEx e) {
            System.out.println("Enter Positive Integers!");
        }
    }
}
