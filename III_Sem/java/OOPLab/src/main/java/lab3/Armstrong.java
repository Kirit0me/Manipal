/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab3;

/*
 *
 * @author student
 */

import java.util.*;
import java.lang.*;
public class Armstrong {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number to check Armstrong : ");
        int num = sc.nextInt();
        int astrong = num;
        int c = 0;
        while (num!=0){
            c += Math.pow(num%10, 3);
            num = num/10;
        }
        if(astrong == c){
            System.out.println(astrong + " is armstrong");
        }
        else {
            System.out.println(astrong + " is not armstrong");
        }
    }
}
