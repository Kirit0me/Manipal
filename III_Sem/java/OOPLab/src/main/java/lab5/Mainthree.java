/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */
class Time{
    int hrs, mins, secs;
    Time(){
        hrs = 0; mins = 0; secs = 0;
    }
    Time(int h, int m, int s){
        hrs = h; mins = m; secs = s;
    }
    void disp(){
        System.out.println(hrs+":"+mins+":"+secs);
    }
    void add(Time t){
        this.secs += t.secs;
        if(this.secs > 59){
            this.secs = this.secs%60;
            this.mins += 1;
        }
        this.mins+=t.mins;
        if(this.mins > 59){
            this.mins = this.mins%60;
            this.hrs += 1;
        }
        this.hrs+=t.hrs;
    }
}
public class Mainthree {
    public static void main(String[] args) {
        Time t1 = new Time();
        Time t2 = new Time(20, 40, 20);
        Time t3 = new Time(13, 49, 54);
        t1.disp();
        t2.disp();
        t3.disp();
        t2.add(t3);
        t2.disp();
    }
}
