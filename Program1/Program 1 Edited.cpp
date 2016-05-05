#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int numerator1, denominator1, numerator2, denominator2;

	cout << "Fraction 1" << endl;
	cout << "Enter the numerator:  ";
	cin >> numerator1;
	cout << "Enter the denominator: ";
	cin >> denominator1;

	cout << "Fraction 2" << endl;
	cout << "Enter the numerator:  ";
	cin >> numerator2;
	cout << "Enter the denominator: ";
	cin >> denominator2;

	cout << "RESULTS " << endl;

	

	int productNum = numerator1 * numerator2;
	int productDenom = denominator1 * denominator2;
	cout << numerator1 << "/" << denominator1 << " multiplied by ";
	cout << numerator2 << "/" << denominator2 << "=" << productNum << "/" << productDenom << endl;

	int QuotientNum = numerator1 * denominator2;
	int QuotientDenom = denominator1 * numerator2;
	cout << numerator1 << "/" << denominator1 << " divided by ";
	cout << numerator2 << "/" << denominator2 << "=" << QuotientNum << "/" << QuotientDenom << endl;

	int sumNum = (numerator1 * denominator2) + (numerator2 * denominator1) ;
	int sumDenom = denominator1 * denominator2;
	cout << numerator1 << "/" << denominator1 << " added by ";
	cout << numerator2 << "/" << denominator2 << "=" << sumNum << "/" << sumDenom;



	return 0;
}

