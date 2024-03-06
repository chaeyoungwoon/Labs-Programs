#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    //base case
    if (arrSize == 0){
        return nullptr;
    }
    
    //if arrray only has 1 element, that is also the smallest
    if (arrSize == 1){
        return arr;
    }

    //basically iterates recursively 
    //shifts right one, reduces size accordingly
    const int *smallest = min(arr + 1, arrSize - 1);

    if (*smallest < arr[0]){
        return smallest;
    }
    else {
        return arr;
    }
}