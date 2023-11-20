/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab12;

/**
 *
 * @author student
 */
import java.util.*;
public class Main1 {

    public static <T> void swapElements(T[] array, int index1, int index2) {
        if (index1 < 0 || index1 >= array.length || index2 < 0 || index2 >= array.length) {
            System.out.println("Invalid indices for swapping.");
            return;
        }

        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static void main(String[] args) {

        Integer[] intArray = {1, 2, 3, 4, 5};
        System.out.println("Original Array: " + Arrays.toString(intArray));

        swapElements(intArray, 1, 3);
        System.out.println("Array after swapping: " + Arrays.toString(intArray));

        String[] strArray = {"apple", "banana", "cherry", "date"};
        System.out.println("Original Array: " + Arrays.toString(strArray));

        swapElements(strArray, 0, 2);
        System.out.println("Array after swapping: " + Arrays.toString(strArray));
    }
}
