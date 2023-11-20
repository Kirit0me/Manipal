/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */

class Box {
    double height, width, breadth, volume;
    void init(double h, double w, double b){
        height = h; width = w; breadth = b;
    }
    void volumecalc(){
        volume = height*width*breadth;
        System.out.println("Volume is " + volume);
    }
}
public class Mainone {
    public static void main(String[] args) {
        Box b1 = new Box();
        b1.init(50, 40, 60);
        b1.volumecalc();
    }
}
