    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;

/**
 *
 * @author student
 */
import java.util.Scanner;

class Book {
    String title;
    String author;
    int edition;

    public Book(String title, String author, int edition) {
        this.title = title;
        this.author = author;
        this.edition = edition;
    }
}

public class Mainsix {
    public static void main(String[] args) {
        Book[] books = new Book[6];
        books[0] = new Book("Book1", "Author1", 1);
        books[1] = new Book("Book2", "Author2", 2);
        books[2] = new Book("Book3", "Author1", 2);
        books[3] = new Book("Book4", "Author3", 1);
        books[4] = new Book("Book5", "Author2", 1);
        books[5] = new Book("Book6", "Author4", 3);

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter author's name: ");
        String targetAuthor = sc.nextLine();

        boolean foundBooksByAuthor = false;

        System.out.println("Books written by " + targetAuthor + ":");
        for (int i = 0; i < books.length; i++) {
            if (books[i].author.equals(targetAuthor)) {
                System.out.println("Title: " + books[i].title + ", Edition: " + books[i].edition);
                foundBooksByAuthor = true;
            }
        }

        if (!foundBooksByAuthor) {
            System.out.println("No books found by " + targetAuthor);
        }
    }
}
