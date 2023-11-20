/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Lab7;

// 1. Create a class imath with the following static members, static int min(int x, int y), static int max(int x, int y), 
// static int pow(int x, int y), static string deimalToBinary() static binaryToDecimal() static string decimalToHexedecimal
//2. ?
//3. Q1 in oop lab so, Write a java program to store student record of college name MIT
/**
 *
 * @author student
 */
import java.lang.*;
class IMath{
    static int min(int x, int y)
    {
        return x<y?x:y;
    }
    
    static int max(int x, int y)
    {
        return x>y?x:y;
    }
    static int pow(int x, int y)
    {
        int r = 1;
        for(int i = 0;i<y;i++){
            r = r*x;
        }
        return r;
    }
    static String decimalToBinary(int x)
    {
        String s = "";
        while(x!=0){
            int n = x%2;
            s += n;
            x = x/2;
        }
        String bin = "";
        for(int i = (s.length()-1); i>=0; i--){
            char c = s.charAt(i);
            bin+=c;
        }
        return bin;
    }
    static int binaryToDecimal(String x)
    {
        int len = x.length();
        int bin = Integer.parseInt(x);
        int dec = 0;
        for(int i = 0;i<len;i++){
            int n = bin%10;
            bin = bin/10;
            dec += n*Math.pow(2, i);
        }
        return dec;
    }
//    static String decimalToHexadecimal(int x)
//    {
//        
//    }
}

public class Main1 {
    public static void main(String[] args) {
        IMath i = new IMath();
        String s = i.decimalToBinary(672);
        int d = i.binaryToDecimal("1011010011");
        System.out.println(s);
        System.out.println(d);
    }
}
