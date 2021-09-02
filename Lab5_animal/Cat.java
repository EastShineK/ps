
public final class Cat extends Mammal {

	private String slave;
	
	public Cat() {}
	public Cat(String Cname, float Cweight, String slave){
		setName(Cname);
		setWeight(Cweight);
		setNameOfSlave(slave);
	}
	
	public void bark()
	{
		System.out.println("Meow");
	}
	
	public String getFood()
	{		
		return "Fish";
	}
	
	public String getNameOfSlave() {
		return slave;
	}
	void setNameOfSlave(String s)
	{
		slave = s;
	}
}
