/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab9;
import java.util.*;
/**
 *
 * @author student
 */
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch=0, c=0, w=1, l=0, v=0;
        String str = sc.nextLine();
        str = str.toLowerCase();
        ch = str.length();
        char[] cstr = str.toCharArray();
        for(int i = 0; i<str.length(); i++){
            if(cstr[i] == 'a' || cstr[i] == 'e' || cstr[i] == 'i' || cstr[i] == 'o' || cstr[i] == 'u'){
                v++;
            } else {
                c++;
            }
            if(cstr[i] == ' '){
                ch--; c--; w++;
            }
            if(cstr[i] == '.'){
                l++;ch--;c--;
            }
        }
        System.out.println("Stats: chars : " + ch + " vowels : " + v + " consonants : " + c + " words : " + w);
    }
}
