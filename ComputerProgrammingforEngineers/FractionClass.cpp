#include <iostream>
#include <string>

using namespace std;
class Fraction {
  public:
	void setFraction (int N, int D, int NU);			// Initializer for Fraction class

	/* Define class funtions here*/
	Fraction sum (Fraction b);
	Fraction sum (double b);
	Fraction multiply (Fraction b);
	Fraction multiply (double b);
	void abbreviation();
	bool toMixedNum();
	void print();
	double toDouble();
	
  private:
  	int N;		// Integer of mixed number form
		int D;		// Denominator
		int NU;		// Numerator
};
void Fraction::setFraction (int N, int D, int NU) {
  this->N = N;
  this->D = D;
  this->NU = NU;
}
void Fraction::abbreviation()
{
	  int replaceD = 0;
    this->N = this->N + this->NU / this->D;
    if (this->D !=0 && this->NU % this->D == 0)
    {
        this->NU = this->NU % this->D;
        replaceD = this->D;
        this->D = 0;

        return;
    }
    else if (this->D == 0)
    {
        //cout << "ge" << endl;
        return;
    }
    else
    {
        this->NU = this->NU % this->D;
    }
    int rema, num1, num2;

    num1 = this->D;
    num2 = this->NU;

    while (num2 != 0)
    {
        rema = num1 % num2;
        num1 = num2;
        num2 = rema;
    }
    //cout << "n1 :" << num1 << endl;
    //cout << "n2 :" << num2 << endl;
    this->NU = this->NU / num1;
    this->D = this->D / num1;
    //cout << "this->NU :abbe " << this->NU << endl;
}

