
public final class Dog extends Mammal {
	private String Master;
	
	Dog(String Dname, float Dweight, String Master){
		setName(Dname);
		setWeight(Dweight);
		setNameOfMaster(Master);
	}
	
	public void bark()
	{
		System.out.println("Bowbow");
	}
	
	public String getFood()
	{		
		return "Apple";
	}
	
	public String getNameOfMaster() {
		return Master;
	}
	void setNameOfMaster(String m)
	{
		Master = m;
	}
}
