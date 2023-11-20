package lab1;
import java.util.*;
import java.lang.Math;
class Salary
{
	public static void main(String args[])
	{
		double basic, gross, net;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the basic : ");
		basic = in.nextDouble();
		gross = 1.28*basic;
		net = 0.9*gross;
		System.out.println("Net Salary will be : \n" + net);	
	}
}