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
class Mythr extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread " + Thread.currentThread().getName() + ": " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Thread " + Thread.currentThread().getName() + " was interrupted");
                return; // Terminate the thread if interrupted
            }
        }
    }
}

public class Main4 {
    public static void main(String[] args) {
        Mythr thread1 = new Mythr();
        Mythr thread2 = new Mythr();

        // Set priorities
        thread1.setPriority(Thread.MIN_PRIORITY); // Set minimum priority
        thread2.setPriority(Thread.MAX_PRIORITY); // Set maximum priority

        thread1.start();
        thread2.start();

        try {
            // Main thread waits for both threads to finish
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread was interrupted");
        }
    }
}
