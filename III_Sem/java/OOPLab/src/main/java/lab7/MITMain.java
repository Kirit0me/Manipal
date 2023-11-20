/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab7;

/**
 *
 * @author student
 */
public class MITMain {
    static class Student_Detail{
        String name, college_name;
        int id;
        Student_Detail(String college_name, String name , int id ){
            this.college_name = college_name;
            this.name = name;
            this.id = id;
        }
        
        void display(){
        System.out.println("College : "+college_name);
        System.out.println("Name : "+name);
        System.out.println("ID : "+id);
        System.out.println(" ");
        }
    }
    
    public static void main(String args[]){
    Student_Detail s[] = new Student_Detail[10];
    s[0] = new Student_Detail("MIT","Harsh",1212);
    s[1] = new Student_Detail("MIT","Dev",1214);
    s[2] = new Student_Detail("MIT","Vihaan",1245);
    
    for(int i=0;i<3;i++){
        s[i].display();
    }
    
    }
    
}
