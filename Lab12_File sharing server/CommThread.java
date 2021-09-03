import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Iterator;

public class CommThread extends Thread {
	private Socket soc;
	private int id;
	
	public CommThread (Socket soc, int id) {
		this.soc = soc;
		this.id = id;
	}
	public void run () {
		try {
			OutputStream os = soc.getOutputStream ();
			DataOutputStream dos = new DataOutputStream (os);
			String ID;
			ID = Integer.toString(id);
		    dos.writeUTF (ID);
			//dos.writeUTF ("message from server (" + id + ")");
			//System.out.println (Server.getLog ("message is sent (" + id + ")"));
			dos.close ();
			this.soc.close ();
		} catch (IOException e) {
		// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public int getsId() {
		return this.id;
	}
}