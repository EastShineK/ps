#include <iostream>
#include <string>

using namespace std;

#define STOCK_NUM 4
string stock_list[STOCK_NUM] = {"Apple", "Google", "Samsung", "Amazon"};

class BankAccount {
private:
	string name;
	int age;
	int balance; //initial balance is 1
public:
	BankAccount(string n, int a);
  void printAccInfo();
	void deposit(int amount);
	bool withdraw(int amount);
	//int getB() { return balance; }
};

class StockAccount : public BankAccount {
private:
	int stock_nums[STOCK_NUM];

public:
	StockAccount(string n, int a);
	void buyStock(string stock_name, int num, int price);
	void sellStock(string stock_name, int num, int price);
	void printAccInfo();
};
BankAccount::BankAccount(string n, int a)
{
	name = n;
	age = a;
	balance = 1;
}

void BankAccount::deposit(int amount)
{
	balance = balance + amount;
	cout << "Success. Balance: " << balance << endl;
}

bool BankAccount::withdraw(int amount)
{
	if (balance < amount)
	{
		cout << "Withdraw Failed!" << endl;
		return false;
	}

	balance = balance - amount;
	cout << "Success. Balance: " << balance << endl;
	return true;
}

void BankAccount::printAccInfo()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Balance: " << balance << endl;
}

StockAccount::StockAccount(string n, int a)
	:BankAccount(n, a)
{
	for (int i = 0; i < 4; i++)
		stock_nums[i] = 0;
}

void StockAccount::buyStock(string stock_name, int num, int price)
{
	int j;
	//int b = getB();
	//withdraw(num * price);


	if (stock_name != stock_list[0] && stock_name != stock_list[1] && stock_name != stock_list[2] && stock_name != stock_list[3])
	{
		cout << "Cannot find " << stock_name << " stock" << endl;
		return;
	}

	if (!withdraw(num * price))
	{
		cout << "Buy Failed" << endl;
		return;
	}

	for (j = 0; j < 4; j++)
	{
		if (stock_name == stock_list[j])
			break;
	}
	stock_nums[j] = stock_nums[j] + num;

	//cout << "Success. Balance: " << getB() << endl;
	cout << "Success! Buy " << stock_name << " stock" << endl;
}

void StockAccount::sellStock(string stock_name, int num, int price)
{
	int j;
	for (j = 0; j < 4; j++)
	{
		if (stock_name == stock_list[j])
			break;
	}


	if (stock_name != stock_list[0] && stock_name != stock_list[1] && stock_name != stock_list[2] && stock_name != stock_list[3])
	{
		cout << "Cannot find " << stock_name << " stock" << endl;
		return;
	}

	if (stock_nums[j] <= 0)//stock이 없다면
	{
		cout << "Sell Failed" << endl;
		return;
	}

	stock_nums[j] = stock_nums[j] - num;

	deposit(num*price);
	//cout << "Success. Balance: " << getB() << endl;
	cout << "Success! Sell " << stock_name << " stock" << endl;
}

void StockAccount::printAccInfo()
{
	BankAccount::printAccInfo();
	cout << "Apple : "<< stock_nums[0] <<endl;
	cout << "Google : "<< stock_nums[1] <<endl;
	cout << "Samsung : "<< stock_nums[2] <<endl;
	cout << "Amazon : "<< stock_nums[3] <<endl;
}

int main()
{
	StockAccount my_acc("HongGilDong", 24);
	int menu;

	do {
		cout << "=============Menu=============" << endl;
		cout << "1. Print Account Information" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Enter StockMode" << endl;
		cout << "5. END" << endl;
		cout << "==============================" << endl;

		cout << "Menu: ";
		cin >> menu;
		cout << "==============================" << endl;

		if (menu == 5)
			break;
		else if (menu > 5)
		{
			cout << "Wrong number!" << endl;
			continue;
		}
		else if (menu == 1)
		{
			BankAccount acc = my_acc;
			acc.printAccInfo(); //bank print
		}
		else if (menu == 2 || menu == 3)
		{
			int amount;
			cout << "Amount: ";
			cin >> amount;
			if (menu == 2)
				my_acc.deposit(amount);
			else
				my_acc.withdraw(amount);
		}
		else if (menu == 4)
		{
			int s_menu;
			cout << "=============Stock Menu=============" << endl;
			cout << "1. Print Stock Account Information" << endl;
			cout << "2. Buy" << endl;
			cout << "3. Sell" << endl;
			cout << "4. Back" << endl;
			cout << "====================================" << endl;

			cout << "Menu: ";
			cin >> s_menu;
			cout << "====================================" << endl;

			if (s_menu == 4)
				continue;
			else if (s_menu > 4)
			{
				cout << "Wrong Number" << endl;
				continue;
			}
			if (s_menu == 1)
				my_acc.printAccInfo();	// stock print
			else if (s_menu == 2 || s_menu == 3)
			{
				string s_name;
				int s_num, s_price;
				cout << "Stock Name: ";
				cin >> s_name;
				cout << "Stock Num: ";
				cin >> s_num;
				cout << "Stock Price: ";
				cin >> s_price;

				if (s_menu == 2)
					my_acc.buyStock(s_name, s_num, s_price);
				else
					my_acc.sellStock(s_name, s_num, s_price);
			}
		}
	} while (true);

	return 0;

}