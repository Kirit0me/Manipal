import java.util.*;
class LargestOfThree
{
	public static void main(String args[])
	{
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int c = Integer.parseInt(args[2]);
		int d = a>b?(a>c?a:c):(b>c?b:c);
		System.out.println("The Largest Of Three is : \n" + d);	
	}
}