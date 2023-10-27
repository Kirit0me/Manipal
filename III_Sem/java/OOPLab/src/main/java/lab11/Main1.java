/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab11;

/**
 *
 * @author student
 */
import java.util.*;
class MyThread extends Thread{
    @Override
    public void run(){
        for(int i=0;i<10;i++){
            System.out.println("Thread is running" + i);
        }
    }
}

class MyThread2 implements Runnable{
    @Override
    public void run() {
        for(int i=0;i<10;i++){
            System.out.println("Thread is running" + i);
        }
    }
}

public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Choice: \n 1. Interface\n2. Extends");
        int c = sc.nextInt();
        MyThread t1 = new MyThread();
        MyThread2 t = new MyThread2();
        Thread t2 = new Thread(t);
        switch(c){
            case 1:
                t2.start();
            case 2:
                t1.start();
        }
    }
}
