/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author student
 */

class Student{
    int reg_no;
    String name;
    int age;
    Student(){}
    Student(int a, String b, int c){
        reg_no = a;
        name = b;
        age = c;
    }
}

class UG extends Student{
    int sem;
    double fees;
    UG(int a, String b, int c, int d, double e){
        super(a, b, c);
        sem = d;
        fees = e;
    }
    void display(){
        System.out.println(reg_no + " " + name + " " + age + " " + sem + " " + fees);
    }
}

class PG extends Student{
    int sem;
    double fees;
    PG(int a, String b, int c, int d, double e){
        super(a, b, c);
        sem = d;
        fees = e;
    }
    void display(){
        System.out.println(sem + " " + name + " " + age + " " + sem + " " + fees);
    }
}

public class Main2 {
    public static void main(String[] args) {
        UG u1 = new UG(1, "Shreyas", 19, 3, 100000);
        PG p1 = new PG(2, "Meghdeep", 25, 1, 200000);
        u1.display();
        p1.display();
    }
}
