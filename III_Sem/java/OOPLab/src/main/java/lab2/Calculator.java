package lab2;
import java.util.*;
class Calculator{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		char choice = 'y';
		char operator;
    		Double n1, n2, result;
		while(choice == 'y'){
			System.out.println("Enter first number");
			n1 = sc.nextDouble();
			System.out.println("Choose an operator: +, -, *, or /");
    			operator = sc.next().charAt(0);
			System.out.println("Enter Second number");
			n2 = sc.nextDouble();
			switch (operator) {
      				case '+':
       					result = n1 + n2;
        				System.out.println(n1 + " + " + n2 + " = " + result);
        				break;
      				case '-':
        				result = n1 - n2;
        				System.out.println(n1 + " - " + n2 + " = " + result);
        				break;
				case '*':
        				result = n1 * n2;
        				System.out.println(n1 + " * " + n2 + " = " + result);
        				break;
      				case '/':
      					result = n1 / n2;
        				System.out.println(n1 + " / " + n2 + " = " + result);
        				break;

      				default:
        				System.out.println("Invalid operator!");
        				break;
    			}
			System.out.println("Do you want to continue? y to go ahead");
			choice = sc.next().charAt(0);

		}
	}
}