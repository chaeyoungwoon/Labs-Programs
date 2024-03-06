#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char c);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char c){
   ifstream inFS;
   inFS.open(filename);

   int charCount = 0;

   if (!inFS.is_open()){
      cout << "Error opening " << filename << endl;
      exit (EXIT_FAILURE);
   }

   char currChar;

   while (inFS.get(currChar)){ //reads a character from inFS and stores it into currChar. use this instead of >> which skips whitespace 
      if (currChar == c){
         charCount++;
      }
   }

   inFS.close();
   return charCount;

}