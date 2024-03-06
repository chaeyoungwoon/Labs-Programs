#include <iostream>

using namespace std;

#include "IntVector.h"

int main() {
    //default
    IntVector v1;
    cout << v1.size() << "   " << v1.capacity() << endl;

    //two parameters
    IntVector v2(2, 500);
    cout << v2.size() << "   " << v2.capacity() << endl;

    //two parameters of default
    IntVector v3(0,0);
    cout << v3.size() << "   " << v3.capacity() << endl;

    // more than 10 on both
    IntVector v4(1000, 1000);
    cout << v4.size() << "   " << v4.capacity() << endl;

    //one parameter
    IntVector v5(11);
    cout << v5.size() << "   " << v5.capacity() << endl;

    //checking if they are empty or not (v1 should, v2 and v5 should not)
    if (v1.empty()) {
        cout << "v1 is empty" << endl;
    }
    if (v2.empty()) {
        cout << "v2 is empty" << endl;
    } 
    else {
        cout << "v2 is not empty" << endl;
    }
    if (v5.empty()) {
        cout << "v5 is empty" << endl;
    } 
    else {
        cout << "v5 is not empty" << endl;
    }

    //testing .at()
    cout << v2.at(1) << endl;
    cout << v2.at(5) << endl;
    cout << v3.at(0) << endl;
    
    //displaying elements of v5
    for(unsigned int i = 0; i < v5.size(); ++i) {
        cout << v5.at(i) << " ";
    }
    cout << endl;

    //testing .front() and .back()
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    cout << v5.front() << endl;
    cout << v5.back() << endl;

    cout << v1.front() << " " << v2.back() << endl;

    cout << v3.front() << endl;
    cout << v3.back() << endl;
            
    return 0;
}