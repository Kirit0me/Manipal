/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab12;

/**
 *
 * @author student
 */
import java.util.ArrayList;
import java.util.List;

class GenericStack<T> {
    private final List<T> stack = new ArrayList<>();

    public void push(T item) {
        stack.add(item);
    }

    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return stack.remove(stack.size() - 1);
    }

    public boolean isEmpty() {
        return stack.isEmpty();
    }
}

class Student {
    private final String name;

    Student(String name) {
        this.name = name;
    }

    String getName() {
        return name;
    }
}

class Employee {
    private final String name;

    Employee(String name) {
        this.name = name;
    }

    String getName() {
        return name;
    }
}

public class Main2 {
    public static void main(String[] args) {
        GenericStack<Student> studentStack = new GenericStack<>();

        studentStack.push(new Student("Alice"));
        studentStack.push(new Student("Bob"));
        studentStack.push(new Student("Charlie"));

        while (!studentStack.isEmpty()) {
            Student student = studentStack.pop();
            System.out.println("Student: " + student.getName());
        }

        GenericStack<Employee> employeeStack = new GenericStack<>();

        employeeStack.push(new Employee("David"));
        employeeStack.push(new Employee("Eve"));
        employeeStack.push(new Employee("Frank"));

        while (!employeeStack.isEmpty()) {
            Employee employee = employeeStack.pop();
            System.out.println("Employee: " + employee.getName());
        }
    }
}
