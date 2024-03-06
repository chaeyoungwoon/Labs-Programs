#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date() {
   day = 1;
   month = 1;
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){   
   bool large = false;
   if (m > 12){
      month = 12;
      year = y;
      day = d;
      large = true;
   } 
   else{
      month = m;
   }

   if (d > daysPerMonth(month,y)){

      day = daysPerMonth(m,y);
      if (month==2 && isLeap(y)){
         day = 29;
      }
      if (d < 1){
         day = 1;
      } 
      if (m < 1){
         month = 1;
         day = daysPerMonth(1,y);
      }
      
      if (d > daysPerMonth(m,y)) 
      year = y;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   } 
   else if (d < 1|| m < 1){
      if (d < 1){
         day = 1;
      } 
      if (m < 1){
         month = 1;
      }
      year = y;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year<< "." << endl;
   } 
   else{
      day = d;
      if (large){
      cout << "Invalid date values: Date corrected to " << month << "/"<< day << "/" << year << "." << endl;
      }
   }
   year = y; 
   
}


Date::Date(const string &mn, unsigned d, unsigned y){
   monthName = mn;
   bool validMonth = (number(monthName) != 0);
   if (!validMonth){
      monthName = "January";
      day = 1;
      year = 2000;
      month = 1;
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   } 
   else{
      monthName = mn;
      month = number(monthName);

      if (d > daysPerMonth(month, y)){
         day = daysPerMonth(month, y);
         if (monthName == "February" && isLeap(y)){
            day = 29;
         }
         if (d == 0){
            d = 1;
         }
         if (d < 1){
            day = 1;
         }
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;
      } 
      else if (d < 1){ 
         day = 1;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << y << "." << endl;
      } 
      else{
         day = d;
      }
      year = y;
   }
}

void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const{
   const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   cout << months[month-1 ]<< " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const{
   return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   const int daysInMonth[]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (m == 2 && isLeap(y)) {
      return 29;
   } else {
      return daysInMonth[m];
   }
}

string Date::name(unsigned m) const{
   const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   return months[m - 1];
}

unsigned Date::number(const string &mn) const{
   const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   const string monthsLower[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
   for (unsigned int i = 0; i < 12; i++) {
      if (mn == months[i] || mn == monthsLower[i]) {
         return i + 1;
      }
    }
   return 0;
}
// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}