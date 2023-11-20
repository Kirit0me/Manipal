/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */
import java.lang.*;
class Number{
    private double num;
    Number () {}
    Number(double num){
        this.num =  num;
    }
    boolean isZero(){
        if(num == 0){
            return true;
        }
        else return false;
    }
    boolean isPositive(){
        if(num > 0){
            return true;
        }
        else return false;
    }
    boolean isNegative(){
        if(num < 0){
            return true;
        }
        else return false;
    }
    boolean isOdd(){
        if(num%2 != 0){
            return true;
        }
        else return false;
    }
    boolean isEven(){
        if(num%2 == 0){
            
            return true;
        }
        else return false;
    }
    boolean isPrime(){
        for(int i = 2; i < num; i++){
            if(num%i==0) return false;
        }
        return true;
    }
    boolean isArmstrong(){
        int astrong = (int)num;
        num = (int)num;
        int c = 0;
        while (num!=0){
            c += Math.pow(num%10, 3);
            num = num/10;
        }
        if(astrong == c){
            return true;
        } else {
            return false;
        }
    }
}
public class Mainfive {
    public static void main(String[] args) {
        Number n153 = new Number(153);
        Number n2 = new Number(153.2);
        Number n3 = new Number(13);
        //if(n3.isOdd) System.out.println("Idk why I am here");
    }
    
}
