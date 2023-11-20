/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab11;
import java.util.*;
/**
 *
 * @author student
 */
class Matrix extends Thread {
    int a[][] = new int[3][3];
    Scanner sc = new Scanner(System.in);
    Matrix(int n){
        System.out.println("Enter elements : ");
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++) {
                a[i][j] = sc.nextInt();
            }
        }
    }
    
    public void run(int c){
        switch(c){
            case 1:
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++) {
                        System.out.print(a[i][j] + "\t");
                    }
                    System.out.println("");
                }
            case 2:
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++) {
                        System.out.print(a[j][i] + "\t");
                    }
                    System.out.println("");
                }       
        }
    }
    
}

public class Main2 {
    
}
