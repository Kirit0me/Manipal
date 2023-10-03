/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab4;

/**
 *
 * @author student
 */
import java.util.*;
public class NonDiagonal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in array : ");
        int n = sc.nextInt();
        int arr[][] = new int[n][n];
        System.out.println("Enter elements of array : ");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        boolean flag = true;
        int sum_nd = 0;
        int sum_pd = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    sum_pd += arr[i][j];
                }
                if(arr[i][j] != arr[j][i]){
                    flag = false;
                }
                if(i==j || i==n-j-1){
                    continue;
                } else {
                    sum_nd += arr[i][j];
                }
                
            }
        }
        System.out.println("The Sum of non diagonals is " + sum_nd);
        System.out.println("The Sum of Principal diagonal is " + sum_pd);
        if(flag){
            System.out.println("Matrix is symmetric");
        }
        else {
            System.out.println("Matrix is not symmetric");
        }
    }
}
