#include <iostream>
#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;

    if (capacity == 0){
        _data = nullptr;
    }
    else {
        _data = new int[capacity];
        for (unsigned int i = 0; i < capacity; ++i){
            _data[i] = value;
        }
    }
}

IntVector::~IntVector(){    
    delete[] _data;
    _data = nullptr;
}


unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    return _size == 0;
}

const int & IntVector::at(unsigned index) const{
    if(index < _size) {
        return _data[index];
    } else {
        throw out_of_range("IntVector::at_range_check");
    }
}

//new function
int & IntVector::at(unsigned index ){
    if (index < _size){
        return _data[index];
    }
    else {
        throw out_of_range("IntVector::at_range_check");
    }
}

//new function
void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    
    //make more room
    if (_size == _capacity){
        expand();
    }
    _size += 1;
    int *dataTemp = new int [_capacity];
    //purpose is to loop through the original array and copy to dataTemp
    for (unsigned int i = 0; i < _size; ++i){
        //current index = insertion index   
        if (i == index){
            dataTemp[i] = value;
        }
        //shifts elements to the right one space if current index > insertion index
        else if (i > index){
            dataTemp[i] = _data[i - 1];
        }
        //copying without changes
        else {
            dataTemp[i] = _data[i];
        }
    }
    //loop back through the temp array and copy it to the original
    for (unsigned int i = 0; i < _size; ++i){
        _data[i] = dataTemp[i];
    }
    //deallocate!
    delete[] dataTemp;
    dataTemp = nullptr;
}

//new function
void IntVector::erase(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index; i < _size - 1; ++i){
        _data[i] = _data[i + 1];
    }
    _size -= 1;
}

const int & IntVector::front() const{
    return _data[0];
}

//new function
int & IntVector::front(){
    return _data[0];
}

const int & IntVector::back() const{
    return _data[_size - 1];
}

//new function
int & IntVector::back(){
    return _data[_size - 1];
}


void IntVector::assign(unsigned n, int value){
    if(n > _capacity){
        if(n > _capacity * 2){
            expand(n - _capacity);
        } 
        else{
            expand();
        }
    }
    _size = n;

    for(unsigned int i = 0; i < n; ++i){
        _data[i] = value;
    }
}

void IntVector::push_back(int value){
    if(_size == _capacity){
        expand();
    }
    _data[_size] = value;
    _size++;
}

void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned n, int value){
    if(n > _capacity){
        //accounts for if the difference is still larger than the capacity, and expands by it
        if((n - _capacity) > _capacity){
            expand(n - _capacity);
        } 
        else{
            expand();
        }
    }

    if(_size >= n){
        _size = n;
    } 
    else{
        for(unsigned int i = 0; i < n; ++i){
            if(i >= _size){
                _data[i] = value;
            }
        }
        _size = n;
    }
}

//"reserves" a minimum capacity "n" for an array
void IntVector::reserve(unsigned n){
    if(n >= _capacity){
        _capacity = n;
    }
}

void IntVector::expand(){
    if(_capacity > 0){
        int *dataTemp = new int[_capacity * 2];
        for(unsigned int i = 0; i < _capacity; ++i){
            dataTemp[i] = _data[i];
        }

        _data = new int[_capacity * 2];
        for(unsigned int i = 0; i < _capacity; ++i){
            _data[i] = dataTemp[i];
        }

        //deallocation of memory
        delete[] dataTemp;
        dataTemp = nullptr;
        _capacity *= 2;
    } 
    else{ //special case
        _data = new int[1];
        _capacity = 1;
    }
}

//expands by the amount passed in, rather than doubling capacity
void IntVector::expand(unsigned amount){
    int *dataTemp = new int[_capacity + amount];
    for(unsigned int i = 0; i < _capacity; ++i){
        dataTemp[i] = _data[i];
    }
    _data = new int[_capacity + amount];
    for(unsigned int i = 0; i < _capacity; ++i){
        _data[i] = dataTemp[i];
    }
    //deallocation
    delete[] dataTemp;
    dataTemp = nullptr;
    _capacity += amount;
}



void IntVector::expand(unsigned amount){
   
}

