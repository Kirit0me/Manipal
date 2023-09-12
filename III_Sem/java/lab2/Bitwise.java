import java.util.*;
class Bitwise{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter numer to multiply or divide by 2");		
		int n = sc.nextInt();
		System.out.println("Enter 1 for multiply, Enter 2 for divide");	
		int c = sc.nextInt();	
		if(c == 1){
			n = n<<1;
		}
		else if(c == 2){
			n = n>>1;
		}
		else {
			System.out.println("Enter valid input");	
		}	
		System.out.println("Number is " + n);	
	}
}