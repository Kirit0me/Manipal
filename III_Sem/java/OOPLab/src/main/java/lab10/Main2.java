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
public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a[] = new int[10];
        try {
            int c=1; int i = 0;
            while(c==1) {
                System.out.println("Enter element: ");
                a[i] = sc.nextInt();
                i++;
                System.out.println("To stop, press 0: ");
                c = sc.nextInt();
            }
            System.out.println("Array Successfully Input");
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array OverFlow");
        }
    }
}
