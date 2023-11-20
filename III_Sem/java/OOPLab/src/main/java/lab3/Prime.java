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
public class Prime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n and m : ");
        int n = sc.nextInt();
        int m = sc.nextInt();
        for(int i = n; i < m; i++){
            boolean prime = true;
            for(int j = 2; j < i; j++){
                if(i%j == 0){
                    prime = false;
                }
            }
            if(prime){
                System.out.println(i + "\t");
            }
            
        }
    }
}
