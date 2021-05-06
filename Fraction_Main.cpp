#include <iostream>
#include <string>

using namespace std;
class Fraction {
  public:
	void setFraction (int N, int D, int NU);			// Initializer for Fraction class
	Fraction sum (Fraction b);
	Fraction sum (double b);
	Fraction multiply(Fraction b);
	Fraction multiply(double b);
	void abbreviation();
	bool toMixedNum();
	void print();
	double toDouble();
	
	/* Define class funtions here*/
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
bool Fraction::toMixedNum(){
	bool changed = false;
	if (D==0)
		return changed;
	if (NU>=D){
		changed = true;
		N += NU/D;
		NU = NU%D;
	}
	if (NU==0)
		D=0;
	return changed;
}

Fraction str2Fraction (string str){
	Fraction frac;
	string N="";	string NU=""; string D="";
	int int_N,int_D,int_NU;
	int count = 0;
	int len = str.length();
	for (int i=0;i<len;i++){
		if (str[i] == '/')
			count++;
		else if(count == 0)
			N += str[i];
		else if(count == 1)
			NU += str[i];
		else
			D += str[i];
	}
	
	int_D=stoi(D);
	int_NU=stoi(NU);
	int_N=stoi(N);
	
	if (stoi(NU)==stoi(D) && stoi(N)!=0){
		int_D=0;	int_NU=0;
		int_N++;
	}
	frac.setFraction (int_N,int_D,int_NU);
	frac.abbreviation();
	frac.toMixedNum();
	return frac;
}

Fraction double2Fraction (double val){
	cout.setf(ios::fixed);
	cout.precision(10);
	Fraction frac;
	if (int(val)==val){
		frac.setFraction(val,0,0);
		return frac;
	}
	string s_val = to_string(val);
	int len = s_val.length();
	int point = s_val.find(".");
	int D=1;

	for (int i=point;i<=len;i++){
		val *= 10;
		D *= 10;
	}

	frac.setFraction(0,D,val);
	frac.toMixedNum();
	frac.abbreviation();
	return frac;
}

void Fraction::print(){
	cout << N << " and " << NU << "/" << D << endl;
}

Fraction Fraction::sum (Fraction b){
	Fraction frac;
	int NewD,NewNU,NewN;
	
	if (this->D==0 && b.D==0){
		frac.setFraction(this->N+b.N,0,0);
		return frac;
	}else if(this->D==0){
		frac.setFraction(this->N+b.N,b.D,b.NU);
		return frac;
	}else if(b.D==0){
		frac.setFraction(this->N+b.N,this->D,this->NU);
		return frac;
	}
	
	NewD = this->D * b.D;
	NewNU =this->D * b.NU + this->NU * b.D;
	NewN = this->N + b.N ;
	frac.setFraction(NewN,NewD,NewNU);
	frac.abbreviation();
	frac.toMixedNum();
	return frac;
}

Fraction Fraction::sum (double b){
	
	Fraction frac = double2Fraction(b);
	Fraction frac2;
	int NewD,NewNU,NewN;
	if (this->D==0 && frac.D==0){
		frac2.setFraction(this->N+frac.N,0,0);
		return frac2;
	}else if(this->D==0){
		frac2.setFraction(this->N+frac.N,frac.D,frac.NU);
		return frac2;
	}else if(frac.D==0){
		frac2.setFraction(this->N+frac.N,this->D,this->NU);
		return frac2;
	}
	NewD = this->D * frac.D;
	NewNU = this->D * frac.NU + this->NU * frac.D;
	NewN = this->N + frac.N;
	frac2.setFraction(NewN,NewD,NewNU);
	frac2.abbreviation();
	frac2.toMixedNum();
	return frac2;
}

Fraction Fraction::multiply (Fraction b){
	Fraction frac;
	int NewNU,NewD;
	int this_NU,b_NU;
	
	if(this->D==0 && b.D==0){
		frac.setFraction(this->N * b.N,0,0);
		return frac;
	}else if(this->D==0){
		frac.setFraction(this->N*b.N, b.D,this->N * b.NU);
		frac.toMixedNum();
		frac.abbreviation();
		return frac;
	}else if(b.D==0){
		frac.setFraction(this->N * b.N, this->D ,b.N * this->NU );
		frac.toMixedNum();
		frac.abbreviation();
		return frac;
	}
	
	if (this->N>0)
		this_NU = this->NU + this->D*this->N;
	if (b.N>0)
		b_NU = b.NU + b.D * b.N;

	NewD = this->D * b.D;
	NewNU = this_NU * b_NU;
	frac.setFraction(0,NewD,NewNU);
	frac.toMixedNum();
	frac.abbreviation();
	return frac;
}

Fraction Fraction::multiply (double b){
	Fraction frac = double2Fraction(b);
	Fraction frac2;
	double NewNU,NewD;
	int this_NU = this->NU;
	int b_NU = frac.NU;
	
		if(this->D==0 && frac.D==0){
		frac2.setFraction(this->N * frac.N,0,0);
		return frac2;
	}else if(this->D==0){
		frac2.setFraction(this->N*frac.N, frac.D,this->N * frac.NU);
		frac2.toMixedNum();
		frac2.abbreviation();
		return frac2;
	}else if(frac.D==0){
		frac2.setFraction(this->N * frac.N, this->D, frac.N * this->NU);
		frac2.toMixedNum();
		frac2.abbreviation();
		return frac2;
	}
	
	if (this->N>0)
		this_NU = this->NU + this->D*this->N;
	if (frac.N>0)
		b_NU = frac.NU + frac.D * frac.N;

	NewD = this->D * frac.D;
	NewNU = this_NU * b_NU;
	frac.setFraction(0,NewD,NewNU);
	frac.toMixedNum();
	frac.abbreviation();
	return frac;
}

void Fraction::abbreviation(){
	if (D==0)
		return;
	int a=NU;	int b=D;
	while (b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	NU = NU / a;
	D = D / a;
}

double Fraction::toDouble(){
	double frac;
	int ifrac;
	if (D==0){
		frac = N;
		return frac;
	}
	frac = N + double(NU)/D;
	ifrac = frac * 100000;
	if(ifrac%10 >= 5){
		ifrac = ifrac /10;
		ifrac++;
		frac = ifrac/10000.0;
	}else{
		frac = ifrac / 10;
		frac = frac/10000.0;
	}
	return frac;
}

/* Declare class functions here */
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