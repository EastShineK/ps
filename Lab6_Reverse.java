import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Reverse {

	public static void main(String[] args) {
		try {
			ArrayList<String> inputO = new ArrayList<String>();
			InputStream fis = new FileInputStream ("C:\\Users\\82102\\eclipse-workspace\\Reverse\\input.txt");
			InputStreamReader isr = new InputStreamReader (fis);
			BufferedReader br = new BufferedReader(isr);
			String data;
			int i = 0;
			
			do{
				data = br.readLine();
				//System.out.println(data);
				if(data != null) {
					inputO.add(i, data);
					i++;
				}
				else
					break;
				
			}while(data != null);
			
			br.close(); isr.close(); fis.close();
			
			FileOutputStream fos = new FileOutputStream("C:\\Users\\82102\\eclipse-workspace\\Reverse\\output.txt");
			OutputStreamWriter osw = new OutputStreamWriter(fos);
			BufferedWriter bw = new BufferedWriter (osw);
			
			for(int j = i - 1; j >= 0; j--) {
				//System.out.println(inputO.get(j));
				bw.write(inputO.get(j));
				bw.newLine();
			}
			bw.flush();
			bw.close(); osw.close(); fos.close();
		}catch (FileNotFoundException e) {
			System.out.println("NotfoundFile");
        }catch(IOException e){
            System.out.println(e);
        }


	
	}
}
