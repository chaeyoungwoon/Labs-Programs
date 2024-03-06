#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {
   
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: " << endl;
   cin >> filename;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string filename){
   ifstream inFS;
   inFS.open(filename);

   int userIn;
   int totalSum = 0;

   if (!inFS.is_open()){ // checks if the file is open or not
      cout << "Error opening " << filename << endl;
      exit (EXIT_FAILURE);
   }
   while(inFS >> userIn){ //as long as the extraction from INFS is successful, keep running the loop
      totalSum += userIn;
   }

   return totalSum;
   

}