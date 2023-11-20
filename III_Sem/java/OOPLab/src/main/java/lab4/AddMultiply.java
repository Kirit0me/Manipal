/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab4;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class AddMultiply {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter dimensions of array1 : ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println("Enter dimensions of array2 : ");
        int p = sc.nextInt();
        int o = sc.nextInt();
        System.out.println("Press 1 for Multiply and 2 for add");
        int choice = sc.nextInt();
        if(choice == 1){
            if(p==n){

                int arr1[][] = new int[m][n];
                int arr2[][] = new int[n][o];
                System.out.println("Enter elements of array1 : ");
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        arr1[i][j] = sc.nextInt();
                    }
                }
                System.out.println("Enter elements of array2 : ");
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < o; j++){
                        arr2[i][j] = sc.nextInt();
                    }
                }
                int c[][] = new int[m][o];
                for(int i = 0; i< m;i++){
                    for(int j = 0; j < o; j++){
                        c[i][j] = 0;
                        for(int k = 0; k < n; k++){
                            c[i][j] = arr1[i][k]*arr2[k][j];
                        }
                    }
                }
                System.out.println("Matrix Mult: ");
                for(int[] row : c) {
                    for (int column : row) {
                        System.out.print(column + "\t");
                    }
                    System.out.println();
               }
            }
            else{
                System.out.println("Give valid dimensions");
            }
        }
        if(choice == 2){
            if(m == p && n == o){
                int arr1[][] = new int[m][n];
                int arr2[][] = new int[m][n];
                System.out.println("Enter elements of array1 : ");
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        arr1[i][j] = sc.nextInt();
                    }
                }
                System.out.println("Enter elements of array2 : ");
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        arr2[i][j] = sc.nextInt();
                    }
                }
                int sumarr[][] = new int[m][n];
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        sumarr[i][j] = arr1[i][j] + arr2[i][j];
                    }
                }
                System.out.println("Matrix Add: ");
                for(int[] row : sumarr) {
                    for (int column : row) {
                        System.out.print(column + "\t");
                    }
                    System.out.println();
               }
            }
            else{
                System.out.println("Give valid dimensions");
            }
        }
    }
}
