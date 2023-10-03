/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */
class Employee{
    String empName, city;
    double basic, da, hra, total;
    void getdata(String a, String b, double c, double d, double e){
        empName = a;
        city = b;
        basic = c;
        da = d;
        hra = e;
    }
    void calculate(){
        total = basic + basic*da/100 + basic*hra/100;
    }
    void display(){
        System.out.println("The total salary of " + empName + " is " + total);
    }
}
public class Maintwo {
    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.getdata("Shreyas", "Bengaluru", 100000.0, 20.0, 50.0);
        e1.calculate();
        e1.display();
    }
}
