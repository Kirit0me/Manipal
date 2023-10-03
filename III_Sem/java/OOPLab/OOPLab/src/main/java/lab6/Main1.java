/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author student
 */

class Account{
    String customer_name;
    int acc_no;
    double balance;
    String type_of_account;
    
    Account(){}
    Account(String a, int b)
    {
        customer_name = a;
        acc_no = b;
        balance = 0;
    }
    
    void deposit(int a)
    {
        balance += a;
        System.out.println("Amount deposited");
    }
    void withdraw(int a)
    {
        balance -=a;
        if(balance < 0){
            System.out.println("Insufficient balance");
            balance +=a;
        }
        else{
            System.out.println("Amount withdrawn");
        }
       
    }
    void disp()
    {
        System.out.println("Customer Name : " + customer_name + " Account type : " + type_of_account + " Balance : " + balance);
    }
}

class Current extends Account{
    Current(){}
    Current(String a, int b, int c)
    {
        super(a, b);
        type_of_account = "Current Account";
    }
    void check_bal()
    {
        if(balance < 1000){
            System.out.println("Minimum amount not exceded, Subtracting service tax...");
            balance = balance *0.95;
        }
    }
}

class Savings extends Account{
    Savings(){}
    Savings(String a, int b, int c)
    {
        super(a, b);
        type_of_account = "Savings Account";
    }
    void interest()
    {
        balance*= 1.1;
    }
    
}

public class Main1 {
    public static void main(String[] args) {
        
    }
}
