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
public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name : ");
        String name = sc.next();
        System.out.println("Roll no.");
        String roll = sc.next();
        System.out.println("Enter Marks(max 50) : ");
        String marks = sc.next();
        try {
            int roll_ = Integer.parseInt(roll);
            int marks_ = Integer.parseInt(marks);
            int perc = marks_*2;
            System.out.println("Name : " + name);
            System.out.println("Roll no. : " + roll);
            System.out.println("Percentage : " + perc);
            if(perc>90) System.out.println("Grade A");
            else if(perc>80 && perc <= 90) System.out.println("Grade B");
            else if(perc>70 && perc<=80) System.out.println("Grade C");
            else if(perc>60 && perc<=70) System.out.println("Grade D");
            else System.out.println("Fail");
        }
        catch(NumberFormatException e){
            System.out.println("Enter valid number");
        }
    }
}
