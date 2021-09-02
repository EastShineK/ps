package NumberSystemConverter;
import java.util.Scanner;

public class NumberSystemConverter {
	
	public static void main(String[] args) {
		
		Scanner scn = new Scanner(System.in);
		int i = scn.nextInt();
		
		String bnum = Integer.toBinaryString(i);
		String onum = Integer.toOctalString(i);
		String hnum = Integer.toHexString(i);
		
		System.out.print("b ");
		System.out.println(bnum);
		
		System.out.print("o ");
		System.out.println(onum);
		
		System.out.print("h ");
		System.out.println(hnum);
	}

}
