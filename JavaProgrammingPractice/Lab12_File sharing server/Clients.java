import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;


class Test extends Thread {
	/*public int getsId() {
		this.getId()
		return this.id;
	}*/
	private String fpath;
	public Test(){}
	public Test(int id){
		fpath = new String("test-" + Integer.toString(id)+".mp4");
	}
	
	public void run () {
		File file = new File(fpath);
		byte[] tmp = new byte[1024];
		try {
			Socket soc = new Socket("localhost", 5000);
			DataInputStream dis = new DataInputStream (soc.getInputStream());
			//OutputStream fout = new FileOutputStream("test.mp4");
			//DataInputStream.read(byte[] b, int off, int len)
			FileOutputStream fos = new FileOutputStream(file);
			
		    int length = 0;
		    while ((length = dis.read(tmp)) != -1) {
				  fos.write(tmp, 0, length);
				  if(length < 1024) break;
			}

		    
			//System.out.println(dis.readUTF());
			dis.close();
			soc.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
public class Clients {
	public static void main (String[] args) {
		int num = 0;
		for (int i = 0; i < 100; i ++) {
			new Test (num).start (); 
			num++;
		}
	}
}