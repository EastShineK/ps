
public class StringMethod {
	
// Returns a string created by adding 's2' after position 'index' of 's1'.
	static String addString(String s1, int index, String s2) {
		String s3 = s1.substring(index+1);
		String s4 = s1.substring(0, index+1);
		
		s4 = s4.concat(s2);
		s4 = s4.concat(s3);
		return s4;
	}
	
// Returns a reversed string of 's'
	static String reverse(String s) {
		
		int len = s.length();
		String s1 = "";
		
		for(int i = len; i > 0; i--)
		{
			String s3 = s.substring(i-1,i);
			s1 = s1.concat(s3);
			
		}
		//String s2 = s1.substring(1);
		
		return s1;
	}
	
// Returns a string removed all 's2' tokens from 's1'
	static String removeString (String s1, String s2) {
		
		String s4="";
		
		String[] s5 = s1.split(s2);
		int lenk = s5.length;
		
		for(int i = 0; i < lenk; i++)
		{
			s4 = s4.concat(s5[i]);
		}
		//String s6 = s4.substring(1);
		
		return s4;
	}
	
	public static void main(String[] args) {
		
		String s1 = "0123456";
		String s2 = "-";
		String s = "abc";
		String s6 = "01001000";
		String s7 = "00";
		//String s8 = "abkidabkjabjelabkwelab";
		//String s9 = "ab";
		
		System.out.println(addString(s1, 3, s2));
		System.out.println(reverse(s));
		System.out.println(removeString(s6,s7));
		//System.out.println(removeString(s8,s9));
	}
}
