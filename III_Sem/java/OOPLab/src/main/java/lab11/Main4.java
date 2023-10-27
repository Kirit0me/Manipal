/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab11;

/**
 *
 * @author student
 */
 
// Main class
public class Main4 extends Thread {
    
    @Override
    public void run()
    {
        // Print statement
        System.out.println("Inside run method");
    }
 
    public static void main(String[] args)
    {
        ThreadDemo t1 = new ThreadDemo();
        ThreadDemo t2 = new ThreadDemo();
        ThreadDemo t3 = new ThreadDemo();
 
        t1.setPriority(2);
        t2.setPriority(5);
        t3.setPriority(8);
 
        System.out.println("t1 thread priority : "
                           + t1.getPriority());
 
        System.out.println("t2 thread priority : "
                           + t2.getPriority());

        System.out.println("t3 thread priority : "
                           + t3.getPriority());
 

        System.out.println(
            "Currently Executing Thread : "
            + Thread.currentThread().getName());
 
        System.out.println(
            "Main thread priority : "
            + Thread.currentThread().getPriority());
 
        Thread.currentThread().setPriority(10);
 
        System.out.println(
            "Main thread priority : "
            + Thread.currentThread().getPriority());
    }
}