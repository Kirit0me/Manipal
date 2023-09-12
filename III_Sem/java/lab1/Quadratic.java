import java.util.*;
import java.lang.Math;
class Quadratic
{
	public static void main(String args[])
	{
		double a, b, c, disc, roots;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a : ");
		a = in.nextDouble();
		System.out.println("Enter b : ");
		b = in.nextDouble();
		System.out.println("Enter c : ");
		c = in.nextDouble();
		disc = b*b - 4*a*c;
		if(disc < 0){
			System.out.println("Roots are imaginary");
			double realroot = -b/(2*a);
			double imgsqrt = Math.sqrt(-disc);
			System.out.println("Roots are :  \n" + realroot + " +i" + imgsqrt + "	" + realroot + " -i" + imgsqrt); 
		} else if(disc == 0) {
			double rootequal = -b/(2*a);
			System.out.println("Roots are real and equal\n The roots are : \n" + rootequal + "	" + rootequal);
		} else {
			System.out.println("Roots are real");
			double sqroot = Math.sqrt(disc);
			double root1 = (sqroot -b)/(2*a);
			double root2 = (-sqroot -b)/(2*a);
			System.out.println("Roots are \n" + root1 + "	" + root2);
		}
	}
}