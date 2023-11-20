
package lab1;
import java.util.*;
import java.lang.Math;
class CircleStatistics
{
	public static void main(String args[])
	{
		double r, c, a;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the radius of circle : ");
		r = in.nextDouble();
		c = 2*Math.PI*r;
		System.out.println("The circumference of circle is : \n" + c);
		a = Math.PI*r*r;
		System.out.println("The area of circle is : \n" + a);	
	}
}