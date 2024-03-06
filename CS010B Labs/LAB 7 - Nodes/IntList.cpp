#include <iostream>
#include "IntList.h"

using namespace std;

//default constructor 
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

//deconstructor that utilizes clear()
IntList::~IntList(){
    clear();
}

//clear() will delete all nodes by looping as long as there are nodes in the list
//deletes every head node upon each iteration of the loop 
void IntList::clear(){
    while (head != nullptr) { 
        //creates temp node to ensure a reference to the next node before deleting the current one
        //if we don't do this, then we lose info on the next node making it impossible to keep going in the list
        IntNode *temp = head->next; 
        delete head; 

        //head points to the next node
        head = temp;  
    }
    tail = nullptr;
}

//push_front will add a new node to the front of the list
void IntList::push_front(int newNode){
    IntNode* temp = new IntNode(newNode); 
    
    //pointer of next node = current head in the list (because current head will be the second node after)
    temp->next = head; 
    
    //update the head to point to new node
    head = temp; 

    if (tail == nullptr){
        tail = temp;
    }
}

/* 
fixed this
void IntList::pop_front(){
    if (head != nullptr){ 
        IntNode* temp = head; //store next node into temp
        delete head; //delete current head
        head = temp; //assign head with stored node
    }

    if (head == nullptr){
        tail = nullptr;
    }
}
*/

//pop_front will remove the front node in the list as long as it isn't empty
void IntList::pop_front(){
    if (head != nullptr){ 
        IntNode* temp = head; //store head into temp
        head = head->next; //reassign head before deletion
        delete temp; //delete current head 
    }

    if (head == nullptr){
        tail = nullptr;
    }
}

//checks if list is empty and returns corresponding bool
bool IntList::empty() const{
    if (head == nullptr){
        return true;
    }
    else {
        return false;
    }
}

//returns value pointed to by head
const int & IntList::front() const{
    return head->value;
}

//returns value pointed to by tail
const int & IntList::back() const{
    return tail->value;
}

//overloaded operator to output the list
ostream & operator<<(ostream &out, const IntList &newList){
    IntNode* current = newList.head; //begin from the head of the new list
    
    while (current != nullptr){ //loop until the end of the list
        out << current->value; //output current value of the node
        current = current->next; //traverses the node by 1 until current == nullptr
        if (current != nullptr){ 
            out << " ";
        }
    }
    return out;
}


