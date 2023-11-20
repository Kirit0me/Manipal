/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author student
 */

class Bank{
    int roi;
    int get_roi(){return 0;}
}

class SBI extends Bank {
    int get_roi(){return 8;}
}

class ICICI extends Bank {
    int get_roi(){return 7;}
}

class AXIS extends Bank {
    int get_roi(){return 9;}
}

public class Main3 {
    public static void main(String[] args) {
        SBI b1 = new SBI();
        ICICI b2 = new ICICI();
        AXIS b3 = new AXIS();
        Bank bank = b1;
        int c = bank.get_roi();
        System.out.println("ROI for SBI : " + c + "%");
        bank = b2;
        c = bank.get_roi();
        System.out.println("ROI for ICICI : " + c + "%");
        bank = b3;
        c = bank.get_roi();
        System.out.println("ROI for AXIS : " + c + "%");
    }
 
}
