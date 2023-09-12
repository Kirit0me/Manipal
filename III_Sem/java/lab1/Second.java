import java.util.*;

class Second
{
	public static void main(String args[])
	{
		int a, b, c;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the first number : ");
		a = in.nextInt();
		System.out.println("Enter the second number : ");
		b = in.nextInt();
		c = a+ b;
		System.out.println("The sum of " + a + " and " + b + " is :\n" + c);	
	}
}