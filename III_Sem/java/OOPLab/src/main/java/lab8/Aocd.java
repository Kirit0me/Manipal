/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;
/**
 *
 * @author student
 */
import java.util.*;
abstract class Shape
{
    int a,b;
    abstract public void printarea();
}
class Rectangle extends Shape{
    public int area_rect;
    public void printarea()
    {
        Scanner s=new Scanner(System.in);
        System.out.println("enter the length and breadth of rectangle :");
        a=s.nextInt();
        b=s.nextInt();
        area_rect=a*b;	
        System.out.println("The area of rectangle is : "+area_rect);
    }
}


class Circle extends Shape{
    double area_circle;
    public void printarea()
    {
        Scanner s=new Scanner(System.in);
        System.out.println("enter the radius of circle :");
        a=s.nextInt();
        area_circle=(3.14*a*a);
        System.out.println("The area of circle is : "+area_circle);
    }
}

public class Aocd {
    public static void main(String[] args) {
        Shape s;
        s = new Rectangle();
        s.printarea();  
        s = new Circle();
        s.printarea();
    }
}
