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
public class MagicSquareCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in array : ");
        int M = sc.nextInt();
        int mat[][] = new int[M][M];
        System.out.println("Enter elements of array : ");
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                mat[i][j] = sc.nextInt();
            }
        }
        boolean flag = false;
      
        int sum1 = 0,sum2=0;

        for (int i = 0; i < M; i++){
            sum1 += mat[i][i];
            sum2 += mat[i][M-1-i];
        }

        if(sum1!=sum2) flag = true; 
        for (int i = 0; i < M; i++) {

            int rowSum = 0, colSum = 0;

            for (int j = 0; j < M; j++){
                 rowSum += mat[i][j];
                 colSum += mat[j][i];
            }

            if (rowSum != colSum || colSum != sum1) flag = true; 
        }
        if (!flag)
            System.out.println("Given matrix is a Magic Square");
        else
            System.out.println("Given matrix is a not a magic" + " Square");
       }
}