Fraction str2Fraction(string str)
{
    string p1, p2, p3;
    int n = str.length();
    int N = 0, NU = 0, D = 0;
    int coutn = 0;
    for (int i = 0; i < n; i++)
    {
        if (str.at(i) == '/' && coutn == 0)
        {
            p1 = str.substr(0, 1);
            N = stoi(p1);
            // cout << "N : "<< N << '\n';
            p2 = str.substr(i + 1, 1);
            NU = stoi(p2);
            // cout << "NU :" << NU << '\n';
            coutn++;
        }
        else if (str.at(i) == '/' && coutn == 1)
        {
            p3 = str.substr(i + 1, 1);
            D = stoi(p3);
            //cout <<"D:" << D << '\n';
            //coutn++;
        }
        // cout << i << endl;
    }
		if (NU == 0)
        D = 0;
    Fraction k1;
    k1.setFraction(N, D, NU);
    return k1;
}
Fraction double2Fraction(double val)
{
    Fraction k2;
    int N = 0, NU = 0, D = 0;
    string str, str2;
    //cout << "val :" << val << endl;
    str = to_string(val);
    //cout << "str : " << str << endl;
    int n = str.length();
    //cout << "n :" << n << endl;
    int dotcout = 0;
    int num1 = 1;
    double num;
    int c = 0;

    for (int m = 0; m < n; m++)
    {
        if (str.at(n - 1 - m) == '0')
        {
            str.at(n - 1 - m) = '\0';
            c = n - 1 - m;
            //cout << "c :" << c << endl;
        }
        else
        {
            break;
        }
    }

    num = stod(str);
    c = c - 1;
    //cout << "num" << num << endl;
    for (int j = 0; j < c; j++)
    {
        num = num * 10;
        num1 = num1 * 10;
    }
    int numx = num;

    N = numx / num1;
    NU = numx % num1;
    D = num1;

    k2.setFraction(N, D, NU);
    k2.abbreviation();
    return k2;
}
/* Declare class functions here */
void Fraction::print()
{
    cout << this->N << " and " << this->NU << '/' << this->D << endl;
}
Fraction Fraction::sum(Fraction b)
{
    //cout << "sumF start" << endl;
    Fraction sum;
    int Nuk = this->NU;
		if(this->NU == 0 && this->D==0 && b.NU == 0 && b.D == 0)
		{
			sum.N = this->N + b.N;
			sum.NU = 0;
			sum.D = 0;
			
			return sum;
		}
		else if(this->NU == 0 && b.NU != 0)
		{
			sum.N = this->N + b.N;
			sum.NU = b.NU;
			sum.D = b.D;
			
			return sum;
		}
		else if(this->NU != 0 && b.NU == 0)
		{
			sum.N = this->N + b.N;
			sum.NU = this->NU;
			sum.D = this->D;
			
			return sum;
		}

    this->NU = this->NU + this->N * this->D;
    b.NU = b.NU + b.N * b.D;

    int temp, rema, num1, num2, want;

    num1 = this->D;
    num2 = b.D;

    if (num1 < num2)
    {
        temp = num2;
        num2 = num1;
        num1 = temp;
    }

    while (num2 != 0)
    {
        rema = num1 % num2;
        num1 = num2;
        num2 = rema;
    }
    want = this->D * b.D / num1;

    int multhis = want / this->D;
    int mulb = want / b.D;

    this->NU = this->NU * multhis;
    //cout << "this->NU : " << this->NU << endl;
    b.NU = b.NU * mulb;
    // cout << "b.NU : " << b.NU << endl;
    sum.NU = this->NU + b.NU;
    sum.D = want;
    sum.N = 0;
    sum.abbreviation();
    this->NU = Nuk;
    //cout << "this->NU sumF : " << this->NU << endl;
    return sum;
}
Fraction Fraction::sum(double b)
{
    //cout << "sumD start" << endl;
    Fraction sum;
    int double2fractionNU;
    int Nuk = this->NU;

    this->NU = this->NU + this->N * this->D;
    double2fractionNU = double2Fraction(b).NU + double2Fraction(b).N * double2Fraction(b).D;
	
		if(this->NU == 0 && this->D==0 && double2Fraction(b).NU == 0 && double2Fraction(b).D == 0)
		{
			sum.N = this->N + double2Fraction(b).N;
			sum.NU = 0;
			sum.D = 0;
			
			return sum;
		}
		else if(this->NU == 0 && double2Fraction(b).NU != 0)
		{
			sum.N = this->N + double2Fraction(b).N;
			sum.NU = double2Fraction(b).NU;
			sum.D = double2Fraction(b).D;
			
			return sum;
		}
		else if(this->NU != 0 && double2Fraction(b).NU == 0)
		{
			sum.N = this->N + double2Fraction(b).N;
			sum.NU = this->NU;
			sum.D = this->D;
			
			return sum;
		}

    int temp, rema, num1, num2, want;

    num1 = this->D;
    num2 = double2Fraction(b).D;

    if (num1 < num2)
    {
        temp = num2;
        num2 = num1;
        num1 = temp;
    }

    while (num2 != 0)
    {
        rema = num1 % num2;
        num1 = num2;
        num2 = rema;
    }
    want = this->D * double2Fraction(b).D / num1;

    int multhis = want / this->D;
    int mulb = want / double2Fraction(b).D;
   // cout << "multhis : " << multhis << endl;
   // cout << "mulb : " << mulb << endl;
   // cout << "this->NU : " << this->NU << endl;
    this->NU = this->NU * multhis;
   // cout << "this->NU : " << this->NU << endl;
    double2fractionNU = double2fractionNU * mulb;
    sum.NU = this->NU + double2fractionNU;
    sum.D = want;
    sum.N = 0;
    sum.abbreviation();
    this->NU = Nuk;

    return sum;
}

