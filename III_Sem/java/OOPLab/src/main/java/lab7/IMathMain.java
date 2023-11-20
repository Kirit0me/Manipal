/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab7;

/**
 *
 * @author student
 */
public class IMathMain{
    static int min(int x, int y){
        if(x>y) return y;
        else return x;
    }
    
    static int max(int x, int y){
        if(x>y) return x;
        else return y;
    }
    
    static int pow(int x, int y){
        int a=1;
        for(int i=0;i<y;i++){
            a*=x;
        }
        return a;
    }
    
    static int Dec2Bin(int a){
     int ans = 0,count =0;
     while(a>0){
         int rem = a%2;
         a = a/2;
         ans += rem*pow(10,count);
         count++;
     }
     return ans;
    }
    
    static int Bin2Dec(int a){
     int ans=0,count=0;
     while(a>0){
      int rem = a%10;
      a = a/10;
      ans += rem*pow(2,count);
      count++;
     }
     return ans;
    }
    
    static String Dec2Hex(int a){
        String hex="";
        char hexchars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        while(a>0){
        int rem = a%16;
        hex = hexchars[rem] + hex;
        a = a/16;
        }
        return hex;
    }
    
    public static void main(String args[]){
    System.out.println("Min of 2,3 : " + min(2,3));
    System.out.println("Max of 2,3 : " + max(2,3));
    System.out.println("2 to the power 3 : " + pow(2,3));
    System.out.println("Converting 57 to binary : " + Dec2Bin(57));
    System.out.println("Converting 101101 to decimal : " + Bin2Dec(101101));
    System.out.println("Converting 4154 to hexadecimal : " + Dec2Hex(4154));
    }
}
