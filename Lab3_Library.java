
public class Library {

	public Book[] Books = new Book[10];
	
	Library()
	{
		for(int i = 0; i < 10; i++)
		{
			this.Books[i] = new Book(0);
		}
	}
	 
	void borrowBook(int n)
	{
		if(Books[n].state == 0)
		{
			Books[n].state = 1;
			System.out.println(n+"th book Borrow Complete!");
		}
		else
		{
			System.out.println("This book already borrowed");
		}
	}
	
	void returnBook(int n)
	{
		if(Books[n].state == 1)
		{
			Books[n].state = 0;
			System.out.println(n+"th book Return Complete!");
		}
		else
		{
			System.out.println("This book is not returnable.");
		}
	}
}
