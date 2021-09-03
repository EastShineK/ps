import java.util.Scanner;
import java.io.*;

public class SimpleCalculator {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		Calculate c = new Calculate();
		char op;
		String snum1, snum2;
		int checkNum = 0;
		int num1, num2;
		try {
			for(int i = 0; i < str.length(); i++) {
				if(str.charAt(i) == '+') {
					op = '+';
					checkNum = i;
					break;
				}
				else if(str.charAt(i) == '-') {
					op = '-';
					checkNum = i;
					break;
				}
			}
			op = str.charAt(checkNum);
			snum1 = str.substring(0, checkNum);
			snum2 = str.substring(checkNum + 1, str.length());
			num1 = Integer.parseInt(snum1);
			num2 = Integer.parseInt(snum2);
			
			System.out.println(c.resulting(num1, num2, op));
			
			
		} catch(AddZeroException e){
			System.out.println("AddZeroException");
		} catch(SubtractZeroException e){
			System.out.println("SubtractZeroException");
		} catch(OutOfRangeException e){
			System.out.println("OutOfRangeException");
		}
	}
}

class Calculate{
	public int resulting(int num1, int num2, char op) throws AddZeroException, SubtractZeroException, OutOfRangeException{
		int result = 0;
		
		if(num1 == 0 || num2 ==0) {
			if(op == '+') {
				throw new AddZeroException();
			}
			else if(op == '-') {
				throw new SubtractZeroException();
			}
		}
		if(num1 < 0 || num1 > 1000 || num2 < 0 || num2 > 1000 ) {
			throw new OutOfRangeException();
		}
		
		if(op == '+') {
			result = num1 + num2;
			if(result > 1000 || result < 0) {
				throw new OutOfRangeException();
			}
		}
		else if(op == '-') {
			result = num1 - num2;
			if(result > 1000 || result < 0) {
				throw new OutOfRangeException();
			}
		}
		
		return result;
	}
}

class AddZeroException extends Exception{
	public AddZeroException() {};
}
class SubtractZeroException extends Exception{
	public SubtractZeroException() {};
}
class OutOfRangeException extends Exception{
	public OutOfRangeException() {};
}