#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) { 
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];

   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];

   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()){
      cout << "Error opening: " << inputFile << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   vector<int> userValues;
   int nums;
   int average = 0;
   char c; // dummy char

   while (inFS >> nums){ 
      userValues.push_back(nums);
      inFS >> c; //program needs to deal with commas, so use a char
   }

   // Close input stream.
   inFS.close();

   // Get integer average of all values read in.
   for (unsigned int i = 0; i < userValues.size(); ++i){ 
      average += userValues[i];
   }
   average /= userValues.size();

   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < userValues.size(); ++i){
      userValues[i] -= average;
   }

   // Create output stream and open/create output csv file.
   ofstream outFS(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()){
      cout << "Error opening: " << outputFile << endl;
      return 1;
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < userValues.size(); ++i){
      if (i != userValues.size() - 1){ //if current element is not the last one, append a comma 
         outFS << userValues[i] << ",";
      }
      else if (i == userValues.size() - 1){ //if current element is last, just print without comma
         outFS << userValues[i];
      }
   }

   // Close output stream.
   outFS.close();

   return 0;
}