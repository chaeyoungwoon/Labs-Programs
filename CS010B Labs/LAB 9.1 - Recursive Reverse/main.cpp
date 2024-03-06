/*
You may not use a loop of any kind.
You may not use global or static variables.
You may not use the word r*****e anywhere within your main.cpp file (including comments).
*/

#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s){
   string temp = "";
   //base case
   if (s.size() <= 1) {
      return;
   }
   else {
      //adds the last character to the flipped temp, then adds the first character at the end
      temp = s.substr(1, s.size() - 2);

      flipString(temp);
      
      //adds the last character to the flipped temp, then adds the first character at the end
      s = s.at(s.size() - 1) + temp + s.at(0); 
   }
   return;
}

