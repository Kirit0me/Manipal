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
class NotSquareMatException extends Exception{}
public class Main5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter matrix Dimensions : ");
        int i = sc.nextInt();
        int j = sc.nextInt();
        try {
            if(i!=j) throw new NotSquareMatException();
            else {
                int pd = 0;
                System.out.println("Enter matrix for pd : ");
                int a[][] = new int[i][j];
                for(int m = 0;m<i;m++){
                    for(int n = 0;n<i; n++){
                        a[m][n] = sc.nextInt();
                    }
                }
                for(int k = 0; k<i; k++){
                    pd+=a[k][k];
                }
            }
        } catch(NotSquareMatException e) {
            System.out.println("Enter valid matrix dimensions");
        }
    }
}
