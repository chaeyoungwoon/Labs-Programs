#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int num); 
      Rational(int num, int denom); 
      Rational add(const Rational &number) const; 
      Rational subtract(const Rational &number) const; 
      Rational multiply(const Rational &number) const; 
      Rational divide(const Rational &number) const;
      void simplify();
      void display() const;
   private:
      int gcd(int x, int y) const;
};

// Implement Rational class member functions here

//Constructors
Rational::Rational(int num, int denom){
   numerator = num;
   denominator = denom;
}
Rational::Rational(int num){
   numerator = num;
   denominator = 1;
}
Rational::Rational(){
   numerator = 0;
   denominator = 1;
}

//Accessors
//(a/b) (c/d)

Rational Rational::add(const Rational &number) const{
   //(a/b) + (c/d) = (ad + bc) / (b*d)

   int addNumerator = (numerator * number.denominator) + (number.numerator * denominator);
   int addDenominator = denominator * number.denominator;

   Rational addFraction(addNumerator, addDenominator);
   return addFraction;
}

Rational Rational::subtract(const Rational &number) const{
   //(a/b) - (c/d) = (ad - bc) / (b*d)
   int subNumerator = ((numerator * number.denominator) - (number.numerator * denominator));
   int subDenominator = denominator * number.denominator;

   Rational subtractFraction(subNumerator, subDenominator);
   return subtractFraction;

}

Rational Rational::multiply(const Rational &number) const{
   //(a/b) * (c/d) = (ac) / (bd)
   int multNumerator = numerator * number.numerator;
   int multDenominator = denominator * number.denominator;

   Rational multFraction(multNumerator, multDenominator);
   return multFraction;
}

Rational Rational::divide(const Rational &number) const{
   //(a/b) / (c/d) = (ad) / (cb)
   int divNumerator = numerator * number.denominator;
   int divDenominator = number.numerator * denominator;

   Rational divFraction(divNumerator, divDenominator);
   return divFraction;
}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

int Rational::gcd(int x, int y) const{
   //while loop operates until y is zero, and the final GCD value is x
   //Euclidean algorithm states that the gcd of two numberes is the same as the gcd of x and x % y
   while (y != 0){
      int temp = y;
      y = x % y; //y is updated to the remainder
      x = temp; //x is udpated to previous y value
   }
   return x;
}

void Rational::simplify(){
   int common = gcd(numerator, denominator);
   numerator = numerator / common;
   denominator = denominator / common;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

