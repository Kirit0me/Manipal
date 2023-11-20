/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab11;

/**
 *
 * @author student
 */
class SharedResource {
    synchronized void printNumbers() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class SharedResource1 {
    void printNumbers() {
        synchronized(this) {
            for (int i = 1; i <= 5; i++) {
                System.out.println(i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class Thread1 extends Thread {
    SharedResource sharedResource;

    public Thread1(SharedResource sharedResource) {
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() {
        sharedResource.printNumbers();
    }
}

class Thread2 extends Thread {
    SharedResource sharedResource;

    public Thread2(SharedResource sharedResource) {
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() {
        sharedResource.printNumbers();
    }
}
public class Main5 {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource();

        Thread1 t1 = new Thread1(sharedResource);
        Thread2 t2 = new Thread2(sharedResource);

        t1.start();
        t2.start();
    }
}
