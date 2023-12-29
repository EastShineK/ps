import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;


public class Server {
	private static ArrayList<Thread> arr = new ArrayList<Thread> ();
	private static SimpleDateFormat sdfDate = new SimpleDateFormat ("yyy-MM-dd HH:mm:SSS");
	public static String getLog (String msg) {
		return "[" + sdfDate.format(new Date ()) + "] Server thread: " + msg;
	}
	public static void main (String[] args) {
		ServerSocket ss = null;
		int id = 0;
		OutputStream out;
		File file = new File("test.mp4");//
		FileInputStream fis;//
		try {
			ss = new ServerSocket (5000);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("server is ready");
	while (true) {
		try {
			Socket soc = ss.accept ();
			//System.out.println(Server.getLog ("new connection arrived"));
			//
			fis = new FileInputStream(file);
		    out = soc.getOutputStream();
		    byte[] tmp = new byte[1024];
		    int c = 0;
		    while((c = fis.read(tmp)) != -1) {
		      out.write(tmp, 0, c);
		    }
		    out.flush();
			//
			
			Thread t = new CommThread (soc, id ++);
			t.start ();
			arr.add(t);
			Iterator<Thread> iter = arr.iterator ();
			while (iter.hasNext ()) {
				t = iter.next ();
				if (!t.isAlive ()) {
					iter.remove ();
				}
			}
			fis.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		}
	}
}
