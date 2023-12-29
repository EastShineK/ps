import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.TreeMap;

public class Contact {
	Map<String, String> NPlist = new HashMap<String, String>();
	
	void Show()
	{
		TreeMap<String, String> tm = new TreeMap<String, String>(NPlist);
		Iterator<String> iteratorKey = tm.keySet( ).iterator( );
		while(iteratorKey.hasNext()) {
			String key = iteratorKey.next();
            String value = NPlist.get(key);
            System.out.println(key + " "+ value);
        }
	}
	
	void Find(String name)
	{
		if(NPlist.containsKey(name))
			System.out.println(NPlist.get(name));
		else
			System.out.println("error");
	}
	
	void Add(String name, String Pnumber)
	{
		if(NPlist.containsKey(name))
			System.out.println("error");
		else
			NPlist.put(name, Pnumber);
	}
	
	void Delete(String name)
	{
		if(NPlist.containsKey(name))
			NPlist.remove(name);
		else
			System.out.println("error");
	}
	

}
