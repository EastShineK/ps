import java.util.Scanner;

public class mainO {
	
	public static void main(String[] args) {
		
		//System.out.println("Start");
		Contact listK = new Contact();
		
		while(true)
		{
			Scanner scan = new Scanner(System.in);
			String str = scan.nextLine();
			String[] input = str.split("\\s");
			String comd = input[0];
			
			if(comd.equals("find"))
			{
				String name = input[1];
				listK.Find(name);
			}
			else if(comd.equals("add"))
			{
				String name = input[1];
				String pnumber = input[2];
				listK.Add(name, pnumber);
			}
			else if(comd.equals("show"))
			{
				listK.Show();
			}
			else if(comd.equals("delete"))
			{
				String name = input[1];
				listK.Delete(name);

			}
		}
		
	}
}
