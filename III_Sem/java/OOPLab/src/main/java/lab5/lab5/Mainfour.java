/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */
class Complex{
    int real, img;
    Complex(){ real = 0; img = 0;}
    Complex(int a, int b){
        real = a;
        img = b;
    }
    void disp(){
        System.out.println(real + " + " + img +"i");
    }

}
public class Mainfour {
    static void add(int a, Complex c){
        Complex ct = new Complex();
        ct.real = c.real + a;
        ct.img = c.img;
        ct.disp();
    }
    static void add(Complex c1, Complex c2){
        Complex ct = new Complex();
        ct.real = c1.real + c2.real;
        ct.img = c1.img + c2.img;
        ct.disp();
    }
    
    public static void main(String[] args) {
        Complex c1 = new Complex(3, 4);
        Complex c2 = new Complex(4, 2);
        add(3, c1);
        add(c1, c2);
    }
}