Fraction Fraction::multiply(Fraction b)
{
    //cout << "multplyF start" << endl;
    Fraction sum;
	
		if(this->NU == 0 && this->D==0 && b.NU == 0 && b.D == 0)
		{
			sum.N = this->N * b.N;
			sum.NU = 0;
			sum.D = 0;		
			return sum;
		}
		else if(this->NU == 0 && b.NU != 0)
		{
			this->NU = 1;
			this->D = 1;
		}
		else if(this->NU != 0 && b.NU == 0)
		{
			b.NU = 1;
			b.D = 1;
		}
		else
		{
			
		}
    int Nuk = this->NU;
		this->NU = this->NU + this->N * this->D;
    b.NU = b.NU + b.N * b.D;
    
		sum.NU = this->NU * b.NU;
    sum.D = this->D * b.D;
    sum.N = 0;

    sum.abbreviation();

    this->NU = Nuk;
    return sum;
}
Fraction Fraction::multiply(double b)
{
    //cout << "multplyD start" << endl;
    Fraction sum;

    int double2fractionNU = double2Fraction(b).NU;
		int double2fractionD = double2Fraction(b).D;
    int Nuk = this->NU;
	
		if(this->NU == 0 && this->D==0 && double2Fraction(b).NU == 0 && double2Fraction(b).D == 0)
		{
			sum.N = this->N * double2Fraction(b).N;
			sum.NU = 0;
			sum.D = 0;
			
			return sum;
		}
		else if(this->NU == 0 && double2Fraction(b).NU != 0)
		{
			this->NU = 1;
			this->D = 1;
		}
		else if(this->NU != 0 && double2Fraction(b).NU == 0)
		{
			double2fractionNU = 1;
			double2fractionD = 1;
		}
		else
		{
			this->NU = this->NU + this->N * this->D;
    	double2fractionNU = double2Fraction(b).NU + double2Fraction(b).N * double2Fraction(b).D;
		}
	

    sum.NU = this->NU * double2fractionNU;

    sum.D = this->D * double2fractionD;
    sum.N = 0;

    sum.abbreviation();

    this->NU = Nuk;
    return sum;
}

bool Fraction::toMixedNum()
{
    if (this->NU >= this->D)
    {
			if(this->D != 0)
        this->N = this->N + this->NU / this->D;
        return true;
    }
    else
    {
        return false;
    }

}

double Fraction::toDouble()
{
    float NU1, D1, result;
    int Nuk = this->NU;
		int ten=1;
    this->NU = this->NU + this->N * this->D;
		if (this->D == 0)
        return this->N;
    NU1 = NU;
    D1 = D;
    this->NU = Nuk;
		result = NU1 / D1;
		for(int l = 0; l < 6; l++)
		{
			result = result * 10;
		}
		for(int v = 0; v < 2; v++)
		{
			if(int(result) % 10 >= 5)
			{
				int remain = int(result) % 10;
				result =result - remain;
				result = result + 10;
				result = result / 10;
				
			}
			else
			{
				result = result / 10;
			}
		}
		for(int h = 0; h < 4; h++)
		{
			result = result / 10;
		}
		
	
    return result;
}
/* You can make additional functions */
int main() {
  string in_frac1;
  double in_frac2;
  cin >> in_frac1 >> in_frac2;

  Fraction frac1 = str2Fraction (in_frac1);
  Fraction frac2 = double2Fraction (in_frac2);

  frac1.print ();
  frac2.print ();
 
  Fraction frac3 = frac1.sum (frac1);			// frac1 + frac1
  frac3.print ();

  Fraction frac4 = frac1.sum (in_frac2);		// frac1 + frac2
  frac4.print ();

  Fraction frac5 = frac2.multiply (frac1);		// frac2 * frac1
  frac5.print ();

  Fraction frac6 = frac2.multiply (in_frac2);	// frac2 * frac2
  frac6.print ();

  double res = frac1.toDouble();
  printf ("%.6f\n", res);

  res = frac2.toDouble();
  printf ("%.6f\n", res);
  
  frac1.toMixedNum ();
  frac2.toMixedNum ();

  frac1.print ();
  frac2.print ();

  return 0;
}