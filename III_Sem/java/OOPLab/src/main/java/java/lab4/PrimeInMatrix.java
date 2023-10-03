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
public class PrimeInMatrix {
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
        System.out.println("Prime Numbers : ");
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                boolean prime = true;
                for(int k = 2; k < arr[i][j]; k++){

                    if(arr[i][j]%k == 0){
                        prime = false;
                    }
                }
                if(prime && arr[i][j] != 1){
                    count++;
                    System.out.print(arr[i][j] + " ");
                }
            }
        }

        System.out.println("");
        System.out.println("Number of prime numbers are : " + count);
    }
}
