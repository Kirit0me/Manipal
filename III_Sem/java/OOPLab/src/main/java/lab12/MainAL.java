/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab12;

/*
 *
 * @author student
 */
import java.util.ArrayList;

public class MainAL {
    public static void main(String[] args) {
        // Create an ArrayList and initialize it with the given elements
        ArrayList<Integer> list = new ArrayList<>();
        list.add(5);
        list.add(10);
        list.add(20);
        list.add(3);
        list.add(17);
        list.add(25);

        // Display all elements in the ArrayList
        System.out.println("Original ArrayList: " + list);

        // Add the element 50 to the list
        list.add(50);

        // Insert an element 19 at the 3rd position (index 2)
        list.add(2, 19);

        // Delete an element at the 2nd position (index 1)
        list.remove(1);

        // Display the final ArrayList
        System.out.println("Final ArrayList: " + list);
    }
}

