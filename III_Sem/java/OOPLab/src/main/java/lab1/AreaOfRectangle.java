package lab1;
import java.util.*;
class AreaOfRectangle
{
	public static void main(String args[])
	{
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
//		int a, b, c;
//		Scanner in = new Scanner(System.in);
//		System.out.println("Enter the breadth of rectangle : ");
//		a = in.nextInt();
//		System.out.println("Enter the height of rectangle : ");
//		b = in.nextInt();
		int c = a*b;
		System.out.println("The area of rectangle is : \n" + c);	
	}
}