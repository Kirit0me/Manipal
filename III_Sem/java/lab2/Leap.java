import java.util.*;
class Leap {
	public static void main(String args[]) {
		boolean leap = false;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter year : ");
		int year = sc.nextInt();
		if(year%4 == 0){
			if(year%100 == 0){
				if(year%400 == 0){
					leap = true;
				}
				else { 
					leap = false;
				}
			}
			else {
				leap = true;
			}
		}
		else{
			leap = false;
		}
		if(leap) {
			System.out.println(year + " is a leap year");
		}
		else {
			System.out.println(year + " is not a leap year");
		}
	}
}

			