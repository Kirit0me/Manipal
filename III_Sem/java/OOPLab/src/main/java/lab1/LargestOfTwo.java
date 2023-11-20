package lab1;
import java.util.*;
import java.lang.Math;
class LargestOfTwo
{
	public static void main(String args[])
	{
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int c = a>b?a:b;
		System.out.println("The Largest Of Two is : \n" + c);	
	}
}