#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;


void readData(const string &filename, vector<double> &angles, vector<double> &coefficients);
double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients);
bool isOrdered(const vector<double> &angles);
void reorder(vector<double> &angles, vector<double> &coefficients);

int main(int argc, char* argv[]){

    vector<double> flightPathAngles;
    vector<double> liftCoefficients;

    string filename = argv[1]; //get the file name from command line arg

    readData(filename, flightPathAngles, liftCoefficients);

    if (!isOrdered(flightPathAngles)){ //check if the flight angles are ordered, and if not, reorder
        reorder(flightPathAngles, liftCoefficients);
    }

    string request; //for user input loop
    do {
        //get the angle
        double requestedAngle; 
        cin >> requestedAngle;

        //interpolate the coefficient for the desired angle
        double interpolatedC = interpolation(requestedAngle, flightPathAngles, liftCoefficients);
        cout << interpolatedC << endl;

        //get user request to proceed or quit the loop
        cin >> request;

    } while (request == "Yes" || request == "yes");

    return 0;
}

void readData(const string &filename, vector<double> &angles, vector<double> &coefficients){ 
    ifstream inFS;
    inFS.open(filename);

    if (!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }   

    double userAngle;
    double userCoefficient;

    //reading information from the file
    while (inFS >> userAngle){
        if (inFS >> userCoefficient){
            angles.push_back(userAngle);
            coefficients.push_back(userCoefficient);
        }
        else {
            break;
        }
    }
    inFS.close();
}

double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients){
    // this is the index that is next in angles, from vector angle. this is also greater than the requested angle
    unsigned int i = 1; 
	
    //find the interval for the following interpolation
	while (angle > angles[i]) {
		++i;
	}
	
    //step 1 = (b - a) / (c - a)
	//step 2 = f(c) - f(a)
	//equation -> f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
	
	double step1 = (angle - angles[i - 1]) / (angles[i] - angles[i - 1]);
	double step2 = coefficients[i] - coefficients[i - 1];
	
	return coefficients[i - 1] + step1 * step2;
}

bool isOrdered(const vector<double> &angles){
    if (angles.size() == 0){
        return true;
    }

    double finalAngle = angles[0];

    //checks for ascending order
    for (unsigned int i = 1; i < angles.size(); ++i){
        if (angles[i] < finalAngle){ 
            return false;
        }
        finalAngle = angles[i];
    }
    return true;

}

void reorder(vector<double> &angles, vector<double> &coefficients) {
    for (unsigned int i = 0; i < angles.size(); ++i) {

        //index of smallest angle is the current index (for now)
        unsigned smallest = i;

        //find the index of the smallest angle in remaining unsorted angles
        for (unsigned j = i; j < angles.size(); ++j) {
            if (angles[j] < angles[smallest]) {
                smallest = j;
            }
        }
        
        //swap angles and coefficients
        double tempA = angles[smallest];
        double tempC = coefficients[smallest];
        
        //shift elements to maintain proper order (reverse order from i)
        for (unsigned k = smallest; k > i; --k) {
            angles[k] = angles[k - 1];
            coefficients[k] = coefficients[k - 1];
        }
        
        //set smallest angle/coefficient to the accurate positions
        angles[i] = tempA;
        coefficients[i] = tempC;
    }
}
