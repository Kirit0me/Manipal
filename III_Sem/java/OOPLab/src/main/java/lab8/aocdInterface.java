/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;
import java.lang.*;
/**
 *
 * @author student
 */
interface Area{        
    double calc(double x,double y);    
}    
    
class Rect implements Area    
{    
    public double calc(double x,double y)    
    {    
        return(x*y);    
    }    
}    
    
class Cir implements Area    
{    
    public double calc(double x, double y)    
    {    
        return(Math.PI*x*x);    
    }    
}

public class aocdInterface 
{
    public static void main(String[] args) {
        Area a;
        a = new Rect();
        System.out.println("Area of Rectangle length 20 and breadth 10 is "+a.calc(10,20));
        a = new Cir();
        System.out.println("Area of Circle radius 10 is "+a.calc(10,20));
    }
}
