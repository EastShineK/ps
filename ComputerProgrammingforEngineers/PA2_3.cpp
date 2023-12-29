#include <iostream>
#include <string>

using namespace std;
class shape {
protected:
	string sha;
	double a1;
	double b1;
public:
	void showArea() {
		cout << "Area of ";
	}
	string getS() { return sha; }
	double getA() { return a1; }
	double getB() { return b1; }
};

class Rectangle : public shape {
public:
	Rectangle() {};
	Rectangle(string s, double a, double b) {
		sha = s;
		a1 = a;
		b1 = b;
	}
	void showArea() {
		shape::showArea();
		cout << sha << " : " << a1 * b1;
	}
};

class Square : public Rectangle {
public:
	Square(string s, double a) {
		sha = s;
		a1 = a;
		b1 = a;
	}
	void showArea() {
		shape::showArea();
		cout << sha << " : " << a1 * a1;
	}
};

class Triangle : public shape {
public:
	Triangle(string s, double a, double b) {
		sha = s;
		a1 = a;
		b1 = b;
	}
	void showArea() {
		shape::showArea();
		cout << sha << " : " << 0.5 * a1 * b1;
	}
};

class Circle : public shape {
public:
	Circle(string s, double a) {
		sha = s;
		a1 = a;
		b1 = 0;
	}
	void showArea() {
		shape::showArea();
		cout << sha << " : " << 3.141592 * a1 * a1;
	}
};
int main() {

	double a, b;
	string s;
	cin >> s;

	if (s == "rectangle")
	{	
		cin >> a >> b;
		Rectangle rect(s, a, b);
		rect.showArea();
	}
	else if (s == "square")
	{	
		cin >> a ;
		Square sqr(s, a);
		sqr.showArea();
	}
	else if (s == "triangle")
	{	
		cin >> a >> b;
		Triangle triangle(s, a, b);
		triangle.showArea();

	}
	else if (s == "circle")
	{
		cin >> a;
		Circle circle(s, a);
		circle.showArea();
	}
	else
		cout<<"input doesnt matches with required shape"<<endl;
	return 0;
}