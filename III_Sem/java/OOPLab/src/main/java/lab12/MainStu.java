package lab12;
import java.util.*;
class Stu{
    int id;
    String name;
    int mark;
    Stu(int id,String name,int mark){
        this.id = id;
        this.name = name;
        this.mark = mark;
    }

    void disp(){
        System.out.println("Stu ID is -> "+id);
        System.out.println("Stu NAME is -> "+name);
        System.out.println("Stu MARK is -> "+mark);
    }

    int getMarks(){
        return mark;
    }
}

public class MainStu {
    public static void main(String[] args) {
        ArrayList<Stu> ar = new ArrayList<Stu>();
        Stu s1 = new Stu(1,"tim",80);
        Stu s2 = new Stu(2,"jim",85);
        Stu s3 = new Stu(3,"bill",73);
        Stu s4 = new Stu(4,"bob",94);
        Stu s5 = new Stu(5,"mike",89);
        ar.add(s1);
        ar.add(s2);
        ar.add(s3);
        ar.add(s4);
        ar.add(s5);
        for (Stu student : ar) {
            if (student.getMarks() > 80) {
                student.disp();
            }
        }
    }
}
